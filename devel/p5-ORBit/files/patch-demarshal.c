--- demarshal.c.orig	Mon Oct 16 03:32:32 2000
+++ demarshal.c	Tue Oct 15 20:35:32 2002
@@ -7,7 +7,7 @@
 #include "types.h"
 
 #define RECV_BUFFER_LEFT(buf) \
- (((guchar *)buf->message_body + GIOP_MESSAGE_BUFFER(buf)->message_header.message_size) - (guchar *)buf->cur)
+ (((guchar *)buf->message_body + 12 + GIOP_MESSAGE_BUFFER(buf)->message_header.message_size) - (guchar *)buf->cur)
 
 
 static CORBA_boolean
