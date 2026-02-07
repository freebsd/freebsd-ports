Obtained from:  https://sources.debian.org/data/main/g/gitinspector/0.4.4+dfsg-9/debian/patches/Drop-superfluous-argument-to-NullTranslations.install.patch
Reference:      https://github.com/ejwa/gitinspector/issues/213#issuecomment-722732702

--- gitinspector/localization.py.orig	2016-02-03 13:25:05 UTC
+++ gitinspector/localization.py
@@ -73,7 +73,7 @@ def init():
 
 		__enabled__ = True
 		__installed__ = True
-		__translation__.install(True)
+		__translation__.install()
 
 def check_compatibility(version):
 	if isinstance(__translation__, gettext.GNUTranslations):
@@ -98,7 +98,7 @@ def get_date():
 
 def enable():
 	if isinstance(__translation__, gettext.GNUTranslations):
-		__translation__.install(True)
+		__translation__.install()
 
 		global __enabled__
 		__enabled__ = True
@@ -108,4 +108,4 @@ def disable():
 	__enabled__ = False
 
 	if __installed__:
-		gettext.NullTranslations().install(True)
+		gettext.NullTranslations().install()
