--- dw-start.sh.orig	2017-01-20 00:11:50 UTC
+++ dw-start.sh
@@ -83,15 +83,15 @@ DWCMD="direwolf -a 100"
 #
 
 
-if [ -x /usr/bin/lxterminal ]
+if [ -x /usr/local/bin/lxterminal ]
 then
-  /usr/bin/lxterminal -t "Dire Wolf" -e "$DWCMD" &
-elif [ -x /usr/bin/xterm ] 
+  /usr/local/bin/lxterminal -t "Dire Wolf" -e "$DWCMD" &
+elif [ -x /usr/local/bin/xterm ] 
 then
-  /usr/bin/xterm -bg white -fg black -e "$DWCMD" &
-elif [ -x /usr/bin/x-terminal-emulator ]
+  /usr/local/bin/xterm -bg white -fg black -e "$DWCMD" &
+elif [ -x /usr/local/bin/x-terminal-emulator ]
 then
-  /usr/bin/x-terminal-emulator -e "$DWCMD" &
+  /usr/local/bin/x-terminal-emulator -e "$DWCMD" &
 else
   echo "Did not find an X terminal emulator."
 fi
