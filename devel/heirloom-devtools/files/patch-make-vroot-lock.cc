--- make/vroot/lock.cc.orig	2023-01-13 17:29:24 UTC
+++ make/vroot/lock.cc
@@ -53,7 +53,7 @@ extern	char		*sys_errlist[];
 extern	int		sys_nerr;
 #endif
 
-static	void		file_lock_error(char *msg, char *file, char *str, int arg1, int arg2);
+static	void		file_lock_error(char *msg, char *file, char *str, char *arg1, char *arg2);
 
 #define BLOCK_INTERUPTS sigfillset(&newset) ; \
 	sigprocmask(SIG_SETMASK, &newset, &oldset)
@@ -123,7 +123,7 @@ file_lock(char *name, char *lockname, int *file_locked
 
 		if (errno != EEXIST) {
 			file_lock_error(msg, name, NOCATGETS("symlink(%s, %s)"),
-			    (int) name, (int) lockname);
+			    name, lockname);
 			fprintf(stderr, "%s", msg);
 			return errno;
 		}
@@ -171,7 +171,7 @@ file_lock(char *name, char *lockname, int *file_locked
  * Format a message telling why the lock could not be created.
  */
 static	void
-file_lock_error(char *msg, char *file, char *str, int arg1, int arg2)
+file_lock_error(char *msg, char *file, char *str, char *arg1, char *arg2)
 {
 	int		len;
 
