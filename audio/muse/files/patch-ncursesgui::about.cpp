--- ncursesgui/about.cpp.orig	Thu May 30 22:56:45 2002
+++ ncursesgui/about.cpp	Mon Dec 22 00:47:55 2003
@@ -58,80 +58,80 @@
 	warning ("aboutbox::setitem()");
 	char src[8192];
 	snprintf (src, sizeof(src),
-"MuSE is a [ d y n e . o r g ] production! :)
-		
-MuSE <-------------------------------> Multiple Streaming Engine 
-MuSE is an application for the mixing, encoding, and streaming of sound:
-is an engine that can simultaniously mix up to 6 separate MP3 or OggVorbis
-audio files from the hard drive or the network, where each channel of 
-audio can be dynamicly adjusted for speed and volume plus a soundcard 
-line-in channel. The resulting stream can be played locally on the sound 
-card and/or encoded as an mp3 network stream to an icecast or shoutcast 
-server (ready to be mixed and played again by other muses... ;)
-
-MuSE has been created and is mantained by 
-Denis Rojo aka jaromil <jaromil@dyne.org>
-The GTK+ graphical user interface is developed by 
-nightolo <night@autistici.org>
-The ncurses user interface is developed by
-Luca Profico aka rubik <rubik@olografix.org>
-
-MuSE as it is now would have never existed without the contributions of:
-= Markus Seidl ( funda.ment.org ) for the idea of mixing and streaming 
-  multiple files
-= August Black ( aug.ment.org ) for the original graphical user interface
-= SERVUS.AT for trusting this project since the beginning and supporting it
-= PUBLIC VOICE Lab ( pvl.at ) for recently giving MuSE support and new 
-  horizons of use
-= Asbesto Molesto ( freaknet.org ) for the extensive testing and 
-  documentation
-= Alex, Rasty and Martinez ( ! ) for the good karma
-
-also BIG THANKS to:
-lobo, voyager, void, blicero, saiborg, the freaknet medialab, the ASCII 
-squat, henk, the imc-audio collective, jeff, the LOA hacklab, the TPO, 
-bundes & didi, indymedia italy, neural.it, the autistici.org collective, 
-mag-one, radio onda rossa and all the others i'm forgetting here!
-	
-MuSE redistributes, linking statically, the following libraries:
-= libmpeg by Woo-jae Jung (now mantained by Mikael Hedin)
-= libshout by Jack Moffit, Chad Armstrong and Scott Manley
-= libcdk by Mike Glover
-
-(refer to documentation included into subdirectories for more informations)
-
-MuSE can link dinamically to the following libraries:
-= libogg, libvorbis, libvorbisfile - www.xiph.org
-= glib, libgdk, libgtk - www.gtk.org
-= liblame - www.mp3dev.org/mp3
-= libX11, libXext - www.xfree86.org
-= other common GNU libraries
-
-MuSE sourcecode also got inspirations from:
-= stream mixer code by Scott Manley
-= buffered FIFO pipe code by Charles Samuels.
-
-
-MuSE is copyright (c) 2000, 2001, 2002 by Denis Rojo aka jaromil
-MuSE's GTK+ G.U.I. is (c) 2002 by nightolo
-MuSE's ncurses console U.I is (c) 2002 by Luca Profico aka rubik
-
-
-
----------------------------------------------------------------
-This source code is free software; you can redistribute it and/or
-modify it under the terms of the GNU Public License as published 
-by the Free Software Foundation; either version 2 of the License,
-or (at your option) any later version.
-
-This source code is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
-Please refer to the GNU Public License for more details.
-
-You should have received a copy of the GNU Public License along with
-this source code; if not, write to:
-Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
+"MuSE is a [ d y n e . o r g ] production! :)\n\
+		\n\
+MuSE <-------------------------------> Multiple Streaming Engine \n\
+MuSE is an application for the mixing, encoding, and streaming of sound:\n\
+is an engine that can simultaniously mix up to 6 separate MP3 or OggVorbis\n\
+audio files from the hard drive or the network, where each channel of \n\
+audio can be dynamicly adjusted for speed and volume plus a soundcard \n\
+line-in channel. The resulting stream can be played locally on the sound \n\
+card and/or encoded as an mp3 network stream to an icecast or shoutcast \n\
+server (ready to be mixed and played again by other muses... ;)\n\
+\n\
+MuSE has been created and is mantained by \n\
+Denis Rojo aka jaromil <jaromil@dyne.org>\n\
+The GTK+ graphical user interface is developed by \n\
+nightolo <night@autistici.org>\n\
+The ncurses user interface is developed by\n\
+Luca Profico aka rubik <rubik@olografix.org>\n\
+\n\
+MuSE as it is now would have never existed without the contributions of:\n\
+= Markus Seidl ( funda.ment.org ) for the idea of mixing and streaming \n\
+  multiple files\n\
+= August Black ( aug.ment.org ) for the original graphical user interface\n\
+= SERVUS.AT for trusting this project since the beginning and supporting it\n\
+= PUBLIC VOICE Lab ( pvl.at ) for recently giving MuSE support and new \n\
+  horizons of use\n\
+= Asbesto Molesto ( freaknet.org ) for the extensive testing and \n\
+  documentation\n\
+= Alex, Rasty and Martinez ( ! ) for the good karma\n\
+\n\
+also BIG THANKS to:\n\
+lobo, voyager, void, blicero, saiborg, the freaknet medialab, the ASCII \n\
+squat, henk, the imc-audio collective, jeff, the LOA hacklab, the TPO, \n\
+bundes & didi, indymedia italy, neural.it, the autistici.org collective, \n\
+mag-one, radio onda rossa and all the others i'm forgetting here!\n\
+	\n\
+MuSE redistributes, linking statically, the following libraries:\n\
+= libmpeg by Woo-jae Jung (now mantained by Mikael Hedin)\n\
+= libshout by Jack Moffit, Chad Armstrong and Scott Manley\n\
+= libcdk by Mike Glover\n\
+\n\
+(refer to documentation included into subdirectories for more informations)\n\
+\n\
+MuSE can link dinamically to the following libraries:\n\
+= libogg, libvorbis, libvorbisfile - www.xiph.org\n\
+= glib, libgdk, libgtk - www.gtk.org\n\
+= liblame - www.mp3dev.org/mp3\n\
+= libX11, libXext - www.xfree86.org\n\
+= other common GNU libraries\n\
+\n\
+MuSE sourcecode also got inspirations from:\n\
+= stream mixer code by Scott Manley\n\
+= buffered FIFO pipe code by Charles Samuels.\n\
+\n\
+\n\
+MuSE is copyright (c) 2000, 2001, 2002 by Denis Rojo aka jaromil\n\
+MuSE's GTK+ G.U.I. is (c) 2002 by nightolo\n\
+MuSE's ncurses console U.I is (c) 2002 by Luca Profico aka rubik\n\
+\n\
+\n\
+\n\
+---------------------------------------------------------------\n\
+This source code is free software; you can redistribute it and/or\n\
+modify it under the terms of the GNU Public License as published \n\
+by the Free Software Foundation; either version 2 of the License,\n\
+or (at your option) any later version.\n\
+\n\
+This source code is distributed in the hope that it will be useful,\n\
+but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
+Please refer to the GNU Public License for more details.\n\
+\n\
+You should have received a copy of the GNU Public License along with\n\
+this source code; if not, write to:\n\
+Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.\n\
 ");
 
 	item = splitstring(src);
