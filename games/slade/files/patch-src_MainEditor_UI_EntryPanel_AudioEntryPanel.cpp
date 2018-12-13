--- src/MainEditor/UI/EntryPanel/AudioEntryPanel.cpp.orig	2018-11-25 00:21:04 UTC
+++ src/MainEditor/UI/EntryPanel/AudioEntryPanel.cpp
@@ -93,15 +93,17 @@ AudioEntryPanel::AudioEntryPanel(wxWindow* parent) :
 		LOG_MESSAGE(3, "Windows Media Player installed, using wxMediaCtrl");
 		media_ctrl_ = new wxMediaCtrl(this, -1);
 	}
-#else
+#elif wxUSE_MEDIACTRL
 	// Create wxMediaCtrl
 	media_ctrl_ = new wxMediaCtrl(this, -1);
+#else
+	LOG_MESSAGE(1, "wxWidgets is built without media support, MP3 playback disabled.");
 #endif
 
 	// Setup sizer
 	wxGridBagSizer* sizer_gb = new wxGridBagSizer(UI::pad(), UI::pad());
 	sizer_main_->AddStretchSpacer();
-#ifndef __WXOSX__
+#if wxUSE_MEDIACTRL && !defined(__WXOSX__)
 	if (media_ctrl_) sizer_main_->Add(media_ctrl_, 0);
 #endif
 	sizer_main_->Add(sizer_gb, 0, wxALIGN_CENTER);
@@ -163,13 +165,17 @@ AudioEntryPanel::AudioEntryPanel(wxWindow* parent) :
 	sound_->setVolume(snd_volume);
 	music_->setVolume(snd_volume);
 	theMIDIPlayer->setVolume(snd_volume);
+#if wxUSE_MEDIACTRL
 	if (media_ctrl_) media_ctrl_->SetVolume(snd_volume*0.01);
+#endif
 	mod_->setVolume(snd_volume);
 	//theGMEPlayer->setVolume(snd_volume);
 	//theOPLPlayer->setVolume(snd_volume);
 
 	// Disable general entrypanel buttons
+#if wxUSE_MEDIACTRL
 	if (media_ctrl_) media_ctrl_->Show(false);
+#endif
 	toolbar_->Show(false);
 
 	// Bind events
@@ -533,6 +539,7 @@ bool AudioEntryPanel::openMod(MemChunk& data)
 // ----------------------------------------------------------------------------
 bool AudioEntryPanel::openMedia(string filename)
 {
+#if wxUSE_MEDIACTRL
 	// Attempt to open with wxMediaCtrl
 	if (media_ctrl_ && media_ctrl_->Load(filename))
 	{
@@ -547,6 +554,7 @@ bool AudioEntryPanel::openMedia(string filename)
 
 		return true;
 	}
+#endif
 	
 	return false;
 }
@@ -571,8 +579,10 @@ void AudioEntryPanel::startStream()
 		mod_->play(); break;
 	case MIDI:
 		theMIDIPlayer->play(); break;
+#if wxUSE_MEDIACTRL
 	case Media:
 		if (media_ctrl_) media_ctrl_->Play(); break;
+#endif
 	default:
 		break;
 	}
@@ -595,8 +605,10 @@ void AudioEntryPanel::stopStream()
 		mod_->pause(); break;
 	case MIDI:
 		theMIDIPlayer->pause();	break;
+#if wxUSE_MEDIACTRL
 	case Media:
 		if (media_ctrl_) media_ctrl_->Pause(); break;
+#endif
 	default:
 		break;
 	}
@@ -620,8 +632,10 @@ void AudioEntryPanel::resetStream()
 		mod_->stop(); break;
 	case MIDI:
 		theMIDIPlayer->stop(); break;
+#if wxUSE_MEDIACTRL
 	case Media:
 		if (media_ctrl_) media_ctrl_->Stop(); break;
+#endif
 	default:
 		break;
 	}
@@ -823,8 +837,10 @@ void AudioEntryPanel::onTimer(wxTimerEvent& e)
 		pos = mod_->getPlayingOffset().asMilliseconds(); break;
 	case MIDI:
 		pos = theMIDIPlayer->getPosition(); break;
+#if wxUSE_MEDIACTRL
 	case Media:
 		if (media_ctrl_) pos = media_ctrl_->Tell(); break;
+#endif
 	default:
 		break;
 	}
@@ -837,7 +853,9 @@ void AudioEntryPanel::onTimer(wxTimerEvent& e)
 	        (audio_type_ == Sound && sound_->getStatus() == sf::Sound::Stopped) ||
 	        (audio_type_ == Music && music_->getStatus() == sf::Sound::Stopped) ||
 			(audio_type_ == Mod && mod_->getStatus() == sf::Sound::Stopped) ||
+#if wxUSE_MEDIACTRL
 			(audio_type_ == Media && media_ctrl_ && media_ctrl_->GetState() == wxMEDIASTATE_STOPPED) ||
+#endif
 			(audio_type_ == MIDI && theMIDIPlayer && !theMIDIPlayer->isPlaying()))
 	{
 		timer_seek_->Stop();
@@ -863,8 +881,10 @@ void AudioEntryPanel::onSliderSeekChanged(wxCommandEve
 		mod_->setPlayingOffset(sf::milliseconds(slider_seek_->GetValue())); break;
 	case MIDI:
 		theMIDIPlayer->setPosition(slider_seek_->GetValue()); break;
+#if wxUSE_MEDIACTRL
 	case Media:
 		if (media_ctrl_) media_ctrl_->Seek(slider_seek_->GetValue()); break;
+#endif
 	default:
 		break;
 	}
@@ -887,8 +907,10 @@ void AudioEntryPanel::onSliderVolumeChanged(wxCommandE
 		music_->setVolume(snd_volume); break;
 	case MIDI:
 		theMIDIPlayer->setVolume(snd_volume); break;
+#if wxUSE_MEDIACTRL
 	case Media:
 		if (media_ctrl_) media_ctrl_->SetVolume(snd_volume*0.01); break;
+#endif
 	case Mod:
 		mod_->setVolume(snd_volume); break;
 	default:
