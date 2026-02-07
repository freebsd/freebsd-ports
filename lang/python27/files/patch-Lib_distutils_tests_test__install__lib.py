From 9934ce31b8447667f71c211e559a8de71e8263db Mon Sep 17 00:00:00 2001
From: Brendan Molloy <brendan@bbqsrc.net>
Date: Mon, 4 Jan 2016 23:14:06 +1100
Subject: [PATCH] Check bytecode file actually exists and tests

Should solve issue 20397, where using the --record argument results
in files that failed to generate bytecode files are added to the
record file nonetheless.
---
 Lib/distutils/command/install_lib.py    | 17 +++++++++++++----
 Lib/distutils/tests/test_install_lib.py |  8 ++++++--
 2 files changed, 19 insertions(+), 6 deletions(-)

--- Lib/distutils/tests/test_install_lib.py.orig	2015-12-05 19:46:57 UTC
+++ Lib/distutils/tests/test_install_lib.py
@@ -64,8 +64,12 @@ class InstallLibTestCase(support.Tempdir
         cmd.distribution.packages = [pkg_dir]
         cmd.distribution.script_name = 'setup.py'
 
-        # get_output should return 4 elements
-        self.assertGreaterEqual(len(cmd.get_outputs()), 2)
+        # Create rubbish, uncompilable file
+        f = os.path.join(pkg_dir, 'rubbish.py')
+        self.write_file(f, 'rubbish()')
+
+        # get_output should return 3 elements
+        self.assertEqual(len(cmd.get_outputs()), 3)
 
     def test_get_inputs(self):
         pkg_dir, dist = self.create_dist()
