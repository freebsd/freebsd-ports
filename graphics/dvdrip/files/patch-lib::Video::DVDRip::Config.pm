--- lib/Video/DVDRip/Config.pm.orig	Fri Dec 20 12:09:39 2002
+++ lib/Video/DVDRip/Config.pm	Fri Dec 20 12:14:45 2002
@@ -52,7 +52,7 @@
 	dvd_device => {
 		label => "DVD device",
 		type => 'file',
-		value => "/dev/dvd",
+		value => "/dev/cd0c",
 	},
 	dvd_mount_point => {
 		label => "DVD mount point",
@@ -81,7 +81,7 @@
 	play_stdin_command => {
 		label => "STDIN player command",
 		type  => 'string',
-		value => 'xine stdin://mpeg2 -g -pq -a %a',
+		value => 'mplayer -aid %(%a+128) -',
 		presets => [
 			'mplayer -aid %(%a+128) -',
 			'xine stdin://mpeg2 -g -pq -a %a',
@@ -124,7 +124,7 @@
 	burn_cdrecord_cmd => {
 		label => "cdrecord command",
 		type  => 'string',
-		value => '/usr/lib/xcdroast-0.98/bin/xcdrwrap CDRECORD',
+		value => 'cdrecord',
 		presets => [
 			'/usr/lib/xcdroast-0.98/bin/xcdrwrap CDRECORD',
 			'cdrecord',
@@ -171,11 +171,10 @@
 	default_video_codec => {
 		label => "Default Video Codec",
 		type  => 'string',
-		value => 'divx4',
+		value => 'xvid',
 		presets => [
-			"SVCD","VCD","divx4","divx5",
-			"xvid","xvidcvs","ffmpeg4","fame",
-			"af6"
+			"SVCD","VCD","xvid","ffmpeg4",
+			"fame","af6"
 		],
 	},
 );
--- lib/Video/DVDRip/Config.pm.orig	Fri Jan  3 15:21:22 2003
+++ lib/Video/DVDRip/Config.pm		Fri Jan  3 15:27:10 2003
@@ -54,11 +54,6 @@
 		type => 'file',
 		value => "/dev/dvd",
 	},
-	dvd_mount_point => {
-		label => "DVD mount point",
-		type => 'dir',
-		value => "/cdrom",
-	},
 	play_dvd_command => {
 		label => "DVD player command",
 		type  => 'string',
--- lib/Video/DVDRip/Config.pm.orig	Fri Jan  3 15:42:30 2003
+++ lib/Video/DVDRip/Config.pm	Fri Jan  3 15:43:33 2003
@@ -50,7 +50,7 @@
 		value => 5,
 	},
 	dvd_device => {
-		label => "DVD device",
+		label => "DVD mount point",
 		type => 'file',
 		value => "/dev/cd0c",
 	},
@@ -176,7 +176,7 @@
 
 my @CONFIG_ORDER = (
 	"Filesystem" => [qw(
-		dvd_device         dvd_mount_point
+		dvd_device
 		base_project_dir
 		dvdrip_files_dir   ogg_file_ext
 	)],
--- lib/Video/DVDRip/Config.pm.orig	Fri Jan  3 15:47:07 2003
+++ lib/Video/DVDRip/Config.pm	Fri Jan  3 15:47:17 2003
@@ -546,7 +546,7 @@
 sub test_play_file_command  	{ _executable (@_) 	}
 sub test_play_stdin_command 	{ _executable (@_) 	}
 
-sub test_dvd_device		{ _writable (@_)	}
+sub test_dvd_device		{ _exists (@_)	}
 sub test_dvd_mount_point	{ _exists (@_)		}
 sub test_base_project_dir	{ _writable (@_)	}
 sub test_dvdrip_files_dir	{ _writable (@_)	}
