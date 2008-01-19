--- gtk2_ardour/engine_dialog.cc.orig	2008-01-15 03:58:38.000000000 +0100
+++ gtk2_ardour/engine_dialog.cc	2008-01-15 22:30:06.000000000 +0100
@@ -12,7 +12,7 @@
 #include <CoreFoundation/CFString.h>
 #include <sys/param.h>
 #include <mach-o/dyld.h>
-#else
+#elif !defined(__FreeBSD__)
 #include <alsa/asoundlib.h>
 #endif
 
@@ -113,7 +113,9 @@
 #ifdef __APPLE__
 	strings.push_back (X_("CoreAudio"));
 #else
+#ifndef __FreeBSD__
 	strings.push_back (X_("ALSA"));
+#endif
 	strings.push_back (X_("OSS"));
 	strings.push_back (X_("FFADO"));
 #endif
@@ -158,7 +160,7 @@
 	basic_packer.attach (period_size_combo, 1, 2, row, row + 1, FILL|EXPAND, (AttachOptions) 0);
 	row++;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 	label = manage (new Label (_("Number of buffers")));
 	basic_packer.attach (*label, 0, 1, row, row + 1, FILL|EXPAND, (AttachOptions) 0);
 	basic_packer.attach (periods_spinner, 1, 2, row, row + 1, FILL|EXPAND, (AttachOptions) 0);
@@ -179,7 +181,7 @@
 	row++;
 	/* no audio mode with CoreAudio, its duplex or nuthin' */
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 	label = manage (new Label (_("Audio Mode")));
 	basic_packer.attach (*label, 0, 1, row, row + 1, FILL|EXPAND, (AttachOptions) 0);
 	basic_packer.attach (audio_mode_combo, 1, 2, row, row + 1, FILL|EXPAND, (AttachOptions) 0);
@@ -218,7 +220,7 @@
 	realtime_button.signal_toggled().connect (mem_fun (*this, &EngineControl::realtime_changed));
 	realtime_changed ();
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 	label = manage (new Label (_("Realtime Priority")));
 	label->set_alignment (1.0, 0.5);
 	options_packer.attach (*label, 0, 1, row, row + 1, FILL|EXPAND, (AttachOptions) 0);
@@ -268,7 +270,7 @@
 	options_packer.attach (*label, 0, 1, row, row + 1, FILL|EXPAND, (AttachOptions) 0);
 	++row;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 	label = manage (new Label (_("Dither")));	
 	label->set_alignment (1.0, 0.5);
 	options_packer.attach (dither_mode_combo, 1, 2, row, row + 1, FILL|EXPAND, AttachOptions(0));
@@ -299,7 +301,7 @@
 	device_packer.set_spacings (6);
 	row = 0;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 	label = manage (new Label (_("Input device")));
 	label->set_alignment (1.0, 0.5);
 	device_packer.attach (*label, 0, 1, row, row+1, FILL|EXPAND, (AttachOptions) 0);
@@ -568,7 +570,7 @@
 void
 EngineControl::realtime_changed ()
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 	priority_spinner.set_sensitive (realtime_button.get_active());
 #endif
 }
@@ -584,8 +586,10 @@
 #endif
 
 #ifndef __APPLE__
+#ifndef __FreeBSD__
 	} else if (driver == "ALSA") {
 		devices[driver] = enumerate_alsa_devices ();
+#endif
 	} else if (driver == "FFADO") {
 		devices[driver] = enumerate_ffado_devices ();
 	} else if (driver == "OSS") {
@@ -712,6 +716,7 @@
 	return devs;
 }
 #else
+#ifndef __FreeBSD__
 vector<string>
 EngineControl::enumerate_alsa_devices ()
 {
@@ -772,6 +777,7 @@
 
 	return devs;
 }
+#endif
 
 vector<string>
 EngineControl::enumerate_ffado_devices ()
@@ -860,7 +866,7 @@
 EngineControl::redisplay_latency ()
 {
 	uint32_t rate = get_rate();
-#ifdef __APPLE_
+#if defined(__APPLE_) || defined(__FreeBSD__)
 	float periods = 2;
 #else
 	float periods = periods_adjustment.get_value();
