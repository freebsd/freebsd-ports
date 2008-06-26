--- /dev/null	2008-06-26 21:42:58.000000000 +0200
+++ src/tcd_mb.c	2008-06-26 21:43:09.000000000 +0200
@@ -0,0 +1,98 @@
+/*-
+ * Copyright (c) 2008 Pietro Cerutti <gahr@FreeBSD.org>
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. All advertising materials mentioning features or use of this software
+ *    must display the following acknowledgement:
+ *	This product includes software developed by the University of
+ *	California, Berkeley and its contributors.
+ * 4. Neither the name of the University nor the names of its contributors
+ *    may be used to endorse or promote products derived from this software
+ *    without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ */
+
+#include "tcd_mb.h"
+#include <musicbrainz/mb_c.h>
+
+int
+tcd_readmb(struct tcd_state *cd, SDL_CD *cdrom)
+{
+    int nof_cds;	/* Can handle only one at the moment */
+    char *cd_title;
+    static char tmp_buff[256] = { 0 };
+    size_t len;
+    musicbrainz_t mb;
+
+    /*
+     * Sanity check
+     */
+    if(!cd || !cdrom)
+	return (1);
+
+    /*
+     * Initialize
+     */
+    cd_title = cd->cd_info.disc_title;
+    mb = mb_New();
+    mb_SetServer(mb, MB_HOST, MB_PORT);
+    mb_SetDevice(mb, SDL_CDName(cd->current_discid));
+    if (!mb_Query(mb, MBQ_GetCDInfo)) {
+	mb_GetQueryError(mb, tmp_buff, sizeof(tmp_buff));
+	fprintf(stderr, "MusicBrainz error: %s\n", tmp_buff);
+	return (1);
+    }
+
+    /*
+     * Query
+     */
+    nof_cds = mb_GetResultInt(mb, MBE_GetNumAlbums);
+    if(nof_cds != 1) {
+	fprintf(stderr, "MusicBrainz error: %sCD%s found\n",
+		!nof_cds ? "no" : "too many", !nof_cds ? "" : "s");
+	return (1);
+    }
+
+    /*
+     * Select
+     */
+    mb_Select1(mb, MBS_SelectArtist, 1);
+    mb_Select1(mb, MBS_SelectAlbum, 1);
+
+    /*
+     * Set Artist and Album
+     */
+    mb_GetResultData(mb, MBE_AlbumGetAlbumArtistName, tmp_buff, sizeof(tmp_buff));
+    len = snprintf(cd_title, 256, "%s / ", tmp_buff);
+    mb_GetResultData(mb, MBE_AlbumGetAlbumName, cd_title+len, 256 - len);
+
+    /*
+     * Set tracks
+     */
+    for(len = 1; len <= cdrom->numtracks; len++)
+	mb_GetResultData1(mb, MBE_AlbumGetTrackName, cd->cd_info.trk[len-1].name, 256, len);
+
+    mb_Delete(mb);
+
+    tcd_writediskinfo(&cd->cd_info, cdrom);
+
+    return (0);
+}
