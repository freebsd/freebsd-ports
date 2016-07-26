--- src/qsynthOptions.cpp.orig	2016-04-05 15:57:45 UTC
+++ src/qsynthOptions.cpp
@@ -172,11 +172,11 @@ void qsynthOptions::print_usage ( const 
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
@@ -479,7 +479,7 @@ void qsynthOptions::loadSetup ( qsynthSe
 	pSetup->iAudioBufSize    = m_settings.value("/AudioBufSize", 512).toInt();
 	pSetup->iAudioBufCount   = m_settings.value("/AudioBufCount", 8).toInt();
 #else
-	pSetup->sMidiDriver      = m_settings.value("/MidiDriver", "alsa_seq").toString();
+	pSetup->sMidiDriver      = m_settings.value("/MidiDriver", "jack").toString();
 	pSetup->sAudioDriver     = m_settings.value("/AudioDriver", "jack").toString();
 	pSetup->iAudioBufSize    = m_settings.value("/AudioBufSize", 64).toInt();
 	pSetup->iAudioBufCount   = m_settings.value("/AudioBufCount", 2).toInt();
