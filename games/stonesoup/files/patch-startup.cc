--- ./startup.cc.orig	2012-09-30 23:25:33.000000000 +0200
+++ ./startup.cc	2012-10-27 20:49:08.848667287 +0200
@@ -234,8 +234,10 @@
     you.wizard = true;
 #endif
     // Save-less games are pointless except for tests.
+#ifdef WIZARD
     if (Options.no_save)
         you.wizard = true;
+#endif
 
     init_properties();
     burden_change();
