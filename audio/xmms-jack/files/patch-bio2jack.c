--- bio2jack.c.orig	Thu Apr  8 10:03:08 2004
+++ bio2jack.c	Thu Apr  8 10:07:28 2004
@@ -585,6 +585,7 @@
       /* and transition to STOPPED */
       if(this->state == RESET)
       {
+		wave_header_t *wh;
           this->written_client_bytes    = 0;
           this->played_client_bytes     = 0;  /* number of the clients bytes that jack has played */
 
@@ -598,7 +599,7 @@
           /* free up all of the buffers of audio that are queued */
           /* NOTE: this needs to be done inside of the callback because */
           /*  the callback could be using any of these buffers */
-          wave_header_t *wh = this->pPlayPtr;
+		wh = this->pPlayPtr;
           while(wh)
           {
               wh = wh->pNext;
