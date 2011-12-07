--- plugins/midi_import/portsmf/allegrord.cpp	2011-07-02 13:14:01.000000000 +0000
+++ plugins/midi_import/portsmf/allegrord.cpp.new	2011-09-30 11:37:34.000000000 +0000
@@ -109,19 +109,19 @@
     if (attributes) {
         Alg_parameters_ptr a;
         bool in_seconds = seq->get_units_are_seconds();
-        if (a = Alg_parameters::remove_key(&attributes, "tempor")) {
+        if ((a = Alg_parameters::remove_key(&attributes, (char *)"tempor"))) {
             double tempo = a->parm.r;
             seq->insert_tempo(tempo, seq->get_time_map()->time_to_beat(time));
         }
-        if (a = Alg_parameters::remove_key(&attributes, "beatr")) {
+        if ((a = Alg_parameters::remove_key(&attributes, (char *)"beatr"))) {
             double beat = a->parm.r;
             seq->insert_beat(time, beat);
         }
-        if (a = Alg_parameters::remove_key(&attributes, "timesig_numr")) {
+        if ((a = Alg_parameters::remove_key(&attributes, (char *)"timesig_numr"))) {
             tsnum = a->parm.r;
             ts_flag = true;
         }
-        if (a = Alg_parameters::remove_key(&attributes, "timesig_denr")) {
+        if ((a = Alg_parameters::remove_key(&attributes, (char *)"timesig_denr"))) {
             tsden = a->parm.r;
             ts_flag = true;
         }
@@ -210,56 +210,56 @@
                 }
                 if (first == 'V') {
                     if (voice_flag) {
-                        parse_error(field, 0, "Voice specified twice");
+                        parse_error(field, 0, (char *)"Voice specified twice");
                     } else {
                         voice = parse_chan(field);
                     }
                     voice_flag = true;
                 } else if (first == 'T') {
                     if (time_flag) {
-                        parse_error(field, 0, "Time specified twice");
+                        parse_error(field, 0, (char *)"Time specified twice");
                     } else {
                         time = parse_dur(field, 0.0);
                     }
                     time_flag = true;
                 } else if (first == 'N') {
                     if (next_flag) {
-                        parse_error(field, 0, "Next specified twice");
+                        parse_error(field, 0, (char *)"Next specified twice");
                     } else {
                         next = parse_dur(field, time);
                     }
                     next_flag = true;
                 } else if (first == 'K') {
                     if (new_key_flag) {
-                        parse_error(field, 0, "Key specified twice");
+                        parse_error(field, 0, (char *)"Key specified twice");
                     } else {
                         new_key = parse_key(field);
                         new_key_flag = true;
                     }
                 } else if (first == 'L') {
                     if (loud_flag) {
-                        parse_error(field, 0, "Loudness specified twice");
+                        parse_error(field, 0, (char *)"Loudness specified twice");
                     } else {
                         loud = parse_loud(field);
                     }
                     loud_flag = true;
                 } else if (first == 'P') {
                     if (new_pitch_flag) {
-                        parse_error(field, 0, "Pitch specified twice");
+                        parse_error(field, 0, (char *)"Pitch specified twice");
                     } else {
                         new_pitch = parse_pitch(field);
                         new_pitch_flag = true;
                     }
                 } else if (first == 'U') {
                     if (dur_flag) {
-                        parse_error(field, 0, "Dur specified twice");
+                        parse_error(field, 0, (char *)"Dur specified twice");
                     } else {
                         dur = parse_dur(field, time);
                         dur_flag = true;
                     }
                 } else if (strchr("SIQHW", first)) {
                     if (dur_flag) {
-                        parse_error(field, 0, "Dur specified twice");
+                        parse_error(field, 0, (char *)"Dur specified twice");
                     } else {
                         // prepend 'U' to field, copy EOS too
                         field.insert(0, 1, 'U');
@@ -268,7 +268,7 @@
                     }
                 } else if (strchr("ABCDEFG", first)) {
                     if (new_pitch_flag) {
-                        parse_error(field, 0, "Pitch specified twice");
+                        parse_error(field, 0, (char *)"Pitch specified twice");
                     } else {
                         // prepend 'P' to field
                         field.insert(0, 1, 'P');
@@ -283,7 +283,7 @@
                         parm.s = NULL; // protect string from deletion by destructor
                     }
                 } else {
-                    parse_error(field, 0, "Unknown field");
+                    parse_error(field, 0, (char *)"Unknown field");
                 }
 
                 if (error_flag) {
@@ -404,11 +404,11 @@
 long Alg_reader::parse_chan(string &field)
 {
     const char *int_string = field.c_str() + 1;
-    char *msg = "Integer or - expected";
+    char *msg = (char *)"Integer or - expected";
     const char *p = int_string;
     char c;
     // check that all chars in int_string are digits or '-':
-    while (c = *p++) {
+    while ((c = *p++)) {
         if (!isdigit(c) && c != '-') {
             parse_error(field, p - field.c_str() - 1, msg);
             return 0;
@@ -431,8 +431,8 @@
 long Alg_reader::parse_int(string &field)
 {
     const char *int_string = field.c_str() + 1;
-    char *msg = "Integer expected";
-    const char *p = int_string;
+    char *msg = (char *)"Integer expected";
+    const char *p = int_string;
     char c;
     // check that all chars in int_string are digits:
     while (c = *p++) {
@@ -472,7 +472,7 @@
 
 double Alg_reader::parse_real(string &field)
 {
-    char *msg = "Real expected";
+    char *msg = (char *)"Real expected";
     int last = find_real_in(field, 1);
     string real_string = field.substr(1, last - 1);
     if (last <= 1 || last < (int) field.length()) {
@@ -501,8 +501,8 @@
 
 double Alg_reader::parse_dur(string &field, double base)
 {
-    char *msg = "Duration expected";
-    char *durs = "SIQHW";
+    char *msg = (char *)"Duration expected";
+    char *durs = (char *)"SIQHW";
     char *p;
     int last;
     double dur;
@@ -516,7 +516,7 @@
         // convert dur from seconds to beats
         dur = seq->get_time_map()->time_to_beat(base + dur) - 
               seq->get_time_map()->time_to_beat(base);
-    } else if (p = strchr(durs, toupper(field[1]))) {
+    } else if ((p = strchr(durs, toupper(field[1])))) {
         dur = duration_lookup[p - durs];
         last = 2;
     } else {
@@ -554,12 +554,12 @@
                 a_string, seq->get_time_map()->beat_to_time(
                         seq->get_time_map()->time_to_beat(base) + dur));
     }
-    parse_error(field, n, "Unexpected character in duration");
+    parse_error(field, n, (char *)"Unexpected character in duration");
     return dur;
 }
 
 struct loud_lookup_struct {
-    char *str;
+    char const *str;
     int val;
 } loud_lookup[] = { {"FFF", 127}, {"FF", 120}, {"F", 110}, {"MF", 100}, 
                     {"MP", 90}, {"P", 80}, {"PP", 70}, {"PPP", 60}, 
@@ -568,7 +568,7 @@
 
 double Alg_reader::parse_loud(string &field)
 {
-    char *msg = "Loudness expected";
+    char *msg = (char *)"Loudness expected";
     if (isdigit(field[1])) {
         return parse_int(field);
     } else {
@@ -594,14 +594,14 @@
 //
 long Alg_reader::parse_key(string &field)
 {
-    char *msg = "Pitch expected";
-    char *pitches = "ABCDEFG";
+    char *msg = (char *)"Pitch expected";
+    char *pitches = (char *)"ABCDEFG";
     char *p;
     if (isdigit(field[1])) {
         // This routine would not have been called if field = "P<number>"
         // so it must be "K<number>" so <number> must be an integer.
         return parse_int(field);
-    } else if (p = strchr(pitches, toupper(field[1]))) {
+    } else if ((p = strchr(pitches, toupper(field[1])))) {
         long key = key_lookup[p - pitches];
         key = parse_after_key(key, field, 2);
         return key;
@@ -629,7 +629,7 @@
         int oct = atoi(octave.c_str());
         return parse_after_key(key + oct * 12, field, last);
     }
-    parse_error(field, n, "Unexpected character in pitch");
+    parse_error(field, n, (char *)"Unexpected character in pitch");
     return key;
 }
 
@@ -654,7 +654,7 @@
                 param->set_attr(symbol_table.insert_string(attr.c_str()));
                 parse_val(param, field, i + 1);
             } else {
-                parse_error(field, 0, "attribute needs to end with typecode: i,a,r,s, or l");
+                parse_error(field, 0, (char *)"attribute needs to end with typecode: i,a,r,s, or l");
             }
             return !error_flag;
         }
@@ -708,7 +708,7 @@
             } else if (!period && s[pos] == '.') {
                 period = true;
             } else {
-                parse_error(s, pos, "Unexpected char in number");
+                parse_error(s, pos, (char *)"Unexpected char in number");
                 return false;
             }
             pos = pos + 1;
@@ -729,7 +729,7 @@
             }
         }
     } else {
-        parse_error(s, i, "invalid value");
+        parse_error(s, i, (char *)"invalid value");
         return false;
     }
     return true;
