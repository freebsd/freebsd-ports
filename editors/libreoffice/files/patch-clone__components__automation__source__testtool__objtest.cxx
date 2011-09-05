--- clone/components/automation/source/testtool/objtest.cxx.orig	2011-05-20 18:05:11.000000000 +0200
+++ clone/components/automation/source/testtool/objtest.cxx	2011-08-25 22:36:33.395644903 +0200
@@ -433,8 +433,10 @@
     abGP.Append( "04" );
 #elif defined SOLARIS && defined INTEL
     abGP.Append( "05" );  // Solaris x86
-#elif defined FREEBSD
+#elif defined FREEBSD && defined INTEL
     abGP.Append( "08" );
+#elif defined FREEBSD && defined X86_64
+    abGP.Append( "09" );
 #elif defined MACOSX
     abGP.Append( "12" );
 #elif defined LINUX && defined PPC
