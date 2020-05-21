--- share/templates/create_default_templates.py.orig	2020-05-21 19:30:52 UTC
+++ share/templates/create_default_templates.py
@@ -44,6 +44,8 @@ for language in languages:
         os.makedirs(destination_dir)
     shutil.copy(source, destination)
 
+# do another loop to ensure we've copied all the translations before using them
+for language in languages:
     # get translation with help of gettext
     translation = gettext.translation('inkscape', localedir=binary_dir + '/po/locale', languages=[language])
     translated_string = translation.gettext(LAYER_STRING)
