/*
 *  @(#) MPEG Audio Player maplay 1.2, last edit of this file: 6/23/94 13:02:49
 *  @(#) Copyright (C) 1993, 1994 Tobias Bading (bading@cs.tu-berlin.de)
 *  @(#) Berlin University of Technology
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


This is the README file of the MPEG Audio Player maplay, Version 1.2.
Besides this file, you should now own a copy of the following files:

  ANNOUNCEMENT		the announcement for this release
  INSTALL		infos about compiling and installing the program
  COPYING		the GNU General Public License
  Makefile		a makefile
  configuration.sh	a shell script used by the makefile

and the source files

  all.h			maplay.cc		subband_layer_1.h
  crc.cc		obuffer.cc		subband_layer_2.cc
  crc.h			obuffer.h		subband_layer_2.h
  header.cc		scalefactors.cc		synthesis_filter.cc
  header.h		scalefactors.h		synthesis_filter.h
  ibitstream.cc		subband.h		ulaw.cc
  ibitstream.h		subband_layer_1.cc	ulaw.h

-------------------------------------------------------------------------------

0) Introduction

MPEG is a standard created by the ISO (International Organization for
Standardization) and the IEC (International Electrotechnical Commission).
The full name of this standard is "ISO/IEC DIS 11172: Information
Technology - Coding of moving pictures and associated audio for digital
storage media ut to about 1.5 Mbit/s". As the name already states,
it deals with digital video and audio. The video part of this standard has
inspired many people to write decoders and a few encoders for it.
Best known should be the Berkeley player. Players for the audio part on
the other hand are very rare. The ones I know are the XING player for Windoze
and a sample implementation of the ISO, which also includes an encoder.

The audio part of the MPEG standard specifies three layers, whereat each
layer specifies its own file format. All three layers are using similar
audio coding techniques, but they vary in efficiency and complexity.
Layer I needs the fewest calculation time for en-/decoding a stream, layer III
the most. But a layer I MPEG audio stream is bigger than a layer III stream
at the same quality. This program is able to decode and play only layer I
and II streams, layer III is not supported (yet?!?).

Like the MPEG video standard, the audio part also uses a lossy compression
algorithm, which means that you can't get back 100% the original from a
MPEG audio stream. Layer II MPEG audio streams are compressed by ratios
from 1:3 up to 1:24 compared to raw PCM data, like on an audio CD.
But the quality is still very (very) near to the original at ratios between
1:5 and 1:12. You'll love it... :-)

-------------------------------------------------------------------------------

1) What does maplay?

maplay version 1.2 is the second release of my MPEG audio player/decoder.
It decodes layer I and layer II MPEG audio streams and plays them
using a CD-quality audio device. Currently supported devices are the
dbri device of SPARC 10 computers and the audio ports of Silicon
Graphics Indigo machines. Thanks to Louis P. Kruger (lpkruger@phoenix.
Princeton.EDU), maplay 1.2 can also use the /dev/dsp device under Linux.
Louis has tested it with the Pro Audio Spectrum 16 soundcard. Sound Blaster 16
and Gravis Ultrasound cards should also work, but a bug in the dsp driver
prevents stereo playback on Gravis Ultrasound cards. An amd device of a
SPARC 2/IPX/... machine can be used, too, but this device is only capable of
producing audio output at 8 kHz in u-law format, which sounds like transmitted
through a telephone. Other audio device are not supported directly, but can be
used with the "decode to stdout" option and an audio format converter.
Besides it shouldn't be a problem to adapt the program to other audio devices.

The player supports all modes, which are single channel, stereo,
joint stereo and dual channel, and all bitrates except free mode.
The missing free mode support should not be a problem for now,
because I haven't seen such a stream yet.

maplay needs approximately 46% CPU time on SPARC 10/40 machines and 50%
on Indigos for realtime stereo playback of a 44.1 kHz 128 kbit/s stream.
Single channel playback needs about the half CPU time. On a SPARCstation IPX,
maplay needs about 43% CPU time for realtime mono playback. Stereo playback
is not possible via an amd device.

Besides realtime playing of audio streams, maplay can decode streams to
stdout for further conversions. The output consists of 16 bit signed PCM
values. For stereo streams, the values are interleaved, which means that
a value for the left channel is followed by a value for the right channel
and so on. If maplay has been compiled for u-law output, the output consists
of 8 bit u-law samples at a rate of 8 kHz, no matter what frequency the stream
uses.

-------------------------------------------------------------------------------

2) How to create a maplay binary?

Please read the install file for this topic.

-------------------------------------------------------------------------------

3) How to start the program?

For a quick mono test enter "./maplay -v -l filename", where filename is the
name of an audio stream, like "things.mp2". This stream has been posted along
with the sources and is the beginning of Roxette's song "Things Will Never Be
The Same". It is coded in joint stereo mode with 128 kbit/s, which is a
compression ratio of 1:11. If the output is ok, you can test stereo playback
by leaving out the -l option. If the stereo output stutters, the problem is
not enough free CPU time in most cases. Stereo output is not possible when
using an amd u-law device. If maplay shows error messages like
"ioctl AUDIO_GETDEV on /dev/audio: ..."
and maplay was compiled for u-law output, please try out the -amd option.
This option forces maplay to treat /dev/audio as an amd device and may be
required on SPARC clones.

To convert a MPEG audio stream into other audio formats, you can use
"maplay -v -s filename | your_converter". Unfortunately, I can't be of much
help for you to find such a converter. The only good converter I know is the
"soundfiler" on Indigos. But if you would have an Indigo, you wouldn't need a
converter...

-------------------------------------------------------------------------------

4) Command line options

maplay [-v] [-s] [-l] [-r] [-us] [-uh] [-ul] [-amd] [-c] [-f ushort] filename

with these options:
  filename	filename of a MPEG audio stream or - for stdin
  -h		short help
  -v		verbose mode
		You will get information about the stream, like mode, bitrate,
		copyright etc., if you use this option.
  -s		stdout mode
		This option tells the program to decode the stream to stdout.
		The created output contains 16 bit signed PCM samples. If the
		binary has been compiled for 8 kHz u-law format usage, the
		output consists of 8 bit u-law samples at a 8 kHz rate. If the
		stream is in stereo mode, the samples of both channels are
		interleaved, the sample for the left channel first.
  -l		maplay decodes (and plays) the left channel of stereo streams
		only. This option halves the required CPU time.
  -r		Same as above, but decodes the right channel only
  -us, -uh	These options are available on SPARCstations only.
		They specify where the audio signal should be send to:
		"-us" means speaker and "-uh" headphone jack.
  -ul		This option is available on machines with the dbri device
		and sends the audio output to the line out jack.
  -amd		This option forces maplay to treat /dev/audio as an amd
		device. Use it if your SPARC clone has an amd device, but
		maplay doesn't recognize it. You may also use this option on a
		machine	with a dbri device, because the dbri device can also
		produce	u-law output. But I suggest to recompile the program
		without the ULAW define in this case to get the CD-quality
		output.
  -c		This option instructs the program to report filter range
		violations to stderr. Sometimes PCM values calculated by
		the synthesis filter exceede the 16 bit boundary and must
		be mapped to these boundaries. If you can hear this, you
		may use the next option.
  -f ushort	maplay uses this scalefactor instead of the default value 32768
		for the synthesis filter. You can reduce or eliminate range
		violations with this option, but lower scalefactor values
		reduce the signal-to-noise ratio, too. I can't remember when
		I used this option the last time myself.


Ok, that's all for now and this release,
I hope you like it,
                    Tobias Bading   (bading@cs.tu-berlin.de)
