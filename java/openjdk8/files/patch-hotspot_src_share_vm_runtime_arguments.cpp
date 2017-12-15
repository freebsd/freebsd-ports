--- hotspot/src/share/vm/runtime/arguments.cpp.orig	2017-12-01 00:32:02.284351000 +0000
+++ hotspot/src/share/vm/runtime/arguments.cpp	2017-12-01 00:38:48.362549000 +0000
@@ -3974,7 +3974,8 @@ jint Arguments::parse(const JavaVMInitArgs* args) {
             hotspotrc, hotspotrc);
   }
 
-#ifdef _ALLBSD_SOURCE  // UseLargePages is not yet supported on BSD.
+#if defined(_ALLBSD_SOURCE) && !defined(__FreeBSD__)
+  // UseLargePages is not yet supported on BSD.
   UNSUPPORTED_OPTION(UseLargePages, "-XX:+UseLargePages");
 #endif
 
