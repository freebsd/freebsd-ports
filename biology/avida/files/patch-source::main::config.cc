--- ./source/main/config.cc.orig	Thu Oct 16 18:15:17 2003
+++ ./source/main/config.cc	Mon May 10 20:39:45 2004
@@ -132,15 +132,15 @@
   
   file_group->Add(default_dir, DEFAULT_DIR, "DEFAULT_DIR",
 		  "Directory in which config files are found");
-  file_group->Add(inst_filename, "inst_set.default", "INST_SET",
+  file_group->Add(inst_filename, "../work/inst_set.default", "INST_SET",
 		  "File containing instruction set");
-  file_group->Add(event_filename, "events.cfg", "EVENT_FILE",
+  file_group->Add(event_filename, "../work/events.cfg", "EVENT_FILE",
 		  "File containing list of events during run");
-  file_group->Add(analyze_filename, "analyze.cfg", "ANALYZE_FILE",
+  file_group->Add(analyze_filename, "../work/analyze.cfg", "ANALYZE_FILE",
 		  "File used for analysis mode");
-  file_group->Add(env_filename, "environment.cfg", "ENVIRONMENT_FILE",
+  file_group->Add(env_filename, "../work/environment.cfg", "ENVIRONMENT_FILE",
 		  "File that describes the environment");
-  file_group->Add(start_creature, "organism.default", "START_CREATURE",
+  file_group->Add(start_creature, "../work/organism.default", "START_CREATURE",
 		  "Organism to seed the soup");
 
   // Reproduction group.
