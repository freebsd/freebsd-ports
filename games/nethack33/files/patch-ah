--- win/gnome/gnmain.c.orig	Sat Aug  5 19:53:33 2000
+++ win/gnome/gnmain.c	Sat May 18 03:12:16 2002
@@ -672,6 +672,7 @@
     euid = geteuid();
     if (uid != euid)
       setuid(uid);
+    setregid(getegid(), -1);
     gnome_init ("nethack", VERSION_STRING, argc, argv);
     parse_args (argc, argv);
 
