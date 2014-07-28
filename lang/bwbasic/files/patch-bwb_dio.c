--- ../../foo/bwbasic-2.20/bwb_dio.c	Sun Nov 26 09:02:18 1995
+++ bwb_dio.c	Thu Jan 16 11:10:58 1997
@@ -90,7 +90,6 @@
    {
    FILE *fp;
    struct exp_ese *e;
-   int previous_buffer;
    char atbuf[ MAXSTRINGSIZE + 1 ];
    char first[ MAXSTRINGSIZE + 1 ];
    char devname[ MAXSTRINGSIZE + 1 ];
@@ -98,7 +97,6 @@
    /* initialize */
 
    mode = req_devnumber = rlen = -1;
-   previous_buffer = FALSE;
 
    /* get the first expression element up to comma or whitespace */
 
@@ -435,7 +433,15 @@
       sprintf( bwb_ebuf, "in bwb_open(): using previously closed file (and buffer)" );
       bwb_debug( bwb_ebuf );
 #endif
-      previous_buffer = TRUE;
+      /*
+       * Previous code assumed that buffer was always valid, and
+       * always the right size.  (MJS)
+       */
+      if (dev_table[ req_devnumber ].buffer != NULL) 
+         {
+         free (dev_table[ req_devnumber ].buffer);
+         dev_table[ req_devnumber ].buffer = NULL;
+         }
       }
 
    if ( ( dev_table[ req_devnumber ].mode != DEVMODE_CLOSED ) &&
@@ -512,7 +518,7 @@
 
    /* allocate a character buffer for random access */
 
-   if (( mode == DEVMODE_RANDOM ) && ( previous_buffer != TRUE ))
+   if ( mode == DEVMODE_RANDOM )
       {
       /* Revised to CALLOC pass-thru call by JBV */
       if ( ( dev_table[ req_devnumber ].buffer = CALLOC( rlen + 1, 1, "bwb_open" )) == NULL )
