http://www.openoffice.org/issues/show_bug.cgi?id=25579
We should set locale as UTF-8 when compiling
but this was due to violation of OOo coding style

--- ../solenv/inc/settings.mk.old	Tue Mar  9 21:19:28 2004
+++ ../solenv/inc/settings.mk	Mon Mar 29 13:23:31 2004
@@ -172,7 +172,7 @@
 JAVAI=gij
 JAVACPS=--classpath
 .ELSE
-JAVAC=javac
+JAVAC=javac -encoding UTF-8
 JAVAI=java
 JAVACPS=-classpath
 .ENDIF
