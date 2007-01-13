--- udf.c.orig	Sat Jan 13 16:35:48 2007
+++ udf.c	Sat Jan 13 16:36:03 2007
@@ -127,7 +127,7 @@ nsr:
 
 anchor:
 	/* read anchor volume descriptor */
-	vd = (struct volume_descriptor *) volume_id_get_buffer(id, off + (256 * bs), 0x200);
+	vd = (struct volume_descriptor *) volume_id_get_buffer(id, off + (256 * bs), bs);
 	if (vd == NULL)
 		return -1;
 
@@ -142,7 +142,7 @@ anchor:
 
 	/* pick the primary descriptor from the list */
 	for (b = 0; b < count; b++) {
-		vd = (struct volume_descriptor *) volume_id_get_buffer(id, off + ((loc + b) * bs), 0x200);
+		vd = (struct volume_descriptor *) volume_id_get_buffer(id, off + ((loc + b) * bs), bs);
 		if (vd == NULL)
 			return -1;
 
