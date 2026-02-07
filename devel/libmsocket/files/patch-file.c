--- file.c.orig	2008-10-12 23:30:58 UTC
+++ file.c
@@ -171,6 +171,7 @@ short lms_file_icanrw(struct stat *fs)
 	gid_t l;
 	register unsigned int i;
 	int grpcnt;
+	long ngroups_max;
 
 	if (!fs)
 	{
@@ -212,13 +213,14 @@ short lms_file_icanrw(struct stat *fs)
 			return(1);
 		}
 
-		glist = (gid_t *)malloc(NGROUPS + 1);
+		ngroups_max = sysconf(_SC_NGROUPS_MAX) + 1;
+		glist = (gid_t *)malloc(sizeof(gid_t) * ngroups_max);
 		if (!glist)
 		{
 			return(-1);
 		}
 
-		if ((grpcnt = getgroups((NGROUPS + 1), glist)) < 0)
+		if ((grpcnt = getgroups(ngroups_max, glist)) < 0)
 		{
 			free(glist);
 			return(-1);
@@ -257,6 +259,7 @@ short lms_file_icanr(struct stat *fs)
 	gid_t l;
 	register unsigned int i;
 	int grpcnt;
+	long ngroups_max;
 
 	if (!fs)
 	{
@@ -298,13 +301,14 @@ short lms_file_icanr(struct stat *fs)
 			return(1);
 		}
 
-		glist = (gid_t *)malloc(NGROUPS + 1);
+		ngroups_max = sysconf(_SC_NGROUPS_MAX) + 1;
+		glist = (gid_t *)malloc(sizeof(gid_t) * ngroups_max);
 		if (!glist)
 		{
 			return(-1);
 		}
 
-		if ((grpcnt = getgroups((NGROUPS + 1), glist)) < 0)
+		if ((grpcnt = getgroups(ngroups_max, glist)) < 0)
 		{
 			free(glist);
 			return(-1);
