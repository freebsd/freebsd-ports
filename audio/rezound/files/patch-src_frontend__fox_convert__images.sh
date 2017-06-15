--- src/frontend_fox/convert_images.sh.orig	2012-04-14 05:41:31 UTC
+++ src/frontend_fox/convert_images.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 # probably should go with something more generic like /bin/sh
 
 # to change to something other than gif, replace .gif and FXGIFIcon throughout the script
@@ -58,7 +58,7 @@ echo >> $H_FILE
 
 
 # this function encodes filenames with spaces or other non-printable characters into something that will be a valid C-variable name
-function filenameToVarname # $1 is a [path/]filename.ext
+filenameToVarname() # $1 is a [path/]filename.ext
 {
 	# remove path and extension and translate chars
 	basename "${1%\.*}" | tr ' [],-' '_____'
@@ -81,7 +81,7 @@ echo "#endif" >> $H_FILE
 
 
 # only overwrite the h file if it needs to be so it won't cause a whole bunch of things to unnecessarily recompile
-if [ -a ${H_FILE%\.tmp} ]
+if [ -e ${H_FILE%\.tmp} ]
 then
 	diff $H_FILE ${H_FILE%\.tmp} >/dev/null
 	if [ $? -ne 0 ]
