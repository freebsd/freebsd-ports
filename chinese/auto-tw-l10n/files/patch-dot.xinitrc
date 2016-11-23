--- dot.xinitrc.orig	2016-04-30 18:04:47 UTC
+++ dot.xinitrc
@@ -4,19 +4,23 @@ export XMODIFIERS='@im=xcin'
 #export XMODIFIERS='@im=SCIM'
 #export XMODIFIERS='@im=oxim'
 #export XMODIFIERS=@im=ibus
+#export XMODIFIERS='@im=fcitx'
 
 #export GTK_IM_MODULE=xcin
 export GTK_IM_MODULE=xim
 #export GTK_IM_MODULE=scim
 #export GTK_IM_MODULE=oxim
 #export GTK_IM_MODULE=ibus
+#export GTK_IM_MODULE=fcitx
 
 export QT_IM_MODULE=xim
+#export QT_IM_MODULE=fcitx
 
 export GCIN_XIM=xcin
 
 # Input Method
 exec gcin &
+#exec fcitx &
 #exec xcin2.5 &
 #scim -d &
 #exec oxim &
