Reference:	https://github.com/nant/nant/issues/91
Obtained from:	https://github.com/nant/nant/commit/69c8ee96493c5d953212397c8ca06c2392372ca4
		https://github.com/nant/nant/commit/4ad065d009b043996d4ce2d25ce5031d81c6ce60

--- src/NAnt.Core/Resources/ProjectHelp.xslt.orig	2012-06-09 14:05:53 UTC
+++ src/NAnt.Core/Resources/ProjectHelp.xslt
@@ -26,7 +26,7 @@
     <xslt:output method="text" />
     <msxsl:script language="C#" implements-prefix="stringutils">
     <![CDATA[
-        string PadRight( string str, int padding) {
+        public string PadRight( string str, int padding) {
             return str.PadRight(padding);
         }
     ]]>
