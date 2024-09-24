--- sys/fileio.cc.orig	2024-07-18 14:04:43 UTC
+++ sys/fileio.cc
@@ -595,7 +595,7 @@ FileIO::StatModTimeHP(DateTimeHighPrecision *modTime)
 	int	nanosecs = 0;
 
 // nanosecond support for stat is a bit of a portability mess
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   #if defined(__GLIBC__) && defined(__GLIBC_PREREQ)
     #if defined(_BSD_SOURCE) || defined(_SVID_SOURCE) \
 	|| (__GLIBC_PREREQ(2, 12) \
@@ -862,6 +862,11 @@ void
 FileIO::GetExtendedAttribute( StrPtr *name, StrBuf *val, Error *e )
 {
 	val->Clear();
+}
+
+void
+FileIO::SetExtendedAttributes( StrDict *vals, Error *e )
+{
 }
 
 void
