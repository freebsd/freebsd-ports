--- mixer.c.orig	Mon Apr  2 23:12:21 2001
+++ mixer.c	Fri Aug 10 23:22:04 2001
@@ -49,6 +49,8 @@
 static int num_channels;
 #endif /* __OpenBSD__ || __NetBSD__ */
 
+#define MIN(a, b) ((a) < (b) ? (a) : (b))
+
 static unsigned int volume;
 
 static int
@@ -167,7 +169,7 @@
 					break;
 			}
 		} else {
-			fprintf(stderr, "Bad numbers %s", q);
+			fprintf(stderr, "Bad numbers %s\n", q);
 			return -1;
 		}
 	}
@@ -298,9 +300,13 @@
 	int devlen, dev_volume;
 
 	devlen = strcspn(vol, "=");
-	strncpy(dev, vol, devlen);
-	strncpy(val, &vol[devlen+1], strlen(vol)-devlen-1);
-
+	if (devlen == strlen(vol)) {
+		fprintf(stderr, "invalid volume specifier %s\n", vol);
+		return -1;
+	}
+	strlcpy(dev, vol, MIN(devlen + 1, sizeof(dev)));
+	strlcpy(val, &vol[devlen+1], MIN(strlen(vol)-devlen, sizeof(val)));
+	
 #if defined (__OpenBSD__) || (__NetBSD__)
 
 	for ( ndev = 0 ; ; ndev++ ) {
