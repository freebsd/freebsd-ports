--- src/drvlatex2e.cpp.pre_tr	Sat Jun 18 22:35:42 2005
+++ src/drvlatex2e.cpp	Tue Aug 23 00:30:01 2005
@@ -284,27 +284,6 @@
 	const char * cp = textinfo.thetext.value();
 	//buffer << textinfo.thetext.value() 
 
-#if 0
-// characters to be handled specially	
-% -> \%
-# -> \#
-{ -> \{
-} -> \}
-_ -> \_
-& -> \&
-$ -> \$  
-	Tritt auch manchmal mit veränderter Bedeutung als $$ auf: --> \$\$
-
-\ -> \textbackslash
-^ -> \textasciicircum
-~ -> \textasciitilde
-
-Zusätzlich machen folgende Zeichen oft Probleme:
-
-" -> \textquotedblright
-?`-> \textquestiondown
-!`-> \textexclamdown
-#endif
 	while (cp && *cp) {
 		if ((*cp == '%') ||
 			(*cp == '#') ||
