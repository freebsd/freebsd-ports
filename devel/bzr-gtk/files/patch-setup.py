--- setup.py.orig	2010-08-13 22:38:52.000000000 +0200
+++ setup.py	2010-08-20 06:35:35.736688497 +0200
@@ -57,7 +57,6 @@
         branch = Branch.open(self.url)
         credits = find_credits(branch.repository, branch.last_revision())
 
-        pickle.dump(credits, file("credits.pickle", 'w'))
         return True
 
 
@@ -128,8 +127,7 @@
             "bzrlib.plugins.gtk.branchview",
             "bzrlib.plugins.gtk.preferences",
         ],
-        data_files=[ ('share/bzr-gtk', ['credits.pickle']),
-                    ('share/bzr-gtk/icons', ['icons/commit.png',
+        data_files=[ ('share/bzr-gtk/icons', ['icons/commit.png',
                                              'icons/commit16.png',
                                              'icons/diff.png',
                                              'icons/diff16.png',
