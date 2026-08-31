--- tools/lkl/lib/virtio_blk.c.orig	2018-06-28 05:58:16 UTC
+++ tools/lkl/lib/virtio_blk.c
@@ -51,7 +51,7 @@ static int blk_enqueue(struct virtio_dev *dev, int q, 
 
 	lkl_req.type = le32toh(h->type);
 	lkl_req.prio = le32toh(h->ioprio);
-	lkl_req.sector = le32toh(h->sector);
+	lkl_req.sector = le64toh(h->sector);
 	lkl_req.buf = &req->buf[1];
 	lkl_req.count = req->buf_count - 2;
 
@@ -98,7 +98,7 @@ int lkl_disk_add(struct lkl_disk *disk)
 		ret = -LKL_ENOMEM;
 		goto out_free;
 	}
-	dev->config.capacity = capacity / 512;
+	dev->config.capacity = htole64(capacity / 512);
 
 	ret = virtio_dev_setup(&dev->dev, 1, 32);
 	if (ret)
