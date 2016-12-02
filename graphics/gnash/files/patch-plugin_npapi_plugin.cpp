$NetBSD: patch-plugin_npapi_plugin.cpp,v 1.1 2013/02/26 11:04:26 joerg Exp $

--- plugin/npapi/plugin.cpp.orig	2012-01-19 19:17:50.000000000 +0000
+++ plugin/npapi/plugin.cpp
@@ -50,17 +50,17 @@
 // The name must be this value to get flash movies that check the
 // plugin version to load.
 #define PLUGIN_NAME    "Shockwave Flash"
-#define MIME_TYPES_DESCRIPTION  MIME_TYPES_HANDLED":swf:"PLUGIN_NAME
+#define MIME_TYPES_DESCRIPTION  MIME_TYPES_HANDLED ":swf:" PLUGIN_NAME
 
 // Some javascript plugin detectors use the description
 // to decide the flash version to display. They expect the
 // form (major version).(minor version) r(revision).
 // e.g. "8.0 r99."
-#define FLASH_VERSION DEFAULT_FLASH_MAJOR_VERSION"."\
-    DEFAULT_FLASH_MINOR_VERSION" r"DEFAULT_FLASH_REV_NUMBER"."
+#define FLASH_VERSION DEFAULT_FLASH_MAJOR_VERSION "."\
+    DEFAULT_FLASH_MINOR_VERSION" r" DEFAULT_FLASH_REV_NUMBER "."
 
 #define PLUGIN_DESCRIPTION \
-  "Shockwave Flash "FLASH_VERSION"<br>Gnash "VERSION", the GNU SWF Player. \
+  "Shockwave Flash " FLASH_VERSION "<br>Gnash " VERSION ", the GNU SWF Player. \
   Copyright (C) 2006, 2007, 2008, 2009, 2010, 2011 \
   <a href=\"http://www.fsf.org\">Free \
   Software Foundation</a>, Inc. <br> \
@@ -71,7 +71,7 @@
   href=\"http://www.gnu.org/software/gnash/\"> \
   http://www.gnu.org/software/gnash</a>. \
   <br>\
-  Compatible Shockwave Flash "FLASH_VERSION
+  Compatible Shockwave Flash " FLASH_VERSION
 
 #include "plugin.h" 
 #include "GnashSystemIOHeaders.h"
