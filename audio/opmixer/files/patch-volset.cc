$FreeBSD$

--- volset.cc.orig	Mon May 21 19:35:48 2001
+++ volset.cc	Thu May 22 15:00:39 2003
@@ -22,6 +22,6 @@
     int pcmvol = atoi(argv[2]);
     myMixer->SetLevel("vol",mainvol);
     myMixer->SetLevel("pcm",pcmvol);
-    std::cout << "Main : " << mainvol << " PCM : " << pcmvol << endl;
+    std::cout << "Main : " << mainvol << " PCM : " << pcmvol << std::endl;
   };
 };
