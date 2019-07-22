--- dw-start.sh.orig	2018-10-08 14:15:21 UTC
+++ dw-start.sh
@@ -120,14 +120,14 @@ function GUI {
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
@@ -142,9 +142,9 @@ function GUI {
 # -----------------------------------------------------------
 
 # When running from cron, we have a very minimal environment
-# including PATH=/usr/bin:/bin.
+# including PATH=%%PREFIX%%/bin:/bin.
 #
-export PATH=/usr/local/bin:$PATH
+export PATH=%%PREFIX%%/bin:$PATH
 
 #Log the start of the script run and re-run
 date >> $LOGFILE
