http://qa.openoffice.org/issues/show_bug.cgi?id=27028

--- ../solenv/inc/ant.mk~	Wed Feb  4 21:37:16 2004
+++ ../solenv/inc/ant.mk	Fri Apr  2 23:59:27 2004
@@ -100,7 +100,7 @@
 .ENDIF
 .ENDIF
 
-ANT=$(WRAPCMD) java -classpath $(CLASSPATH) -Xmx128m org.apache.tools.ant.Main -Djava.home=$(JAVA_HOME) -Dant.home=$(ANT_HOME)
+#ANT=$(WRAPCMD) java -classpath $(CLASSPATH) -Xmx128m org.apache.tools.ant.Main -Djava.home=$(JAVA_HOME) -Dant.home=$(ANT_HOME)
 #ANT=java -version
 
 .IF "$(ANT_BUILDFILE)"==""
