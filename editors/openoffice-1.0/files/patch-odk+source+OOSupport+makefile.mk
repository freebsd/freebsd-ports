Index: odk/source/OOSupport/makefile.mk
===================================================================
RCS file: /cvs/api/odk/source/OOSupport/makefile.mk,v
retrieving revision 1.1.2.1
diff -u -r1.1.2.1 makefile.mk
--- odk/source/OOSupport/makefile.mk	13 Jan 2003 10:58:17 -0000	1.1.2.1
+++ odk/source/OOSupport/makefile.mk	4 Aug 2005 03:44:04 -0000
@@ -336,5 +336,5 @@
 	+cp -R ParserDB $(CLASSDIR)$/netbeans$/system
 	+cp openoffice-nbm-license.txt $(CLASSDIR)
 	+-mkdir $(CLASSDIR)$/netbeans$/modules
-	+cd $(CLASSDIR) && cp oosupport.jar netbeans$/modules && java MakeModule
+	+cd $(CLASSDIR) && cp oosupport.jar netbeans$/modules && java -classpath $(CLASSDIR) MakeModule
 	+cd $(CLASSDIR) && jar -uvf $(TARGETNETBEANSMODULEFILE) netbeans
