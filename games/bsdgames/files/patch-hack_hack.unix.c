--- hack/hack.unix.c.orig	2014-07-22 09:54:22.000000000 -0400
+++ hack/hack.unix.c	2014-07-22 10:20:43.000000000 -0400
@@ -18,7 +18,9 @@
 
 #include <sys/types.h>	/* for time_t and stat */
 #include <sys/stat.h>
+#include <sys/param.h>
 #include <time.h>
+#include <err.h>
 
 static struct tm *getlt(void);
 static bool  veryold(int);
@@ -94,13 +96,32 @@
 void
 gethdate(const char *name)
 {
-/* old version - for people short of space */
-	char *np;
+	char *p, *np, *path;
+	char filename[MAXPATHLEN+1];
 
-	name = "/usr/games/hide/hack";
-	if (stat(name, &hbuf))
-		error("Cannot get status of %s.",
-		      (np = strrchr(name, '/')) ? np + 1 : name);
+	if (strchr(name, '/') != NULL || (p = getenv("PATH")) == NULL)
+		p = "";
+	np = path = strdup(p);	/* Make a copy for strsep. */
+	if (path == NULL)
+		err(1, NULL);
+
+	for (;;) {
+		if ((p = strsep(&np, ":")) == NULL)
+			break;
+		if (*p == '\0')			/* :: */
+			(void) strlcpy(filename, name, sizeof filename);
+		else
+			(void) snprintf(filename, sizeof filename,
+			    "%s/%s", p, name);
+
+		if (stat(filename, &hbuf) == 0) {
+			free(path);
+			return;
+		}
+	}
+	error("Cannot get status of %s.",
+		(p = strrchr(name, '/')) ? p+1 : name);
+	free(path);
 }
 
 bool
