--- ./lib/ASTK/tools.tcl.orig	Mon Dec  6 09:48:47 2004
+++ ./lib/ASTK/tools.tcl	Sun Jan 16 00:43:35 2005
@@ -51,12 +51,12 @@
    if { $sortie } {
 # vérifie que les commandes distantes fonctionnent
       init_config
-      if { $config(-1,remote_shell_protocol) == "" || $config(-1,remote_shell_protocol) == "RSH" } {
+      if { $astk::config(-1,remote_shell_protocol) == "" || $astk::config(-1,remote_shell_protocol) == "RSH" } {
          set cmd "rsh -n -l $astk::config(-1,login) $astk::config(-1,nom_complet) echo hello"
-      } elseif { $config(-1,remote_shell_protocol) == "SSH" } {
+      } elseif { $astk::config(-1,remote_shell_protocol) == "SSH" } {
          set cmd "ssh -n -l $astk::config(-1,login) $astk::config(-1,nom_complet) echo hello"
       } else {
-         ashare::mess erreur 49 $config(-1,remote_shell_protocol)
+         ashare::mess erreur 49 $astk::config(-1,remote_shell_protocol)
          # le premier appel à rexec_cmd échouera
          cmd="echo ERROR"
       }
