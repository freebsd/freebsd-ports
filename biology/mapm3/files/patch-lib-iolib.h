--- lib/iolib.h.orig	1993-02-09 16:35:27 UTC
+++ lib/iolib.h
@@ -53,9 +53,9 @@ sprintf() can spew out some very large strings of char
 conditions. Assume its really only one (or maybe 2-3) lines. ps_ is similar, 
 but for internal use only by the functions in this library.
 
-Ln is a global input string side-effected by getln() and fgetln().
+Ln is a global input string side-effected by getln() and fgetln_().
 The pointer ln itself may be side-effected, (eg: by the token parsing
-routines) as it is reset during each call to getln() or fgetln().
+routines) as it is reset during each call to getln() or fgetln_().
 However, the string space used to hold the input line is reused, and
 any pointers into the ln string which you saved may point to trash
 after one of these calls. Ln is alloced for 2K chars, leaving lots of
@@ -66,7 +66,7 @@ processing on the output string, including trying to w
 word breaks, converting tabs to spaces (every 8 chars), buffering
 output (perhaps multiple lines!) and more. The do_fwrite() function does
 not do this. Similarly, the getln() function despace()es,
-lowercase()es, and filter()s its input, while fgetln(), input(), and
+lowercase()es, and filter()s its input, while fgetln_(), input(), and
 finput() functions do not [yes, it's a somewhat odd inconsistancy, but
 it's handy].
 
@@ -254,6 +254,14 @@ bool string_editor(); /* args: char *prompt, *str; int
    files! (The obvious exception is logging and input redirection, for which
    you should use the rather carefuly crafted routines described above!) */
 
+/* Mimics 'writable string' behaviour which wasn't problematic in some old
+   pre '89 code. GCC supported it for a long time via the -fwritable-strings
+   option. However, as of version 3.4, it was declared deprecated, and removed
+   in later versions. A lot of the code depends on this questionable behaviour,
+   so the following macro is used throughout this *BSD port. */
+#define WRS(s)  (char[]){(s)}
+
+
 bool make_filename(); /* args: char *name; int mode; char *extension; 
    This turns name into a perfectly valid file name, and returns TRUE if this
    was possible. The name may include a directory specification - otherwise it
@@ -277,7 +285,7 @@ FILE *open_file();  /* args: char *name, *mode; on fai
 #define APPEND "a"
 void close_file();  /* args: FILE *fp; */
 
-bool end_of_file(); /* args: FILE *fp; returns TRUE if finput() or fgetln()  
+bool end_of_file(); /* args: FILE *fp; returns TRUE if finput() or fgetln_()  
    will be able to grab a new line from the file. */
 bool end_of_text(); /* args: FILE *fp; Like an end-of-file test, except it also
   returns TRUE if rest of the file is white. As a side-effect, it will step
@@ -289,17 +297,17 @@ void do_fwrite(); /* args: FILE *fp; char *string; no 
 
 #define fpr(fp) fprint(fp,ps)
 #define fwp(fp) fwrite(fp,ps)
-#define fnl(fp) fwrite(fp,"\n")
+#define fnl(fp) fwrite(fp,WRS("\n"))
 
 void finput();  /* args: FILE *fp; char *str; int max_input_chars; */
-void fgetln();  /* args: FILE *fp; side-effects global char *ln; 
-   Finput() and fgetln() both return a filter()ed line, and on end-of-file, the
+void fgetln_();  /* args: FILE *fp; side-effects global char *ln; 
+   Finput() and fgetln_() both return a filter()ed line, and on end-of-file, the
    ENDOFILE message is sent. Str must have room for max_input_chars+1 chars,
    and only max_input_chars-1 chars can usually be read, as a '\n' may be read
    in at the end and then deleted from the string. */
    
 void fgetdataln(); /* args: FILE *fp; int *count; side-effects global ln;
-   Like fgetln(), although this skips null (white) and comment lines (those
+   Like fgetln_(), although this skips null (white) and comment lines (those
    beginning with a '#' in the leftmost position. Also, each time any line is
    read from the file (data, null, or comment), *count is incremented. */
 		     
@@ -329,7 +337,7 @@ extern int num_file_args, dos_output, prep_it, append_
 
 extern char *ps_, *ln_;     /* input and output strings for the library only */
 extern char *linebuf;       /* tty output buffer */
-extern char *gotln, *lnptr; /* input line for getln(), fgetln() */
+extern char *gotln, *lnptr; /* input line for getln(), fgetln_() */
 
 extern FILE **in_fp;   /* the "stack" of input files for redirecting input */
 extern int redirs;
