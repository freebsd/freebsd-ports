--- j501b/profile.ijs.orig	Sun Dec  8 18:47:18 2002
+++ j501b/profile.ijs	Sun Dec  8 18:50:14 2002
@@ -52,8 +52,8 @@
 18!:4 <'j'
 SYSTEM=: PROFILE {.~ PROFILE i: PATHSEP
 ADDONS=: SYSTEM,PATHSEP,'addons'
-TEMP=: SYSTEM,PATHSEP,'temp'
-USER=: SYSTEM,PATHSEP,'user'
+USER=: (2!:5'HOME'),'\J\user'
+TEMP=: USER
 CONFIG=: USER,PATHSEP,'config'
 18!:4 <'base'
 
