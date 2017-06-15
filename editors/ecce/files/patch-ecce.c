--- ecce.c.orig	2016-09-11 21:27:36 UTC
+++ ecce.c
@@ -12,6 +12,9 @@
 #include <ctype.h>
 #include <signal.h>
 #include <errno.h>
+#include <sys/types.h>
+#include <unistd.h>
+#include <sys/stat.h>
 
 #ifdef WANT_UTF8
 /* EXPERIMENTAL SUPPORT FOR UTF-8 */
@@ -47,7 +50,7 @@ typedef char ecce_char;
 
 /**************************************************************************/
 
-#define NOTE_FILE "/tmp/Note0"
+#define NOTE_FILE "/tmp/ecceNote0%06d"
               /* Name of temp file for multiple contexts - system dependant. */
               /* Something like "/tmp/Note%c" would be a small improvement,  */
               /* but using a proper function like tmpnam() would be best.    */
@@ -61,7 +64,7 @@ typedef char ecce_char;
               /* moving this to sourceforge.                                 */
 
 
-#define CONTEXT_OFFSET (strlen(NOTE_FILE)-1)
+#define CONTEXT_OFFSET 13
               /* Index of variable part in name above (i.e. of '0')         */
 
 static char *ProgName = NULL;
@@ -400,8 +403,7 @@ static int symtype[256] = {
 };
 
 static int sym_type(ecce_char c) {
-  if ((0 <= c) && (c <= 255)) return symtype[(unsigned int)c];
-  return err;
+  return symtype[(unsigned int)c];
 }
 
 static cindex a;
@@ -412,7 +414,7 @@ static FILE *tty_out;
 static FILE *log_out;
 
 static ecce_int *com;
-static int  *link;
+static int  *xlink;
 static ecce_char *text;
 static long *num;
 static long *lim;
@@ -442,7 +444,8 @@ int main(int argc, char **argv) {
   char *locale = setlocale(LC_ALL, "");
 #endif
 
-  backup_save = tmpnam(backup_save_buf);
+  sprintf(backup_save_buf, "/tmp/eccesave%06d", getpid());
+  backup_save = backup_save_buf;
 
   ProgName = argv[0];
   s = strrchr(ProgName, '/');
@@ -596,7 +599,7 @@ void init_globals (void) {
    note_file = malloc (Max_parameter+1);
 
    com  = (ecce_int *) malloc ((Max_command_units+1)*sizeof(ecce_int));
-   link = (int *) malloc ((Max_command_units+1)*sizeof(int));
+   xlink = (int *) malloc ((Max_command_units+1)*sizeof(int));
    text = (ecce_char *) malloc ((Max_command_units+1) * sizeof(ecce_char));
 
    num = (long *) malloc ((Max_command_units+1)*sizeof(long));
@@ -605,7 +608,7 @@ void init_globals (void) {
    com_prompt = malloc (Max_prompt_length+1);
 
    if (a == NULL || note_file == NULL || com == NULL ||
-    link == NULL || text == NULL || num == NULL || lim == NULL ||
+    xlink == NULL || text == NULL || num == NULL || lim == NULL ||
     com_prompt == NULL) {
       fprintf (stderr, "Unable to claim buffer space\n");
       free_buffers();
@@ -628,7 +631,7 @@ void init_globals (void) {
    pending_sym = '\n';
    blank_line = TRUE;
 
-   (void)strcpy (note_file, NOTE_FILE);
+   sprintf (note_file, NOTE_FILE, getpid());
    noted = NULL;
    changes = 0;
    in_second = FALSE;
@@ -640,7 +643,7 @@ void free_buffers (void) { /* only neede
   if (lim) free (lim); lim = NULL;
   if (num) free (num); num = NULL;
   if (text) free (text); text = NULL;
-  if (link) free (link); link = NULL;
+  if (xlink) free (xlink); xlink = NULL;
   if (com) free (com); com = NULL;
   if (com_prompt) free (com_prompt); com_prompt = NULL;
   if (note_file) free (note_file); note_file = NULL;
@@ -820,7 +823,9 @@ void percent (ecce_int Command_sym) {
            the edit and writing out the file.  This is a quick hack: I
            should change this and the copy in percent('S') so that both
            share the same subroutine ensure_main_edit() *****************/
+            int oldmask = umask (0077);
             FILE *sec_out = fopen (note_file, "wb");
+            umask(oldmask);
             (void)strcpy (com_prompt, ">");
             if (sec_out == NULL) {
                (void) fail_with ("Cannot save context", ' ');
@@ -851,8 +856,10 @@ void percent (ecce_int Command_sym) {
  */
          }  /* End of copied bit */
          if (Command_sym == 'c') {
+            int oldmask = umask(0077);
             parameter[inoutlog] = backup_save;
             main_out = fopen (parameter[inoutlog], "wb");
+            umask(oldmask);
             if (main_out == NULL) {
                fprintf(stderr,
                        "Sorry - I can't save your edit (even %s failed)\n", backup_save);
@@ -865,10 +872,12 @@ void percent (ecce_int Command_sym) {
             else
                main_out = fopen (parameter[inoutlog], "wb");
             if (main_out == NULL) {
+               int oldmask = umask(0077);
                fprintf (stderr,
                         "Can't create \"%s\" - attempting to save to %s instead\n",
                         parameter[inoutlog], backup_save);
                main_out = fopen (backup_save, "w");
+               umask(oldmask);
                if (main_out == NULL) {
                  fprintf(stderr, "Cannot save file at all.  Giving up.  Sorry!\n");
                  exit(1);
@@ -947,7 +956,9 @@ void percent (ecce_int Command_sym) {
          pending_sym = '\n';
          note_file[CONTEXT_OFFSET] = note_sec;
          if (in_second) {
+            int oldmask = umask(0077);
             FILE *sec_out = fopen (note_file, "wb");
+            umask(oldmask);
             (void)strcpy (com_prompt, ">");
             if (sec_out == NULL) {
                (void) fail_with ("Cannot save context", ' ');
@@ -1028,14 +1039,14 @@ void unchain(void) {
    do {
       pointer = last_unit;
       if (pointer < 0) return;
-      last_unit = link[pointer];
-      link[pointer] = this_unit;
+      last_unit = xlink[pointer];
+      xlink[pointer] = this_unit;
    } while (com[pointer] != '(');
 }
 
 void stack(void) {
    com[this_unit]  = command;
-   link[this_unit] = pointer;
+   xlink[this_unit] = pointer;
    num[this_unit]  = repeat_count;
    lim[this_unit]  = limit;
    this_unit++;
@@ -1369,7 +1380,9 @@ void execute_command(void) {
          }
          note_file[CONTEXT_OFFSET] = lim[this_unit]+'0';
          {
+            int oldmask = umask(0077);
             FILE *note_out = fopen (note_file, "wb");
+            umask(oldmask);
             cindex p = noted;
 
             if (note_out == NULL) {
@@ -1628,7 +1641,7 @@ bool execute_unit (void) {
 
    command = com[this_unit];
    culprit = command;
-   pointer = link[this_unit];
+   pointer = xlink[this_unit];
 
    repeat_count = num[this_unit];
    for (;;) {  /* On repeats of this_unit */
@@ -1669,7 +1682,7 @@ bool execute_unit (void) {
             switch (command) {
 
                case '(':
-                  this_unit = link[this_unit];
+                  this_unit = xlink[this_unit];
                   break; /* Skip over (...) as if it were single command. */
 
                case ',':
