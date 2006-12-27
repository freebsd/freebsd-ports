--- db/sqlblob.h	Thu Dec  1 01:01:01 2005
+++ db/sqlblob.h	Thu Dec 14 23:26:29 2006
@@ -75,7 +75,7 @@
      fflush(stderr);
 #endif
    }
-   b.mem=new std::vector<T>(xml_decode_string(buf.c_str()+start,end-start,enc_string));
+   b.mem=new std::vector<T>(xml_decode_string<T>(buf.c_str()+start,end-start,enc_string));
 #ifdef DEBUG_ALLOCATIONS
    fprintf(stderr,"sqlblob: allocated a vector at 0x%p\n",b.mem);
    fflush(stderr);

