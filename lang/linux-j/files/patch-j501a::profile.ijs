--- j501a/profile.ijs.orig	Tue Oct 22 18:08:47 2002
+++ j501a/profile.ijs	Tue Oct 22 18:10:13 2002
@@ -47,9 +47,9 @@
 NB. =========================================================
 NB. directory paths (no trailing path separator):
 SYSTEM_j_=: PROFILE{.~PROFILE i: PATHSEP_j_
-USER_j_=: SYSTEM_j_
+USER_j_=: (2!:5'HOME'),'\J'
 ADDON_j_=: SYSTEM_j_,'\addons'
-TEMP_j_=: SYSTEM_j_
+TEMP_j_=: USER_j_
 CONFIG_j_=: USER_j_, '\user\config'
 
 NB. =========================================================
