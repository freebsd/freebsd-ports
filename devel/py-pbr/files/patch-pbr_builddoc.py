From 12e36886fe343f8103a21c60d6925115ad8dbc26 Mon Sep 17 00:00:00 2001
From: Thomas Bechtold <tbechtold@suse.com>
Date: Tue, 2 Jun 2015 18:40:38 +0200
Subject: [PATCH] Remove sphinx_config.init_values() manual call

The function signature for Sphinx's config.init_values() changed since
version 1.3. That leads to:

TypeError: init_values() takes exactly 2 arguments (1 given)

But the function is already correctly called from
application.Sphinx()'s constructor. So use the configuration object
from the application instead of creating an own config object.

Commit 1dfe9ef348c777bef67b2c2b1d35e50ebc720333 already introduced this
change and commit e41a9180ed3103bb45fa1d1be93ba951016b029c reverted it
due to build failures with Sphinx 1.1.3 . The failure occurred because
using the application class to detect if man pages can build raised a
warning which was treated as error. This case is now handled and tested
with Sphinx 1.1.3 and 1.3.1.

Change-Id: Idf6c7b329880c6698b61ee9e88f29c0f6e0956bf
Closes-Bug: #1379998

--- pbr/builddoc.py.orig	2015-08-24 21:30:59 UTC
+++ pbr/builddoc.py
@@ -27,7 +27,6 @@ except ImportError:
 try:
     from sphinx import apidoc
     from sphinx import application
-    from sphinx import config
     from sphinx import setup_command
 except Exception as e:
     # NOTE(dhellmann): During the installation of docutils, setuptools
@@ -129,10 +128,21 @@ class LocalBuildDoc(setup_command.BuildD
             confoverrides['release'] = self.release
         if self.today:
             confoverrides['today'] = self.today
-        sphinx_config = config.Config(self.config_dir, 'conf.py', {}, [])
-        sphinx_config.init_values()
-        if self.builder == 'man' and len(sphinx_config.man_pages) == 0:
+
+        # NOTE(toabctl): creating the app with "warningiserror=False" is
+        # used to detect if man_pages are available.Only needed for sphinx<1.3
+        # See also https://github.com/sphinx-doc/sphinx/issues/1933
+        app = application.Sphinx(
+            self.source_dir, self.config_dir,
+            self.builder_target_dir, self.doctree_dir,
+            self.builder, confoverrides, status_stream,
+            freshenv=self.fresh_env, warningiserror=False)
+
+        if self.builder == 'man' and len(app.config.man_pages) == 0:
             return
+
+        # NOTE(toabctl): Now create the app with "warningiserror=True for real
+        # usage
         app = application.Sphinx(
             self.source_dir, self.config_dir,
             self.builder_target_dir, self.doctree_dir,
