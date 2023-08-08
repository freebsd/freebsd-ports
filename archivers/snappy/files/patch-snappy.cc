--- snappy.cc.orig	2023-03-12 08:04:09 UTC
+++ snappy.cc
@@ -1290,7 +1290,7 @@ std::pair<const uint8_t*, ptrdiff_t> DecompressBranchl
         DeferMemCopy(&deferred_src, &deferred_length, from, len);
       }
     } while (ip < ip_limit_min_slop &&
-             (op + deferred_length) < op_limit_min_slop);
+             (op + deferred_length) < (size_t)op_limit_min_slop);
   exit:
     ip--;
     assert(ip <= ip_limit);
