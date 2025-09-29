--- libblkid/src/devname.c.orig	2025-06-24 07:55:28 UTC
+++ libblkid/src/devname.c
@@ -224,7 +224,11 @@ static void probe_one(blkid_cache cache, const char *p
 
 		if (stat(device, &st) == 0 &&
 		    (S_ISBLK(st.st_mode) ||
-		     (S_ISCHR(st.st_mode) && !strncmp(ptname, "ubi", 3))) &&
+		     (S_ISCHR(st.st_mode)
+#ifdef __linux__
+		      && !strncmp(ptname, "ubi", 3)
+#endif
+		      )) &&
 		    st.st_rdev == devno) {
 			devname = strdup(device);
 			goto get_dev;
@@ -251,8 +255,12 @@ set_pri:
 			dev->bid_pri = BLKID_PRI_DM;
 			if (is_dm_leaf(ptname))
 				dev->bid_pri += 5;
-		} else if (!strncmp(ptname, "md", 2))
-			dev->bid_pri = BLKID_PRI_MD;
+		} else {
+#ifdef __linux__
+			if (!strncmp(ptname, "md", 2))
+				dev->bid_pri = BLKID_PRI_MD;
+#endif
+		}
 		if (removable)
 			dev->bid_flags |= BLKID_BID_FL_REMOVABLE;
 	}
