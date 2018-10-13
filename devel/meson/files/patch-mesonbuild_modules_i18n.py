https://github.com/mesonbuild/meson/issues/4304

From 2ff69b20df0864182fdf2b146d29dc67d0cb9a5b Mon Sep 17 00:00:00 2001
From: Jussi Pakkanen <jpakkane@gmail.com>
Date: Mon, 1 Oct 2018 20:31:48 +0300
Subject: [PATCH] Fix handling generated .desktop files. Closes #4304.

--- mesonbuild/modules/i18n.py.orig	2018-09-22 13:22:03 UTC
+++ mesonbuild/modules/i18n.py
@@ -82,17 +82,19 @@ class I18nModule(ExtensionModule):
         kwargs['command'] = command
 
         inputfile = kwargs['input']
-        if isinstance(inputfile, str):
-            inputfile = mesonlib.File.from_source_file(state.environment.source_dir,
+        if hasattr(inputfile, 'held_object'):
+            ct = build.CustomTarget(kwargs['output'] + '_merge', state.subdir, state.subproject, kwargs)
+        else:
+            if isinstance(inputfile, str):
+                inputfile = mesonlib.File.from_source_file(state.environment.source_dir,
                                                        state.subdir, inputfile)
-        output = kwargs['output']
-        ifile_abs = inputfile.absolute_path(state.environment.source_dir,
-                                            state.environment.build_dir)
-        values = mesonlib.get_filenames_templates_dict([ifile_abs], None)
-        outputs = mesonlib.substitute_values([output], values)
-        output = outputs[0]
-
-        ct = build.CustomTarget(output + '_' + state.subdir + '_merge', state.subdir, state.subproject, kwargs)
+            output = kwargs['output']
+            ifile_abs = inputfile.absolute_path(state.environment.source_dir,
+                                                state.environment.build_dir)
+            values = mesonlib.get_filenames_templates_dict([ifile_abs], None)
+            outputs = mesonlib.substitute_values([output], values)
+            output = outputs[0]
+            ct = build.CustomTarget(output + '_' + state.subdir + '_merge', state.subdir, state.subproject, kwargs)
         return ModuleReturnValue(ct, [ct])
 
     @FeatureNewKwargs('i18n.gettext', '0.37.0', ['preset'])
