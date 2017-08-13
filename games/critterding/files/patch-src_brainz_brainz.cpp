brainz.cpp: In member function 'void Brainz::processTillAnswer()':
brainz.cpp:140:24: error: cannot convert 'bool' to 'bool*' in assignment
    Outputs[i].output = false;
--- src/brainz/brainz.cpp.orig	2017-07-28 12:12:16 UTC
+++ src/brainz/brainz.cpp
@@ -137,7 +137,7 @@ Brainz::Brainz()
 	
 		// clear Motor Outputs
 		for ( unsigned int i=0; i < numberOfOutputs; i++ )
-			Outputs[i].output = false;
+			*Outputs[i].output = false;
 	
 		// clear Neurons
 		for ( unsigned int i=0; i < totalNeurons; i++ )
