Index: soundserver/artswrapper.c
===================================================================
--- soundserver/artswrapper.c	(revision 546970)
+++ soundserver/artswrapper.c	(working copy)
@@ -95,6 +95,10 @@ int main(int argc, char **argv)
 #else
 		setreuid(-1, getuid());
 #endif
+		if (geteuid() != getuid()) {
+			perror("setuid()");
+			return 2;
+		}
 	}
 
 	if(argc == 0)
Index: soundserver/crashhandler.cc
===================================================================
--- soundserver/crashhandler.cc	(revision 546970)
+++ soundserver/crashhandler.cc	(working copy)
@@ -196,7 +196,12 @@ CrashHandler::defaultCrashHandler (int s
           argv[i++] = NULL;
 
           setgid(getgid());
-          setuid(getuid());
+          if (getuid() != geteuid())
+            setuid(getuid());
+          if (getuid() != geteuid()) {
+	    perror("setuid()");
+            exit(255);
+          }
 
           execvp(crashApp, argv);
 
