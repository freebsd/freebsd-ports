--- src/commandline_part.cpp.orig	Sat Apr 29 01:22:18 2006
+++ src/commandline_part.cpp	Sat Apr 29 01:22:57 2006
@@ -33,7 +33,7 @@
         KStandardDirs::kde_default("data")+ QString::fromLatin1( inst->instanceName() ) + '/' );
 
 
-    m_pCPart = new CommandExec(this,name?QString(name)+QString("_exec"):"command_executer",args);
+    m_pCPart = new CommandExec(this,name?QString(name)+QString("_exec"):QString::fromLatin1("command_executer"),args);
 }
 
 commandline_part::~commandline_part()
