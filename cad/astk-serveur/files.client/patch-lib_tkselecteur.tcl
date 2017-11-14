--- lib/tkselecteur.tcl.orig	2017-07-13 07:40:52 UTC
+++ lib/tkselecteur.tcl
@@ -1944,10 +1944,10 @@ proc tkgetdir::ExecCmde { parent } {
    set ExecCmde_shell $ini
     radiobutton $fen.sh.sh   -font $astk::ihm(font,lab) -text /bin/sh   -value /bin/sh   -variable ExecCmde_shell
     radiobutton $fen.sh.csh  -font $astk::ihm(font,lab) -text /bin/csh  -value /bin/csh  -variable ExecCmde_shell
-    radiobutton $fen.sh.ksh  -font $astk::ihm(font,lab) -text /bin/ksh  -value /bin/ksh  -variable ExecCmde_shell
-    radiobutton $fen.sh.bash -font $astk::ihm(font,lab) -text /bin/bash -value /bin/bash -variable ExecCmde_shell
+    radiobutton $fen.sh.ksh  -font $astk::ihm(font,lab) -text %%LOCALBASE%%/bin/ksh  -value %%LOCALBASE%%/bin/ksh  -variable ExecCmde_shell
+    radiobutton $fen.sh.bash -font $astk::ihm(font,lab) -text %%LOCALBASE%%/bin/bash -value %%LOCALBASE%%/bin/bash -variable ExecCmde_shell
     radiobutton $fen.sh.tcsh -font $astk::ihm(font,lab) -text /bin/tcsh -value /bin/tcsh -variable ExecCmde_shell
-    radiobutton $fen.sh.zsh  -font $astk::ihm(font,lab) -text /bin/zsh  -value /bin/zsh  -variable ExecCmde_shell
+    radiobutton $fen.sh.zsh  -font $astk::ihm(font,lab) -text %%LOCALBASE%%/bin/zsh  -value %%LOCALBASE%%/bin/zsh  -variable ExecCmde_shell
 
    pack $fen.txt -fill x -expand 1
    pack $fen.txt.lbl -padx 10 -pady 5 -side left -anchor w
