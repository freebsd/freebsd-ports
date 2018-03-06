--- setup.py.orig	2017-05-25 15:38:59 UTC
+++ setup.py
@@ -38,7 +38,7 @@ setup(name='bugwarrior',
           "dogpile.cache>=0.5.3",
           "lockfile>=0.9.1",
           "click",
-          "future!=0.16.0",
+          "future",
       ],
       extras_require=dict(
           keyring=["keyring", "dbus-python"],
@@ -50,9 +50,11 @@ setup(name='bugwarrior',
           bugzilla=["python-bugzilla"],
       ),
       tests_require=[
-          "Mock",
+          "mock",
           "nose",
           "responses",
+          "pypandoc",
+          "pyac",
           "bugwarrior[jira]",
           "bugwarrior[megaplan]",
           "bugwarrior[activecollab]",
