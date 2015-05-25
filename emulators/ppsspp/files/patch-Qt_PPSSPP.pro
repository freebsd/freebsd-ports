--- Qt/PPSSPP.pro.orig	2015-02-26 20:05:06 UTC
+++ Qt/PPSSPP.pro
@@ -91,7 +91,7 @@ mobile_platform {
 	INCLUDEPATH += $$P/Qt $$P/Qt/Debugger
 	
 	# Creating translations should be done by Qt, really
-	LREL_TOOL = lrelease
+	isEmpty(LREL_TOOL): LREL_TOOL = lrelease
 	# Grab all possible directories (win32/unix)
 	win32: PATHS = $$split($$(PATH), ;)
 	else: PATHS = $$split($$(PATH), :)
