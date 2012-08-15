--- DateTimeFormat.cmake.orig	2012-08-13 12:04:36.000000000 +0800
+++ DateTimeFormat.cmake	2012-08-13 12:04:42.000000000 +0800
@@ -28,7 +28,7 @@
 	IF(_locale)
 	    SET(ENV{LC_ALL} ${_locale})
 	ENDIF(_locale)
-	COMMAND_OUTPUT_TO_VARIABLE(${date_var} date --utc "${format}")
+	COMMAND_OUTPUT_TO_VARIABLE(${date_var} date -u "${format}")
     ENDMACRO(TODAY date_var format)
 
     TODAY(TODAY_CHANGELOG "+%a %b %d %Y" "C")
