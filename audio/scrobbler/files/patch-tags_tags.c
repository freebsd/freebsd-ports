--- tags/tags.c.orig	2005-02-20 18:08:42 UTC
+++ tags/tags.c
@@ -141,37 +141,6 @@ void tag_exists(metatag_t *meta, char *f
 	return;
 }
 
-void metaCD(metatag_t *meta, char *filename, int track)
-{
-	int tmp;
-	
-	pdebug("Getting CD Audio metadata...", META_DEBUG);
-	meta->cdaudio = readCDAudio(filename, track);
-	if(meta->cdaudio == NULL)
-	{
-		pdebug("Error getting metadata", META_DEBUG);
-		
-		return;
-	}
-	
-	meta->has_cdaudio = 1;
-	
-	pdebug("Reading metadata into structs...", META_DEBUG);
-	meta->artist = meta->cdaudio->artist;
-	meta->title = meta->cdaudio->title;
-	meta->mb = realloc(meta->mb, strlen(meta->cdaudio->mbid) + 1);
-	strcpy(meta->mb, meta->cdaudio->mbid);
-	meta->album = meta->cdaudio->album;
-	meta->year = NULL;
-	meta->genre = NULL;
-	/* Special track handling... Yay! */
-	meta->track = realloc(meta->track, 4);
-	tmp = snprintf(meta->track, 3, "%d", track);
-	*(meta->track + tmp) = '\0';
-	
-	return;
-} /* End CD Audio support */
-
 static ape_t *fetchAPE(char *filename)
 {
 	ape_t *ape;
@@ -693,8 +662,6 @@ void get_tag_data(metatag_t *meta, char 
 {
 	if(track > 0)
 	{
-		metaCD(meta, filename, track);
-		
 		return;
 	}
 	else
@@ -801,8 +768,6 @@ void metatag_delete(metatag_t *meta)
 		freeVorbis(meta->speex);
 	if(meta->itunes != NULL)
 		freeiTunes(meta->itunes);
-	if(meta->cdaudio != NULL)
-		freeCDAudio(meta->cdaudio);
 	free(meta);
 }
 
