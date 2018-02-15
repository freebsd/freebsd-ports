The new moodbar generator from audio/moodbar expects the format:
moodbar -o OUTPUT INPUT

--- plugins/moodbars/__init__.py.orig	2018-02-14 18:46:53 UTC
+++ plugins/moodbars/__init__.py
@@ -52,8 +52,8 @@ def generate_moodbar_for_files(files, format, tagger):
             MOODBAR_COMMANDS[format][1]].split(' ')
 #        tagger.log.debug('My debug >>>  %s' % (file_list_mood))
         tagger.log.debug(
-            '%s %s %s %s' % (command, decode_filename(' '.join(file_list)), ' '.join(options), decode_filename(' '.join(file_list_mood))))
-        check_call([command] + file_list + options + file_list_mood)
+            '%s %s %s %s' % (command, ' '.join(options), decode_filename(' '.join(file_list_mood)), decode_filename(' '.join(file_list))))
+        check_call([command] + options + file_list_mood + file_list)
     else:
         raise Exception('Moodbar: Unsupported format %s' % (format))
 
