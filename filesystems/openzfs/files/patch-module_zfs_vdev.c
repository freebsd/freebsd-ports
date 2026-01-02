--- module/zfs/vdev.c.orig	2025-12-18 18:01:01 UTC
+++ module/zfs/vdev.c
@@ -4674,7 +4674,7 @@ vdev_clear(spa_t *spa, vdev_t *vd)
 	vd->vdev_stat.vs_checksum_errors = 0;
 	vd->vdev_stat.vs_dio_verify_errors = 0;
 	vd->vdev_stat.vs_slow_ios = 0;
-	atomic_store_64(&vd->vdev_outlier_count, 0);
+	atomic_store_64((volatile uint64_t *)&vd->vdev_outlier_count, 0);
 	vd->vdev_read_sit_out_expire = 0;
 
 	for (int c = 0; c < vd->vdev_children; c++)
