--- src/qsynthOptions.cpp.orig	2009-08-27 18:35:48.000000000 +0200
+++ src/qsynthOptions.cpp	2009-08-27 18:36:39.000000000 +0200
@@ -155,11 +155,11 @@ void qsynthOptions::print_usage ( const 
 	out << "  -n, --no-midi-in" + sEot +
 		QObject::tr("Don't create a midi driver to read MIDI input events [default = yes]") + sEol;
 	out << "  -m, --midi-driver=[label]" + sEot +
-		QObject::tr("The name of the midi driver to use [oss,alsa,alsa_seq,...]") + sEol;
+		QObject::tr("The name of the midi driver to use [jack,oss,...]") + sEol;
 	out << "  -K, --midi-channels=[num]" + sEot +
 		QObject::tr("The number of midi channels [default = 16]") + sEol;
 	out << "  -a, --audio-driver=[label]" + sEot +
-		QObject::tr("The audio driver [alsa,jack,oss,dsound,...]") + sEol;
+		QObject::tr("The audio driver [jack,oss,dsound,...]") + sEol;
 	out << "  -j, --connect-jack-outputs" + sEot +
 		QObject::tr("Attempt to connect the jack outputs to the physical ports") + sEol;
 	out << "  -L, --audio-channels=[num]" + sEot +
@@ -459,7 +459,7 @@ void qsynthOptions::loadSetup ( qsynthSe
     pSetup->iAudioBufSize    = m_settings.value("/AudioBufSize", 512).toInt();
     pSetup->iAudioBufCount   = m_settings.value("/AudioBufCount", 8).toInt();
 #else
-	pSetup->sMidiDriver      = m_settings.value("/MidiDriver", "alsa_seq").toString();
+	pSetup->sMidiDriver      = m_settings.value("/MidiDriver", "jack").toString();
     pSetup->sAudioDriver     = m_settings.value("/AudioDriver", "jack").toString();
     pSetup->iAudioBufSize    = m_settings.value("/AudioBufSize", 64).toInt();
     pSetup->iAudioBufCount   = m_settings.value("/AudioBufCount", 2).toInt();
