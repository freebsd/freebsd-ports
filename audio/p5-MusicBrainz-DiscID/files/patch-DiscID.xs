fix Unparseable XSUB parameter: 'offsets ...' in DiscID.xs, line 116

--- DiscID.xs.orig	2025-07-13 08:36:28 UTC
+++ DiscID.xs
@@ -113,7 +113,7 @@ int
 ## Provides the TOC of a known CD.
 ##
 int
-discid_put( disc, first_track, sectors, offsets ... )
+discid_put( disc, first_track, sectors, offsets, ... )
   DiscId *disc
   int first_track
   int sectors
