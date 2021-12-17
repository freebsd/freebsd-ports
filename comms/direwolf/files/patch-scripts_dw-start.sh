--- scripts/dw-start.sh.orig	2021-12-17 15:56:10 UTC
+++ scripts/dw-start.sh
@@ -1,4 +1,4 @@
-#!/usr/bin/bash
+#!%%PREFIX%%/bin/bash
 
 # Why not simply "#!/bin/bash" ?
 
@@ -133,14 +133,14 @@ function GUI {
    # Auto adjust the startup for your particular environment:  gnome-terminal, xterm, etc.
    #
 
-   if [ -x /usr/bin/lxterminal ]; then
-      /usr/bin/lxterminal -t "Dire Wolf" -e "$DWCMD" &
+   if [ -x %%PREFIX%%/bin/lxterminal ]; then
+      %%PREFIX%%/bin/lxterminal -t "Dire Wolf" -e "$DWCMD" &
       SUCCESS=1
-     elif [ -x /usr/bin/xterm ]; then
-      /usr/bin/xterm -bg white -fg black -e "$DWCMD" &
+     elif [ -x %%PREFIX%%/bin/xterm ]; then
+      %%PREFIX%%/bin/xterm -bg white -fg black -e "$DWCMD" &
       SUCCESS=1
-     elif [ -x /usr/bin/x-terminal-emulator ]; then
-      /usr/bin/x-terminal-emulator -e "$DWCMD" &
+     elif [ -x %%PREFIX%%/bin/x-terminal-emulator ]; then
+      %%PREFIX%%/bin/x-terminal-emulator -e "$DWCMD" &
       SUCCESS=1
      else
       echo "Did not find an X terminal emulator.  Reverting to CLI mode"
