diff -ruN fam/Listener.c++ fam/Listener.c++
--- fam/Listener.c++	Wed May 29 00:19:26 2002
+++ fam/Listener.c++	Sat Jun  8 16:31:07 2002
@@ -207,7 +207,11 @@
     unsetenv("TMPDIR");
 
     char *tmpfile = tempnam("/tmp", ".fam");
+#if defined(__FreeBSD__)
+    sockaddr_un sun = { sizeof(sockaddr_un), AF_UNIX, "" };
+#else
     sockaddr_un sun = { AF_UNIX, "" };
+#endif
     if(strlen(tmpfile) >= (sizeof(sun.sun_path) - 1))
     {
         Log::error("tmpnam() too long for sun_path (%d >= %d)!",
@@ -277,7 +281,11 @@
 
     // Get the new socket.
 
+#if defined(__FreeBSD__)
+    struct sockaddr_un sun = { sizeof(sockaddr_un), AF_UNIX, "" };
+#else
     struct sockaddr_un sun = { AF_UNIX, "" };
+#endif
     CONFIG_SOCKLEN_T sunlen = sizeof(sun);
     int client_fd = accept(ofd, (struct sockaddr *) &sun, &sunlen);
     if (client_fd < 0)
@@ -339,7 +347,11 @@
 void
 Listener::dirty_ugly_hack()
 {
+#if defined(__FreeBSD__)
+    static sockaddr_un sun = { sizeof (sockaddr_un), AF_UNIX, "/tmp/.fam_socket" };
+#else
     static sockaddr_un sun = { AF_UNIX, "/tmp/.fam_socket" };
+#endif
 
     int sock = socket(PF_UNIX, SOCK_STREAM, 0);
     if (sock < 0)
