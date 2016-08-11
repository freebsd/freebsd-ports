--- libdi_d/config.sh.orig	2004-04-21 19:27:07 UTC
+++ libdi_d/config.sh
@@ -744,7 +744,7 @@ ask_nonscsi_config()
 
 	if [ -z "$IOCDEF" -o "$IOCDEF" = 0 ]
 	then
-		IOCDEF=1
+		IOCDEF=2
 	fi
 
 	while :
