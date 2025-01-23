--- libio/src/io_time.c.orig	2025-01-23 08:31:29 UTC
+++ libio/src/io_time.c
@@ -205,8 +205,6 @@ io_internal_gettime(clockid_t clock_id, struct timespe
         return IO_TIME_ERR_GET_REAL;
       case CLOCK_MONOTONIC:
         return IO_TIME_ERR_GET_MONO;
-      case CLOCK_MONOTONIC_RAW:
-        return IO_TIME_ERR_GET_MONO_RAW;
       default:
         abort();  /* Invalid clock_id, abort the program. */
     }
