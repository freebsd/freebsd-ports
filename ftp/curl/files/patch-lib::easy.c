diff -urN -urN -x .svn ../../vendor/curl/lib/easy.c ./lib/easy.c
--- ../../vendor/curl/lib/easy.c	2008-03-24 00:40:11.000000000 +0200
+++ ./lib/easy.c	2008-03-29 16:08:15.000000000 +0200
@@ -819,7 +819,7 @@
       if(data->state.tempwrite && (tempsize - chunklen)) {
         /* Ouch, the reading is again paused and the block we send is now
            "cached". If this is the final chunk we can leave it like this, but
-           if we have more chunks that is cached after this, we need to free
+           if we have more chunks that are cached after this, we need to free
            the newly cached one and put back a version that is truly the entire
            contents that is saved for later
         */
