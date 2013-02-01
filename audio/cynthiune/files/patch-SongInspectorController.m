--- ./SongInspectorController.m.orig	2012-03-05 20:56:28.000000000 -0500
+++ ./SongInspectorController.m	2012-03-05 21:03:15.000000000 -0500
@@ -34,8 +34,6 @@
 #import <Foundation/NSString.h>
 #import <Foundation/NSThread.h>
 
-#import <musicbrainz/mb_c.h>
-
 #import <Cynthiune/Format.h>
 #import <Cynthiune/NSViewExtensions.h>
 #import <Cynthiune/utils.h>
@@ -156,10 +154,10 @@
     {
       if (!threadRunning)
         {
-          [lookupButton setEnabled: YES];
-          [lookupButton setImage: [NSImage imageNamed: @"lookup-mb-on"]];
+          [lookupButton setEnabled: NO];
+          [lookupButton setImage: [NSImage imageNamed: @"lookup-mb-off"]];
           [lookupAnimation setImage: nil];
-          [lookupStatusLabel setStringValue: @""];
+          [lookupStatusLabel setStringValue: @"MB lookup doesn't work!"];
         }
     }
   else
@@ -320,39 +318,6 @@
                               forKey: @"song"]];
 }
 
-- (char *) _generateTrmId
-{
-  id <Format> stream;
-  trm_t trmGen;
-  int size;
-  char sig[17];
-  unsigned char buffer[4096];
-  char *trmId;
-
-  stream = [song openStreamForSong];
-  if (stream)
-    {
-      trmGen = trm_New ();
-      trm_SetPCMDataInfo (trmGen,
-                          [stream readRate], [stream readChannels], 16);
-      trm_SetSongLength (trmGen, [stream readDuration]);
-      size = [stream readNextChunk: buffer withSize: 4096];
-      while (!trm_GenerateSignature (trmGen, (char *) buffer, size))
-        size = [stream readNextChunk: buffer withSize: 4096];
-
-      trm_FinalizeSignature (trmGen, sig, NULL);
-
-      trmId = malloc (37);
-      trm_ConvertSigToASCII (trmGen, sig, trmId);
-      trm_Delete (trmGen);
-      [stream streamClose];
-    }
-  else
-    trmId = NULL;
-
-  return trmId;
-}
-
 - (void) updateField: (NSTextField *) field
           withString: (NSString *) string
 {
@@ -418,132 +383,6 @@
                                    selector: @selector (_updateFieldsWithTrackInfos:)];
 }
 
-- (NSDictionary *) readMB: (musicbrainz_t) mb
-                    track: (int) track
-{
-  NSMutableDictionary *trackInfos;
-  NSString *string;
-  char cString[100];
-  int releases;
-
-  trackInfos = [NSMutableDictionary new];
-  [trackInfos autorelease];
-
-  mb_Select1 (mb, MBS_SelectTrack, track);
-  if (mb_GetResultData (mb, MBE_TrackGetTrackName, cString, 100))
-    {
-      string = [NSString stringWithUTF8String: cString];
-      [trackInfos setObject: string forKey: @"title"];
-    }
-
-  if (mb_GetResultData (mb, MBE_TrackGetArtistName, cString, 100))
-    {
-      string = [NSString stringWithUTF8String: cString];
-      [trackInfos setObject: string forKey: @"artist"];
-    }
-
-  if (mb_GetResultData (mb, MBE_TrackGetTrackNum, cString, 100))
-    {
-      string = [NSString stringWithUTF8String: cString];
-      [trackInfos setObject: string forKey: @"trackNumber"];
-    }
-
-  if (mb_Select (mb, MBS_SelectTrackAlbum))
-    {
-      if (mb_GetResultData (mb, MBE_AlbumGetAlbumName, cString, 100))
-        {
-          string = [NSString stringWithUTF8String: cString];
-          [trackInfos setObject: string forKey: @"album"];
-        }
-#ifdef MBE_AlbumGetNumReleaseDates
-      releases = mb_GetResultInt (mb, MBE_AlbumGetNumReleaseDates);
-      if (releases)
-        {
-          mb_Select1 (mb, MBS_SelectReleaseDate, 1);
-          if (mb_GetResultData (mb, MBE_ReleaseGetDate, cString, 100))
-            {
-              *(cString + 4) = 0;
-              string = [NSString stringWithUTF8String: cString];
-              [trackInfos setObject: string forKey: @"year"];
-            }
-          mb_Select (mb, MBS_Back);
-        }
-#endif
-
-      mb_Select (mb, MBS_Back);
-    }
-
-  mb_Select (mb, MBS_Rewind);
-
-  return trackInfos;
-}
-
-- (void) _parseMB: (musicbrainz_t) mb
-{
-  int count, results;
-  NSMutableArray *allTrackInfos;
-
-  results = mb_GetResultInt (mb, MBE_GetNumTracks);
-  allTrackInfos = [[NSMutableArray alloc] initWithCapacity: results];
-  [allTrackInfos autorelease];
-
-  for (count = 0; count < results; count++)
-    [allTrackInfos addObject: [self readMB: mb track: count + 1]];
-
-  [self performSelectorOnMainThread: @selector (_updateSongFields:)
-        withObject: allTrackInfos
-        waitUntilDone: YES];
-}
-
-- (void) lookupThread
-{
-  NSAutoreleasePool *pool;
-  char *trmId;
-  musicbrainz_t mb;
-  char **qis;
-  char error[80];
-
-  pool = [NSAutoreleasePool new];
-
-  [self updateField: lookupStatusLabel
-        withString: LOCALIZED(@"Generating TRM...")];
-  trmId = [self _generateTrmId];
-  if (trmId && !threadShouldDie)
-    {
-      qis = MakeQis (trmId, song);
-
-      if (strcasecmp (trmId, busyTrmId))
-        {
-          [self updateField: lookupStatusLabel
-                withString: LOCALIZED (@"Querying MusicBrainz server...")];
-          mb = mb_New ();
-          mb_UseUTF8 (mb, YES);
-          if (mb_QueryWithArgs (mb, MBQ_TrackInfoFromTRMId, qis))
-            [self _parseMB: mb];
-          else
-            {
-//            FIXME: there should be an accurate error message here...
-              [self updateField: lookupStatusLabel
-                    withString: @""];
-              mb_GetQueryError (mb, error, 80);
-              NSLog (@"Musicbrainz error: %s (%s)", error, trmId);
-            }
-          mb_Delete (mb);
-        }
-      else
-        [self updateField: lookupStatusLabel
-              withString: LOCALIZED (@"The MusicBrainz server was too busy")];
-
-      FreeQis (qis);
-    }
-
-  [self performSelectorOnMainThread: @selector (lookupThreadEnded)
-        withObject: nil
-        waitUntilDone: NO];
-
-  [pool release];
-}
-
 - (void) mbLookup: (id)sender
 {
   if (song)
