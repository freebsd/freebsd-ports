--- src/gcc3strm.cxx.orig	2007-08-23 05:01:30.049002000 +0000
+++ src/gcc3strm.cxx	2007-08-23 05:02:36.423000000 +0000
@@ -306,6 +306,7 @@
    return(1 || funcname || hash || result7 || libp) ;
 }
 
+#if 0
 static int G__G__stream_7_7_0(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
 {
       G__letint(result7, 103, (long) ((fpos<mbstate_t>*) G__getstructoffset())->operator==(*(fpos<mbstate_t>*) libp->para[0].ref));
@@ -317,6 +318,7 @@
       G__letint(result7, 103, (long) ((fpos<mbstate_t>*) G__getstructoffset())->operator!=(*(fpos<mbstate_t>*) libp->para[0].ref));
    return(1 || funcname || hash || result7 || libp) ;
 }
+#endif
 
 // automatic destructor
 typedef fpos<mbstate_t> G__TfposlEmbstate_tgR;
@@ -3961,8 +3963,10 @@
    G__memfunc_setup("operator streamoff",1875,G__G__stream_7_4_0, 110, -1, G__defined_typename("streamoff"), 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 0);
    G__memfunc_setup("operator+",919,G__G__stream_7_5_0, 117, G__get_linked_tagnum(&G__G__streamLN_fposlEmbstate_tgR), -1, 0, 1, 1, 1, 0, "n - 'streamoff' 0 - a", (char*)NULL, (void*) NULL, 0);
    G__memfunc_setup("operator-",921,G__G__stream_7_6_0, 117, G__get_linked_tagnum(&G__G__streamLN_fposlEmbstate_tgR), -1, 0, 1, 1, 1, 0, "n - 'streamoff' 0 - a", (char*)NULL, (void*) NULL, 0);
+#if 0
    G__memfunc_setup("operator==",998,G__G__stream_7_7_0, 103, -1, -1, 0, 1, 1, 1, 0, "u 'fpos<mbstate_t>' - 11 - a", (char*)NULL, (void*) NULL, 0);
    G__memfunc_setup("operator!=",970,G__G__stream_7_8_0, 103, -1, -1, 0, 1, 1, 1, 0, "u 'fpos<mbstate_t>' - 11 - a", (char*)NULL, (void*) NULL, 0);
+#endif
    // automatic destructor
    G__memfunc_setup("~fpos<mbstate_t>", 1651, G__G__stream_7_9_0, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 0);
    // automatic assignment operator
