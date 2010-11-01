--- dot.xinitrc.orig	2007-10-23 18:39:29.000000000 +0800
+++ dot.xinitrc	2010-11-01 17:23:01.000000000 +0800
@@ -1,14 +1,18 @@
+# KDE4
+#export PATH=/usr/local/kde4/bin:$PATH
 
 export TERM=xterm
 
 export XMODIFIERS='@im=xcin'
 #export XMODIFIERS='@im=SCIM'
 #export XMODIFIERS='@im=oxim'
+#export XMODIFIERS=@im=ibus
 
 #export GTK_IM_MODULE=xcin
 export GTK_IM_MODULE=xim
 #export GTK_IM_MODULE=scim
 #export GTK_IM_MODULE=oxim
+#export GTK_IM_MODULE=ibus
 
 export QT_IM_MODULE=xim
 
@@ -19,6 +23,7 @@
 #exec xcin2.5 &
 #scim -d &
 #exec oxim &
+#ibus-daemon -d -x &
 
 # turn on numlock (x11/numlockx)
 numlockx
@@ -34,4 +39,4 @@
 #exec startkde
 #exec wmaker
 #exec startxfce4
-
+#exec startkde4
