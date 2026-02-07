--- libdrizzle/binlog.cc.orig	2018-08-27 19:29:31 UTC
+++ libdrizzle/binlog.cc
@@ -316,7 +316,7 @@ drizzle_return_t drizzle_state_binlog_read(drizzle_st 
     if (con->packet_size != binlog_event->length)
     {
         drizzle_set_error(con, "drizzle_state_binlog_read",
-                          "packet size error:%"PRIu32":%"PRIu32, con->packet_size, binlog_event->length);
+                          "packet size error:%" PRIu32 ":%" PRIu32, con->packet_size, binlog_event->length);
         con->binlog->error_fn(DRIZZLE_RETURN_UNEXPECTED_DATA, con, con->binlog->binlog_context);
         return DRIZZLE_RETURN_UNEXPECTED_DATA;
     }
@@ -374,7 +374,7 @@ drizzle_return_t drizzle_state_binlog_read(drizzle_st 
         event_crc= (uint32_t)crc32(0, binlog_event->raw_data, (binlog_event->raw_length - DRIZZLE_BINLOG_CRC32_LEN));
         if (event_crc != binlog_event->checksum)
         {
-          drizzle_set_error(con, __func__, "CRC doesn't match: 0x%"PRIX32", 0x%"PRIX32, event_crc, binlog_event->checksum);
+          drizzle_set_error(con, __func__, "CRC doesn't match: 0x%" PRIX32 ", 0x%" PRIX32, event_crc, binlog_event->checksum);
           con->binlog->error_fn(DRIZZLE_RETURN_BINLOG_CRC, con, con->binlog->binlog_context);
           return DRIZZLE_RETURN_BINLOG_CRC;
         }
