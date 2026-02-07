Index: ADAMEm.c
@@ -737,7 +737,7 @@
  strcat (szJoystickFileName,"adamem.joy");
 #ifdef SOUND
  strcpy (szSoundFileName,ProgramPath);
- strcat (szSoundFileName,"adamem.snd");
+ strcat (szSoundFileName,"%%DATADIR%%/adamem.snd");
 #endif
  LoadConfigFile (szTempFileName,MainConfigFile);
  if (!ParseOptions(_argc,_argv))
