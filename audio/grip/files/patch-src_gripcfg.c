Adjust the encoder list to contain only those we have ports for.
Move oggenc to the beginning of the list since it is the default and to
prevent future offset errors if other encoders are added or removed.

--- src/gripcfg.c.orig	2018-04-06 23:41:51 UTC
+++ src/gripcfg.c
@@ -47,16 +47,9 @@ static Ripper ripper_defaults[]={
   {"",""}
 };
 
-static MP3Encoder encoder_defaults[]={{"bladeenc","-%b -QUIT %w %m","mp3"},
+static MP3Encoder encoder_defaults[]={{"oggenc","-o %m -a %a -l %d -t %n -b %b -N %t -G %G -d %y %w","ogg"},
 				      {"lame","-h --add-id3v2 --tt \"%n\" --ta \"%a\" --tl \"%d\" --ty \"%y\" --tn \"%t\" --tg \"%G\" -b %b %w %m","mp3"},
-				      {"l3enc","-br %b %w %m","mp3"},
-				      {"xingmp3enc","-B %b -Q %w","mp3"},
-				      {"mp3encode","-p 2 -l 3 -b %b %w %m",
-				       "mp3"},
-				      {"gogo","-b %b %w %m","mp3"},
-				      {"oggenc",
-				       "-o %m -a %a -l %d -t %n -b %b -N %t -G %G -d %y %w",
-				       "ogg"},
+				      {"faac","--no-midside -w -q 100 --artist %a --album %d --track %t --title %n --year %y --genre %g -b %b %w -o %m", "m4a"},
 				      {"flac","--best --replay-gain -T title=\"%n\" -T artist=\"%a\" -T album=\"%d\" -T date=\"%y\" -T tracknumber=\"%t\" -T genre=\"%G\"  -o %m %w","flac"},
 				      {"other","",""},
 				      {"",""}
