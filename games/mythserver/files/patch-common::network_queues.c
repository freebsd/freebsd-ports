--- common/network_queues.c.orig	Wed Dec  5 12:59:14 2001
+++ common/network_queues.c	Wed Jan  7 16:37:13 2004
@@ -339,9 +339,9 @@
 void dump_queue(
 	struct circular_queue *queue)
 {
-	printf("Queue %s at 0x%x;g", queue->name, queue);
-	printf("Read at %d Write: %d Size: %d;g", queue->read_index, queue->write_index, queue->size);
-	printf("Buffer: 0x%x", queue->buffer);
+	printf("Queue %s at 0x%x;g", queue->name, &queue);
+	printf("Read at %ld Write: %ld Size: %ld;g", queue->read_index, queue->write_index, queue->size);
+	printf("Buffer: 0x%x", &(queue->buffer));
 	
 	return;
 }
@@ -385,7 +385,7 @@
 
 		if(length>maximum_length)
 		{
-			printf("q: %s got unusually large packet: length: %ld max: %d byteswap: %d",
+			printf("q: %s got unusually large packet: length: %ld max: %ld byteswap: %d",
  				queue->name, length, maximum_length, byteswap);
  			dump_queue(queue);
 			*disconnect = TRUE;
@@ -460,7 +460,7 @@
 
 		if(length>maximum_length)
 		{
-			printf("q: %s got unusually large packet: length: %d max: %d byteswap: %d",
+			printf("q: %s got unusually large packet: length: %d max: %ld byteswap: %d",
  				queue->name, length, maximum_length, byteswap);
  			dump_queue(queue);
 			*disconnect = TRUE;
