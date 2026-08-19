--- src/Base/CrashReporter/Format.h.orig	2026-08-19 16:27:55 UTC
+++ src/Base/CrashReporter/Format.h
@@ -78,6 +78,7 @@ namespace Base::CrashReporter
     return (flags & flag) != Flags::None;
 }
 
+#undef BSD
 // Only values the Writer can actually produce are meaningful here. BSD has a slot reserved
 // because appending is free while inserting later would be a format version bump, but the
 // Writer is not installed on BSD yet (see the guard on Writer::install).
