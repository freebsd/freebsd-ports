--- unix.c.orig	2016-06-14 16:25:53 UTC
+++ unix.c
@@ -0,0 +1,87 @@
+#ifdef __unix__
+#include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <pwd.h>
+#include <errno.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#if defined(__DECC) && defined(VMS)
+#include <unixlib.h>
+static char *vms_to_unix_buffer = NULL;
+static int convert_vms_to_unix(char *vms_dir_name)
+{
+	vms_to_unix_buffer = vms_dir_name;
+}
+#endif
+
+char *get_homedir(void)
+{
+	struct passwd *pw;
+	char *home;
+
+	home = getenv("HOME");
+	if (home)
+		return home;
+
+	if (!(pw = getpwuid(getuid())))
+	{
+		fprintf(stderr, "Who are you? Not found in passwd database!!\n");
+		return NULL;
+	}
+
+#if defined(__DECC) && defined(VMS)
+	/* Convert The OpenVMS Formatted "$HOME" Directory Path Into Unix
+	   Format. */
+	decc$from_vms(pw->pw_dir, convert_vms_to_unix, 1);
+	return vms_to_unix_buffer;
+#else
+	return pw->pw_dir;
+#endif
+}
+//-----------------------------------------------------------------------------
+int check_and_create_dir(const char *name)
+{
+	struct stat stat_buffer;
+
+	if (stat(name, &stat_buffer))
+	{
+		/* error check if it doesn't exist or something else is wrong */
+		if (errno == ENOENT)
+		{
+			/* doesn't exist letts create it ;) */
+#ifdef BSD43
+			if (mkdir(name, 0775))
+#else
+				if (mkdir(name, S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH))
+#endif
+				{
+					fprintf(stderr, "Error creating dir %s", name);
+					perror(" ");
+					return -1;
+				}
+		}
+		else
+		{
+			/* something else went wrong yell about it */
+			fprintf(stderr, "Error opening %s", name);
+			perror(" ");
+			return -1;
+		}
+	}
+	else
+	{
+		/* file exists check it's a dir otherwise yell about it */
+#ifdef BSD43
+		if (!(S_IFDIR & stat_buffer.st_mode))
+#else
+			if (!S_ISDIR(stat_buffer.st_mode))
+#endif
+			{
+				fprintf(stderr,"Error %s exists but isn't a dir\n", name);
+				return -1;
+			}
+	}
+	return 0;
+}
+#endif
