--- translations/translate_text_files.sh.orig	2018-12-23 20:55:50 UTC
+++ translations/translate_text_files.sh
@@ -21,8 +21,8 @@ set -e
 
 for FILE
 do
-	echo -n "$FILE" | sed -e 's/.*OpenOrienteering_/Comment[/;s/\.ts$/]=/'
-	cat ${FILE} | sed -n -e '
+	echo -n "$FILE" | gsed -e 's/.*OpenOrienteering_/Comment[/;s/\.ts$/]=/'
+	cat ${FILE} | gsed -n -e '
 	  /<source>A free software for drawing orienteering maps</! d
 	  n
 	  /<translation>/! n
@@ -31,22 +31,22 @@ do
 	  p
 	  q
 	'
-done | sed -e "
+done | gsed -e "
   s/^[^=]*\]=\(Comment\)/\1/
   /^[^=]*\]=$/ d
   s/&quot;/\"/
   s/&apos;/'/
 " > desktop_file_comment.txt
 
-sed -i "../packaging/linux/Mapper.desktop" -e '
+gsed -i "../packaging/linux/Mapper.desktop" -e '
   /^Comment=/ r desktop_file_comment.txt
   /^Comment\[/ d
 '
 
 for FILE
 do
-	echo -n "$FILE" | sed -e 's/.*OpenOrienteering_/     <comment xml:lang="/;s/\.ts$/">/'
-	cat ${FILE} | sed -n -e '
+	echo -n "$FILE" | gsed -e 's/.*OpenOrienteering_/     <comment xml:lang="/;s/\.ts$/">/'
+	cat ${FILE} | gsed -n -e '
 	  /<source>Orienteering map</! d
 	  n
 	  /<translation>/! n
@@ -55,7 +55,7 @@ do
 	  p
 	  q
 	'
-done | sed -e "
+done | gsed -e "
   s/^[^>]*>\( *<comment\)/\1/
   /\">$/ d
   s/$/<\/comment>/
@@ -63,7 +63,7 @@ done | sed -e "
   s/&apos;/'/
 " > mime_type_comment.txt
 
-sed -i "../packaging/linux/openorienteering-mapper.xml" -e '
+gsed -i "../packaging/linux/openorienteering-mapper.xml" -e '
   /^ *<comment>/ r mime_type_comment.txt
   /^ *<comment [^>]*lang=/ d
 '
