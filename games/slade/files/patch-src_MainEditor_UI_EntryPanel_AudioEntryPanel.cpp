--- src/MainEditor/UI/EntryPanel/AudioEntryPanel.cpp.orig	2016-02-28 02:57:06 UTC
+++ src/MainEditor/UI/EntryPanel/AudioEntryPanel.cpp
@@ -100,15 +100,17 @@ AudioEntryPanel::AudioEntryPanel(wxWindo
 		LOG_MESSAGE(3, "Windows Media Player installed, using wxMediaCtrl");
 		media_ctrl = new wxMediaCtrl(this, -1);
 	}
-#else
+#elif wxUSE_MEDIACTRL
 	// Create wxMediaCtrl
 	media_ctrl = new wxMediaCtrl(this, -1);
+#else
+	LOG_MESSAGE(1, "wxWidgets is built without media support, MP3 playback disabled.");
 #endif
 
 	// Setup sizer
 	wxGridBagSizer* sizer_gb = new wxGridBagSizer(4, 4);
 	sizer_main->AddStretchSpacer();
-#ifndef __WXOSX__
+#if wxUSE_MEDIACTRL && !defined(__WXOSX__)
 	if (media_ctrl) sizer_main->Add(media_ctrl, 0);
 #endif
 	sizer_main->Add(sizer_gb, 0, wxALIGN_CENTER);
@@ -155,13 +157,17 @@ AudioEntryPanel::AudioEntryPanel(wxWindo
 	sound->setVolume(snd_volume);
 	music->setVolume(snd_volume);
 	theMIDIPlayer->setVolume(snd_volume);
+#if wxUSE_MEDIACTRL
 	if (media_ctrl) media_ctrl->SetVolume(snd_volume*0.01);
+#endif
 	mod->setVolume(snd_volume);
 	//theGMEPlayer->setVolume(snd_volume);
 	//theOPLPlayer->setVolume(snd_volume);
 
 	// Disable general entrypanel buttons
+#if wxUSE_MEDIACTRL
 	if (media_ctrl) media_ctrl->Show(false);
+#endif
 	toolbar->Show(false);
 
 	// Bind events
@@ -513,6 +519,7 @@ bool AudioEntryPanel::openMod(MemChunk& 
 *******************************************************************/
 bool AudioEntryPanel::openMedia(string filename)
 {
+#if wxUSE_MEDIACTRL
 	// Attempt to open with wxMediaCtrl
 	if (media_ctrl && media_ctrl->Load(filename))
 	{
@@ -527,6 +534,7 @@ bool AudioEntryPanel::openMedia(string f
 
 		return true;
 	}
+#endif
 	
 	return false;
 }
@@ -549,8 +557,10 @@ void AudioEntryPanel::startStream()
 		mod->play(); break;
 	case AUTYPE_MIDI:
 		theMIDIPlayer->play(); break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) media_ctrl->Play(); break;
+#endif
 	}
 }
 
@@ -569,8 +579,10 @@ void AudioEntryPanel::stopStream()
 		mod->pause(); break;
 	case AUTYPE_MIDI:
 		theMIDIPlayer->pause();	break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) media_ctrl->Pause(); break;
+#endif
 	}
 }
 
@@ -590,8 +602,10 @@ void AudioEntryPanel::resetStream()
 		mod->stop(); break;
 	case AUTYPE_MIDI:
 		theMIDIPlayer->stop(); break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) media_ctrl->Stop(); break;
+#endif
 	}
 }
 
@@ -773,8 +787,10 @@ void AudioEntryPanel::onTimer(wxTimerEve
 		pos = mod->getPlayingOffset().asMilliseconds(); break;
 	case AUTYPE_MIDI:
 		pos = theMIDIPlayer->getPosition(); break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) pos = media_ctrl->Tell(); break;
+#endif
 	}
 
 	// Set slider
@@ -785,7 +801,9 @@ void AudioEntryPanel::onTimer(wxTimerEve
 	        (audio_type == AUTYPE_SOUND && sound->getStatus() == sf::Sound::Stopped) ||
 	        (audio_type == AUTYPE_MUSIC && music->getStatus() == sf::Sound::Stopped) ||
 			(audio_type == AUTYPE_MOD && mod->getStatus() == sf::Sound::Stopped) ||
+#if wxUSE_MEDIACTRL
 			(audio_type == AUTYPE_MEDIA && media_ctrl && media_ctrl->GetState() == wxMEDIASTATE_STOPPED) ||
+#endif
 			(audio_type == AUTYPE_MIDI && theMIDIPlayer && !theMIDIPlayer->isPlaying()))
 	{
 		timer_seek->Stop();
@@ -809,8 +827,10 @@ void AudioEntryPanel::onSliderSeekChange
 		mod->setPlayingOffset(sf::milliseconds(slider_seek->GetValue())); break;
 	case AUTYPE_MIDI:
 		theMIDIPlayer->setPosition(slider_seek->GetValue()); break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) media_ctrl->Seek(slider_seek->GetValue()); break;
+#endif
 	}
 }
 
@@ -829,8 +849,10 @@ void AudioEntryPanel::onSliderVolumeChan
 		music->setVolume(snd_volume); break;
 	case AUTYPE_MIDI:
 		theMIDIPlayer->setVolume(snd_volume); break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) media_ctrl->SetVolume(snd_volume*0.01); break;
+#endif
 	case AUTYPE_MOD:
 		mod->setVolume(snd_volume); break;
 	}
