--- src-common/soundenginealsa.cxx.orig	2008-01-06 23:27:11.000000000 +0300
+++ src-common/soundenginealsa.cxx	2008-02-09 00:54:41.000000000 +0300
@@ -38,219 +38,46 @@
   complexfeed(0),
   enginefeed(0),
   activefeed(0),
-  handle(0),
-  periodsz(0),
   batchsize(0),
   framelag(lag),
   lpfilter(0.0)
 {
-  // test endiness
-  unsigned int scratch=0;
-  unsigned char *p = (unsigned char*) &scratch;
-  *p = 1;
-  assert(scratch == 1 || scratch == 16777216);
-  SoundClip::bigendian = (scratch == 16777216);
-  //fprintf(stderr,"soundenginealsa.cxx: %s endian\n", (SoundClip::bigendian)?"big":"little");
-
-  /* Open PCM device for playback. */
-  int rc = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
-  if (rc < 0)
-  {
-    fprintf(stderr, "unable to open pcm device: %s\n", snd_strerror(rc));
-    return;
-  }
-  snd_pcm_hw_params_t *params=0;
-
-  /* Allocate a hardware parameters object. */
-  snd_pcm_hw_params_alloca(&params);
-  /* Fill it in with default values. */
-  snd_pcm_hw_params_any(handle, params);
-  /* Set the desired hardware parameters. */
-  /* Interleaved mode */
-  snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
-  /* Signed 16-bit little-endian format */
-  snd_pcm_hw_params_set_format(handle, params, (SoundClip::bigendian)?SND_PCM_FORMAT_S16_BE:SND_PCM_FORMAT_S16_LE);
-  /* Two channels (stereo) */
-  snd_pcm_hw_params_set_channels(handle, params, 2);
-  /* 44100 bits/second sampling rate (CD quality) */
-  const unsigned int cd_rate = 44100;
-  unsigned int playback_sampling_rate = cd_rate;
-  int dir=-1; // round down actual rate, please.
-  snd_pcm_hw_params_set_rate_near(handle, params, &playback_sampling_rate, &dir);
-  if (playback_sampling_rate != cd_rate)
-  {
-    fprintf
-    (
-      stderr, 
-      "Asked for %dHz playback rate, but got %dHz\n",
-      cd_rate,
-      playback_sampling_rate
-    );
-  }
-
-  snd_pcm_uframes_t frames_in_buffer = framelag;
-  snd_pcm_uframes_t frames_in_period = framelag/8;
-
-  snd_pcm_hw_params_set_buffer_size_near(handle, params, &frames_in_buffer);
-  snd_pcm_hw_params_set_period_size_near(handle, params, &frames_in_period, &dir);
-
-  /* Write the parameters to the driver */
-  rc = snd_pcm_hw_params(handle, params);
-  if (rc < 0)
-  {
-    fprintf(stderr, "unable to set hw parameters: %s\n", snd_strerror(rc));
-    return;
-  }
-  snd_pcm_hw_params_get_period_size(params, &periodsz, &dir);
-  snd_pcm_hw_params_get_buffer_size(params, &buffersz);
-
-  fprintf(stderr,"soundenginealsa.cxx: period size SOLL-WERT %d, IST-WERT %d\n", framelag/8, (int) periodsz);
-  fprintf(stderr,"soundenginealsa.cxx: buffer size SOLL-WERT %d, IST-WERT %d\n", framelag,   (int) buffersz);
-
-  if (buffersz % periodsz)
-    fprintf(stderr,"soundenginealsa.cxx: WARNING - buffersz is not a multiple of periodsz\n");
-
-  simplefeed  = new SoundFeedSimple(periodsz);
-  complexfeed = new SoundFeedComplex(periodsz);
-  modulatedfeed = new SoundFeedModulated(periodsz);
-  enginefeed = new SoundFeedEngine(periodsz);
-  activefeed = simplefeed;
-  opened = true;
 }
 
 
 SoundEngineAlsa::~SoundEngineAlsa()
 {
-  if (opened)
-  {
-    fprintf(stderr,"Closing down SoundEngineAlsa\n");
-    snd_pcm_drain(handle);
-    snd_pcm_close(handle);
-  }
 }
 
  
 void SoundEngineAlsa::Play(const std::string &fname, int delay, bool looping)
 {
-  activefeed->Paste(fname, delay, looping);
 }
 
 
 void SoundEngineAlsa::StopPlay(void)
 {
-  puts("NOT YET IMPLEMENTED");
 }
 
 
 void SoundEngineAlsa::SetMode(const std::string &modename)
 {
-  if (modename=="complex")
-  {
-    activefeed = complexfeed;
-    return;
-  }
-  if (modename=="simple")
-  {
-    activefeed = simplefeed;
-    return;
-  }
-  if (modename=="modulated")
-  {
-    activefeed = modulatedfeed;
-    return;
-  }
-  if (modename=="engine")
-  {
-    activefeed = enginefeed;
-    return;
-  }
-  if (modename=="none")
-  {
-    activefeed = 0;
-    return;
-  }
-  assert(0);
 }
 
 
 void SoundEngineAlsa::SetModulation(float freq, float ampl)
 {
-  modulatedfeed->SetModulation(freq, ampl);
-  complexfeed->SetModulation(freq, ampl);
-  enginefeed->SetModulation(freq, ampl);
 }
 
 
 void SoundEngineAlsa::SetLowPass(float f)
 {
-  lpfilter = f;
 }
 
 
 
 float SoundEngineAlsa::Sustain(void)
 {
-  if (!activefeed)
-    return 0.0;
-  snd_pcm_sframes_t delay;
-  int avail = snd_pcm_avail_update(handle);
-  int rc = snd_pcm_delay(handle, &delay);
-  if (rc<0)
-    snd_strerror(rc);
-  if (rc==-EPIPE)
-    fprintf(stderr,"soundenginealsa.cxx: EPIPE\n");
-  else
-    assert(!rc);
-
-  // We can only trust pcm_delay if the state is running.
-  snd_pcm_state_t pcm_state = snd_pcm_state(handle);
-  if (pcm_state != SND_PCM_STATE_RUNNING || delay<0)
-  {
-    delay=0;
-    if (pcm_state == SND_PCM_STATE_XRUN)
-      snd_pcm_prepare(handle);
-  }
-
-#if 0
-  if (delay<0)
-    fprintf(stderr,"delay=%d, avail=%d, periodsz=%d\n", (int) delay, (int) avail, (int) periodsz);
-#else
-  (void) avail;
-#endif
-
-  float fractiondone = activefeed->FractionDone(delay);
-
-  if (delay < framelag)
-  {
-    int todo = framelag - delay;
-#if 0
-    int cnt  = (todo + periodsz-1) / periodsz; // Use this with pulse audio (fedora)
-#else
-    int cnt  = todo / periodsz; // Use this with all other alsa implementations
-#endif
-    short *data = activefeed->Get(cnt);
-    if (cnt)
-    {
-      assert(data);
-      if (lpfilter>0.01)
-        low_pass_filter(data, cnt*periodsz, lpfilter);
-      rc = snd_pcm_writei(handle, data, cnt*periodsz);
-      assert(rc == -EPIPE || rc >= 0);
-      if (rc == -EPIPE)
-      {
-        snd_pcm_prepare(handle);
-        fprintf(stderr,"Underrrun!\n");
-      }
-      else
-        if (rc != (int) (cnt*periodsz))
-          fprintf(stderr, "short write, wrote %d frames instead of %d\n", rc, (int) periodsz);
-#if 0
-        else
-          fprintf(stderr, "wrote %d sound frames\n", rc);
-#endif
-    }
-  }
-  return fractiondone;
 }
 
 clipmap_t SoundClip::clips;
