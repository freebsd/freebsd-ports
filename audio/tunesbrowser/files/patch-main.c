--- main.c.orig	Mon Jan  3 21:58:29 2005
+++ main.c	Wed Feb  2 21:56:11 2005
@@ -38,8 +38,8 @@
 {
     fprintf(stderr, "Oops! TunesBrowser has crashed. Sorry about that!\n");
     fprintf(stderr, "This probably won't be of any use unless you feel like debugging,\n");
-    fprintf(stderr, "but the crash occured because of %p being bad.\n", siginfo->si_ptr);
 #if 0
+    fprintf(stderr, "but the crash occured because of %p being bad.\n", siginfo->si_ptr);
     fprintf(stderr, "\n\nRaised SIGSTOP. You can now attach a debugger.\n");
     fprintf(stderr, "Attach to PID %i\n", getpid());
     raise(SIGSTOP);
@@ -66,11 +66,11 @@
     int ret;
 
     sa.sa_handler = (void*)sighandler_sigsegv;
-    sa.sa_flags = SA_NOMASK | SA_SIGINFO;
+    sa.sa_flags = SA_NODEFER | SA_SIGINFO;
     ret = sigaction(SIGSEGV, &sa, NULL);
 
     sa.sa_handler = (void*)sighandler_sigpipe;
-    sa.sa_flags = SA_NOMASK | SA_SIGINFO;
+    sa.sa_flags = SA_NODEFER | SA_SIGINFO;
     ret = sigaction(SIGPIPE, &sa, NULL);
 }
 
@@ -94,7 +94,7 @@
 
     gtk_init(&argc, &argv);
 
-    xml = glade_xml_new(XSTR(UIDIR) "/tunesbrowser.glade", NULL, NULL);
+    xml = glade_xml_new(XSTR(UIDIR) "/tunesbrowser/tunesbrowser.glade", NULL, NULL);
 
     glade_xml_signal_autoconnect(xml);
 
