--- j504/profile.ijs.orig	Sun Aug 10 17:53:22 2003
+++ j504/profile.ijs	Sun Aug 10 17:58:55 2003
@@ -60,8 +60,8 @@
 prf=. PROFILE {.~ PROFILE i: sep
 add=. prf,sep,'addons'
 sys=. prf,sep,'system'
-tmp=. prf,sep,'temp'
-usr=. prf,sep,'user'
+tmp=. (2!:5'HOME'),sep,'J/user'
+usr=. (2!:5'HOME'),sep,'J/user'
 cfg=. usr,sep,'config'
 ids=. ;: 'profile system addons temp user config'
 SYSTEMFOLDERS_j_=: ids ,. prf;sys;add;tmp;usr;cfg
