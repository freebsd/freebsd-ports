--- dependencies.sh.orig	2011-02-28 11:04:24.000000000 -0500
+++ dependencies.sh	2011-03-28 08:52:03.000000000 -0400
@@ -1,4 +1,4 @@
-#! /bin/bash
+#!/bin/sh
 #
 #  Check if dependencies are installed before build.
 #
@@ -7,15 +7,15 @@
 #  but they are required at run time to handle EXIF data 
 #  and RAW files from digital cameras.
 
-dlist=" g++  /usr/include/gtk-2.0/gtk/gtk.h  
-        /usr/include/tiffio.h  /usr/lib*/libtiff.so
-        xdg-open  xdg-desktop-menu  exiftool"
+dlist=" /usr/local/include/gtk-2.0/gtk/gtk.h
+        /usr/local/include/tiffio.h  /usr/local/lib/libtiff.so
+        /usr/local/bin/xdg-open  /usr/local/bin/xdg-desktop-menu  /usr/local/bin/exiftool"
 
 error=0
 
 for dname in $dlist
 do
-   if [ ${dname:0:1} = "/" ] 
+   if [ ${dname#/*} = ${dname} ] 
       then find $dname >/dev/null 2>&1
       else which $dname >/dev/null
    fi
@@ -40,7 +40,7 @@
 
 for dname in $dlist
 do
-   if [ ${dname:0:1} = "/" ] 
+   if [ ${dname#/*} = ${dname} ] 
       then find $dname >/dev/null 2>&1
       else which $dname >/dev/null
    fi
