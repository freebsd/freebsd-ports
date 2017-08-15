https://github.com/CDrummond/cantata/pull/1052

--- devices/cddbinterface.cpp.orig	2017-07-30 19:13:05 UTC
+++ devices/cddbinterface.cpp
@@ -158,7 +158,7 @@ void CddbInterface::readDisc()
                     cddb_track_t *track = cddb_track_new();
                     if (track) {
                         cddb_track_set_frame_offset(track, te.entry.addr.lba + SECONDS_TO_FRAMES(2));
-                        cddb_track_set_title(track, te.entry.control&0x04 ? dataTrack().toUtf8().constData() : tr("Track %1", i).toUtf8().constData());
+                        cddb_track_set_title(track, te.entry.control&0x04 ? dataTrack().toUtf8().constData() : tr("Track %1").arg(i).toUtf8().constData());
                         cddb_track_set_artist(track, unknown.constData());
                         cddb_disc_add_track(disc, track);
                     }
