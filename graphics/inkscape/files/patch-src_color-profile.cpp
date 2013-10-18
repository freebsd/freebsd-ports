--- src/color-profile.cpp.orig	2013-10-17 12:28:59.000000000 +0200
+++ src/color-profile.cpp	2013-10-17 12:34:25.000000000 +0200
@@ -103,6 +103,8 @@
 
 static SPObjectClass *cprof_parent_class;
 
+namespace Inkscape {
+
 class ColorProfileImpl {
 public:
 #if defined(HAVE_LIBLCMS1) || defined(HAVE_LIBLCMS2)
@@ -129,10 +131,6 @@
 #endif // defined(HAVE_LIBLCMS1) || defined(HAVE_LIBLCMS2)
 };
 
-
-
-namespace Inkscape {
-
 #if defined(HAVE_LIBLCMS1) || defined(HAVE_LIBLCMS2)
 cmsColorSpaceSignature asICColorSpaceSig(ColorSpaceSig const & sig)
 {
