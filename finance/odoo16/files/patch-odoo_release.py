--- odoo/release.py.orig	2024-02-22 22:03:20 UTC
+++ odoo/release.py
@@ -12,7 +12,7 @@ RELEASE_LEVELS_DISPLAY = {ALPHA: ALPHA,
 # properly comparable using normal operators, for example:
 #  (6,1,0,'beta',0) < (6,1,0,'candidate',1) < (6,1,0,'candidate',2)
 #  (6,1,0,'candidate',2) < (6,1,0,'final',0) < (6,1,2,'final',0)
-version_info = ('saas~16', 4, 0, FINAL, 0, '')
+version_info = ('16', 4, 0, FINAL, 0, '')
 version = '.'.join(str(s) for s in version_info[:2]) + RELEASE_LEVELS_DISPLAY[version_info[3]] + str(version_info[4] or '') + version_info[5]
 series = serie = major_version = '.'.join(str(s) for s in version_info[:2])
 
