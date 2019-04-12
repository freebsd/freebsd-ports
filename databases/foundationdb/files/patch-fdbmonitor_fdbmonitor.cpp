--- fdbmonitor/fdbmonitor.cpp.orig	2019-04-09 00:11:05 UTC
+++ fdbmonitor/fdbmonitor.cpp
@@ -37,6 +37,10 @@
 #include <linux/limits.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/event.h>
+#endif
+
 #ifdef __APPLE__
 #include <sys/event.h>
 #include <mach/mach.h>
@@ -77,7 +81,7 @@
 
 #ifdef __linux__
 typedef fd_set* fdb_fd_set;
-#elif defined __APPLE__
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 typedef int fdb_fd_set;
 #endif
 
@@ -88,7 +92,7 @@ void monitor_fd( fdb_fd_set list, int fd, int* maxfd, 
 	FD_SET( fd, list );
 	if ( fd > *maxfd )
 		*maxfd = fd;
-#elif defined __APPLE__
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 	/* ignore maxfd */
 	struct kevent ev;
 	EV_SET( &ev, fd, EVFILT_READ, EV_ADD, 0, 0, cmd );
@@ -99,7 +103,7 @@ void monitor_fd( fdb_fd_set list, int fd, int* maxfd, 
 void unmonitor_fd( fdb_fd_set list, int fd ) {
 #ifdef __linux__
 	FD_CLR( fd, list );
-#elif defined __APPLE__
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 	struct kevent ev;
 	EV_SET( &ev, fd, EVFILT_READ, EV_DELETE, 0, 0, NULL );
 	kevent( list, &ev, 1, NULL, 0, NULL ); // FIXME: check?
@@ -193,7 +197,7 @@ const char* get_value_multi(const CSimpleIni& ini, con
 }
 
 double timer() {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	struct timespec ts;
 	clock_gettime(CLOCK_MONOTONIC, &ts);
 	return double(ts.tv_sec) + (ts.tv_nsec * 1e-9);
@@ -912,7 +916,7 @@ void read_child_output( Command* cmd, int pipe_idx, fd
 	}
 }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 void watch_conf_dir( int kq, int* confd_fd, std::string confdir ) {
 	struct kevent ev;
 	std::string original = confdir;
@@ -929,7 +933,7 @@ void watch_conf_dir( int kq, int* confd_fd, std::strin
 		std::string child = confdir;
 
 		/* Find the nearest existing ancestor */
-		while( (*confd_fd = open( confdir.c_str(), O_EVTONLY )) < 0 && errno == ENOENT ) {
+		while( (*confd_fd = open( confdir.c_str(), O_RDONLY )) < 0 && errno == ENOENT ) {
 			child = confdir;
 			confdir = parentDirectory(confdir, false);
 		}
@@ -966,7 +970,7 @@ void watch_conf_file( int kq, int* conff_fd, const cha
 	}
 
 	/* Open and watch */
-	*conff_fd = open( confpath, O_EVTONLY );
+	*conff_fd = open( confpath, O_RDONLY );
 	if ( *conff_fd >= 0 ) {
 		EV_SET( &ev, *conff_fd, EVFILT_VNODE, EV_ADD | EV_CLEAR, NOTE_WRITE | NOTE_ATTRIB, 0, NULL );
 		kevent( kq, &ev, 1, NULL, 0, NULL );
@@ -1170,7 +1174,7 @@ int main(int argc, char** argv) {
 	// testPathOps(); return -1;
 
 	std::string lockfile = "/var/run/fdbmonitor.pid";
-	std::string _confpath = "/etc/foundationdb/foundationdb.conf";
+	std::string _confpath = std::string(PREFIX) + "/etc/foundationdb/foundationdb.conf";
 
 	std::vector<const char *> additional_watch_paths;
 
@@ -1252,7 +1256,7 @@ int main(int argc, char** argv) {
 	/* only linux needs this, but... */
 	int maxfd = 0;
 
-#ifdef __linux__
+#if defined(__linux__)
 	fd_set rfds;
 	watched_fds = &rfds;
 
@@ -1267,12 +1271,12 @@ int main(int argc, char** argv) {
 	CSimpleIniA* ini = NULL;
 
 	if (daemonize) {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 #endif
 		if (daemon(0, 0)) {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #pragma GCC diagnostic pop
 #endif
 			log_err("daemon", errno, "Unable to daemonize");
@@ -1325,12 +1329,12 @@ int main(int argc, char** argv) {
 	snprintf(pid_buf, sizeof(pid_buf), "%d\n", getpid());
 	ssize_t ign = write(lockfile_fd, pid_buf, strlen(pid_buf));
 
-#ifdef __linux__
+#if defined(__linux__)
 	/* attempt to do clean shutdown and remove lockfile when killed */
 	signal(SIGHUP, signal_handler);
 	signal(SIGINT, signal_handler);
 	signal(SIGTERM, signal_handler);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 	int kq = kqueue();
 	if ( kq < 0 ) {
 		log_err( "kqueue", errno, "Unable to create kqueue" );
@@ -1361,7 +1365,7 @@ int main(int argc, char** argv) {
 
 #endif
 
-#ifdef __linux__
+#if defined(__linux__)
 	signal(SIGCHLD, child_handler);
 #endif
 
@@ -1375,11 +1379,11 @@ int main(int argc, char** argv) {
 	/* normal will be restored in our main loop in the call to
 	   pselect, but none blocks all signals while processing events */
 	sigprocmask(SIG_SETMASK, &full_mask, &normal_mask);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 	sigprocmask(0, NULL, &normal_mask);
 #endif
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 	struct stat st_buf;
 	struct timespec mtimespec;
 
@@ -1438,7 +1442,7 @@ int main(int argc, char** argv) {
 
 			load_conf(confpath.c_str(), uid, gid, &normal_mask, &rfds, &maxfd);
 			reload_additional_watches = false;
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 			load_conf( confpath.c_str(), uid, gid, &normal_mask, watched_fds, &maxfd );
 			watch_conf_file( kq, &conff_fd, confpath.c_str() );
 			watch_conf_dir( kq, &confd_fd, confdir );
@@ -1476,7 +1480,7 @@ int main(int argc, char** argv) {
 		if(nfds == 0) {
 			reload = true;
 		}
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 		int nev = 0;
 		if(timeout < 0) {
 			nev = kevent( kq, NULL, 0, &ev, 1, NULL );
