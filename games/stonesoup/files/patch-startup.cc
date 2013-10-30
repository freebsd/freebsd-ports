--- ./startup.cc.orig	2013-09-30 20:32:00.000000000 +0200
+++ ./startup.cc	2013-10-11 22:07:08.183889437 +0200
@@ -240,8 +240,10 @@
     you.wizard = true;
 #endif
     // Save-less games are pointless except for tests.
+#ifdef WIZARD
     if (Options.no_save)
         you.wizard = true;
+#endif
 
     init_properties();
     burden_change();
