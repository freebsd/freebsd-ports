--- dot.xinitrc.orig	2018-05-25 11:12:38.061402000 +0800
+++ dot.xinitrc	2018-05-25 11:15:12.366127000 +0800
@@ -1,22 +1,27 @@
 export TERM=xterm
 
-export XMODIFIERS='@im=xcin'
+#export XMODIFIERS='@im=xcin'
+export XMODIFIERS='@im=gcin'
 #export XMODIFIERS='@im=SCIM'
 #export XMODIFIERS='@im=oxim'
 #export XMODIFIERS=@im=ibus
+#export XMODIFIERS='@im=fcitx'
 
 #export GTK_IM_MODULE=xcin
-export GTK_IM_MODULE=xim
+export GTK_IM_MODULE=gcin
+#export GTK_IM_MODULE=xim
 #export GTK_IM_MODULE=scim
 #export GTK_IM_MODULE=oxim
 #export GTK_IM_MODULE=ibus
+#export GTK_IM_MODULE=fcitx
 
-export QT_IM_MODULE=xim
+export QT_IM_MODULE=gcin
+#export QT_IM_MODULE=xim
+#export QT_IM_MODULE=fcitx
 
-export GCIN_XIM=xcin
-
 # Input Method
 exec gcin &
+#exec fcitx &
 #exec xcin2.5 &
 #scim -d &
 #exec oxim &
@@ -37,3 +42,5 @@
 #exec wmaker
 #exec startxfce4
 #exec startkde4
+#exec startfluxbox
+#exec ck-launch-session startkde
