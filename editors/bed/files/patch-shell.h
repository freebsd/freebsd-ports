$FreeBSD$

--- src/shell.h.orig	Thu May 30 07:22:42 2002
+++ src/shell.h	Fri Jan 30 12:22:26 2004
@@ -23,20 +23,56 @@
 #else
 #define process(commando,args...)   executor(commando,commando,args,NULL)
 #endif
-inline int executor(const char *commando,...)   {
+inline int executor(char *commando,...)   {
+	if(!fork())  {
 		va_list ap;
-		if(!fork())  {
-				va_start(ap,commando);
-			  execvp(commando,(char **)ap);
-				va_end(ap);
-				perror(commando); 
-				exit(4);
-				}
-	else {
-			int statusdieprocessreturns;
-			wait(&statusdieprocessreturns);
-			return statusdieprocessreturns;
+		char *arg;
+		int argc = 0;
+		char **argv = NULL;
+		argv = (char **) malloc(2 * sizeof(char *)); /* commando, NULL */
+		if (argv == NULL)
+			goto cleanup;
+		
+		/* Copy the relevant args into argv */
+		argv[argc] = (char *) malloc((strlen(commando) + 1) * sizeof(char));
+		if (argv[argc] == NULL)
+			goto cleanup;
+		strlcpy(argv[argc], commando, strlen(commando) + 1);
+
+		va_start(ap, commando);
+		while (*commando) {
+			switch (*commando++) {
+				case 's':
+					argc++;
+					if (realloc(argv, (argc + 2) * sizeof(char *)) == NULL)
+						goto cleanup;
+					arg = va_arg(ap, char *);
+					argv[argc] = (char *) malloc((strlen(arg) + 1) * sizeof(char));
+					if (argv[argc] == NULL)
+						goto cleanup;
+					strlcpy(argv[argc], arg, strlen(arg) + 1);
+					break;
+			}
+		}
+		va_end(ap);
+
+		argv[++argc] = NULL;
+		execvp(commando, argv);
+		perror(commando);
+cleanup:
+		if (argv != NULL) {
+			while (argc--) {
+				free(argv[argc]);
 			}
+			free(argv);
+		}
+		exit(4);
+	}
+	else {
+		int statusdieprocessreturns;
+		wait(&statusdieprocessreturns);
+		return statusdieprocessreturns;
 	}
+}
 #endif
 #endif
