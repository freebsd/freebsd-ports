--- src/script.h.orig	Thu Feb 17 19:01:10 2005
+++ src/script.h	Thu Feb 17 19:00:29 2005
@@ -550,11 +550,6 @@ protected:
 	virtual unsigned long getTrapMask(const char *trapname);
 
 	/**
-	 * Default compiler syntax to accept any syntax.
-	 */
-	char *chkIgnore(Line *line, ScriptImage *img);
-
-	/**
 	 * Module based script checker.
 	 */
 	char *chkModule(Line *line, ScriptImage *img);
@@ -598,15 +593,6 @@ protected:
 	char *chkNoArgs(Line *line, ScriptImage *img);
 
 	/**
-	 * Script compiler syntax check for commands that require
-	 * one or more arguments to be present.
-	 *
-	 * @return syntax error message string or NULL.
-	 * @param line statement.
-	 */
-	char *chkHasArgs(Line *line, ScriptImage *img);
-
-	/**
 	 * Load a set of keywords into the system keyword table.  This
 	 * provides a convenient method of initializing and adding to
 	 * the keyword indexes.
@@ -658,6 +644,20 @@ public:
 
 	virtual int mapnicmp(const char *s1, const char *s2, size_t n)
 		{return strnicmp(s1, s2, n);};
+
+	/**
+	 * Script compiler syntax check for commands that require
+	 * one or more arguments to be present.
+	 *
+	 * @return syntax error message string or NULL.
+	 * @param line statement.
+	 */
+	char *chkHasArgs(Line *line, ScriptImage *img);
+
+	/**
+	 * Default compiler syntax to accept any syntax.
+	 */
+	char *chkIgnore(Line *line, ScriptImage *img);
 };
 
 /**
