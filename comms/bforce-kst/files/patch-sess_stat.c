--- bforce/sess_stat.c.old	Sat Aug  7 02:06:26 2004
+++ bforce/sess_stat.c	Sat Aug  7 02:11:29 2004
@@ -75,7 +75,7 @@
 	
 	memset(stat, '\0', sizeof(s_sess_stat));
 	
-	fscanf(fp, "%u %u %u %u %u %lu %lu %lu %lu",
+	fscanf(fp, "%u %u %u %u %u %u %lu %lu %lu %lu",
 			(unsigned int *) &stat->tries,
 			(unsigned int *) &stat->tries_noconn,
 			(unsigned int *) &stat->tries_noansw,
@@ -98,7 +98,7 @@
 	if( fseek(fp, 0, SEEK_SET) == -1 )
 		return -1;
 	
-	fprintf(fp, "%u %u %u %u %u %lu %lu %lu %lu",
+	fprintf(fp, "%u %u %u %u %u %u %lu %lu %lu %lu",
 			(unsigned int) stat->tries,
 			(unsigned int) stat->tries_noconn,
 			(unsigned int) stat->tries_noansw,
