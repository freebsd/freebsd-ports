--- src/AudioEntryPanel.cpp.orig	2015-12-12 08:41:35 UTC
+++ src/AudioEntryPanel.cpp
@@ -89,15 +89,17 @@ AudioEntryPanel::AudioEntryPanel(wxWindo
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
@@ -144,13 +146,17 @@ AudioEntryPanel::AudioEntryPanel(wxWindo
 	sound.setVolume(snd_volume);
 	music.setVolume(snd_volume);
 	theMIDIPlayer->setVolume(snd_volume);
+#if wxUSE_MEDIACTRL
 	if (media_ctrl) media_ctrl->SetVolume(snd_volume*0.01);
+#endif
 	mod.setVolume(snd_volume);
 	//theGMEPlayer->setVolume(snd_volume);
 	//theOPLPlayer->setVolume(snd_volume);
 
 	// Disable general entrypanel buttons
+#if wxUSE_MEDIACTRL
 	if (media_ctrl) media_ctrl->Show(false);
+#endif
 	toolbar->Show(false);
 
 	// Bind events
@@ -497,6 +503,7 @@ bool AudioEntryPanel::openMod(MemChunk& 
 *******************************************************************/
 bool AudioEntryPanel::openMedia(string filename)
 {
+#if wxUSE_MEDIACTRL
 	// Attempt to open with wxMediaCtrl
 	if (media_ctrl && media_ctrl->Load(filename))
 	{
@@ -511,6 +518,7 @@ bool AudioEntryPanel::openMedia(string f
 
 		return true;
 	}
+#endif
 	
 	return false;
 }
@@ -533,8 +541,10 @@ void AudioEntryPanel::startStream()
 		mod.play(); break;
 	case AUTYPE_MIDI:
 		theMIDIPlayer->play(); break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) media_ctrl->Play(); break;
+#endif
 	}
 }
 
@@ -553,8 +563,10 @@ void AudioEntryPanel::stopStream()
 		mod.pause(); break;
 	case AUTYPE_MIDI:
 		theMIDIPlayer->pause();	break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) media_ctrl->Pause(); break;
+#endif
 	}
 }
 
@@ -574,8 +586,10 @@ void AudioEntryPanel::resetStream()
 		mod.stop(); break;
 	case AUTYPE_MIDI:
 		theMIDIPlayer->stop(); break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) media_ctrl->Stop(); break;
+#endif
 	}
 }
 
@@ -757,8 +771,10 @@ void AudioEntryPanel::onTimer(wxTimerEve
 		pos = mod.getPlayingOffset().asMilliseconds(); break;
 	case AUTYPE_MIDI:
 		pos = theMIDIPlayer->getPosition(); break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) pos = media_ctrl->Tell(); break;
+#endif
 	}
 
 	// Set slider
@@ -769,7 +785,9 @@ void AudioEntryPanel::onTimer(wxTimerEve
 	        (audio_type == AUTYPE_SOUND && sound.getStatus() == sf::Sound::Stopped) ||
 	        (audio_type == AUTYPE_MUSIC && music.getStatus() == sf::Sound::Stopped) ||
 			(audio_type == AUTYPE_MOD && mod.getStatus() == sf::Sound::Stopped) ||
+#if wxUSE_MEDIACTRL
 			(audio_type == AUTYPE_MEDIA && media_ctrl && media_ctrl->GetState() == wxMEDIASTATE_STOPPED) ||
+#endif
 			(audio_type == AUTYPE_MIDI && theMIDIPlayer && !theMIDIPlayer->isPlaying()))
 	{
 		timer_seek->Stop();
@@ -793,8 +811,10 @@ void AudioEntryPanel::onSliderSeekChange
 		mod.setPlayingOffset(sf::milliseconds(slider_seek->GetValue())); break;
 	case AUTYPE_MIDI:
 		theMIDIPlayer->setPosition(slider_seek->GetValue()); break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) media_ctrl->Seek(slider_seek->GetValue()); break;
+#endif
 	}
 }
 
@@ -813,8 +833,10 @@ void AudioEntryPanel::onSliderVolumeChan
 		music.setVolume(snd_volume); break;
 	case AUTYPE_MIDI:
 		theMIDIPlayer->setVolume(snd_volume); break;
+#if wxUSE_MEDIACTRL
 	case AUTYPE_MEDIA:
 		if (media_ctrl) media_ctrl->SetVolume(snd_volume*0.01); break;
+#endif
 	case AUTYPE_MOD:
 		mod.setVolume(snd_volume); break;
 	}
