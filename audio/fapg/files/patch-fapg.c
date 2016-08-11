--- fapg.c.orig	2015-02-02 18:27:58 UTC
+++ fapg.c
@@ -57,27 +57,27 @@
 
 int debug = 0;
 int format = FORMAT_M3U;
-char *genrelist = NULL;
-unsigned char *prefix = "";
-unsigned char *base = "";
-unsigned char *dir = "";
-unsigned char *hostname = "fritzserver.de";
+static char *genrelist = NULL;
+static char *prefix = "";
+static char *base = "";
+static char *dir = "";
+static const char *hostname = "fritzserver.de";
 // unsigned char *referal="/usr/local/bin/fapg-rss.sh";
-unsigned char *referal = NULL;
+static const char *referal = NULL;
 //int windows=0;
 int fromstdin = 0;
 int recursive = 0;
 int avoidhlinked = 0;
 int separator = '/';
-unsigned char *eol = "\n";
-unsigned char buffer[MAX];
+static const char *eol = "\n";
+static char buffer[MAX];
 
 int counter = 0;
 
-unsigned char artist[1024];
-unsigned char title[1024];
-unsigned char genrebuf[1024];
-unsigned char genre = 0;
+static char artist[1024];
+static char title[1024];
+static char genrebuf[1024];
+static unsigned char genre = 0;
 int duration;
 #define MP2ENC 1
 #define MP3ENC 2
@@ -87,7 +87,7 @@ int duration;
 #define WAVENC 6
 #define WMAENC 7
 
-char *magic[] = { NULL,
+static const char *magic[] = { NULL,
     "audio/mpeg", "audio/mpeg",
     "audio/mpeg", "audio/mpeg",
     "audio/ogg-vorbis", "audio/x-wav",
@@ -95,7 +95,7 @@ char *magic[] = { NULL,
     NULL
 };
 
-unsigned char unix2dos[] =
+static unsigned char unix2dos[] =
     { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
     16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
     32, 33, 70, 35, 36, 37, 38, 39, 40, 41, 82, 43, 44, 45, 46, 47,
@@ -126,7 +126,7 @@ unsigned char unix2dos[] =
 
 unsigned char *basemap;
 unsigned char *winorunix;
-unsigned char one2one[] =
+static unsigned char one2one[] =
     { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
     16, 17, 18, 19, 20, 21, 22, 23,
     24, 25, 26, 27, 28, 29, 30, 31,
@@ -160,7 +160,7 @@ unsigned char one2one[] =
     248, 249, 250, 251, 252, 253, 254, 255
 };                              /* identical mapping */
 
-unsigned char noand[256] =
+static unsigned char noand[256] =
     { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
     16, 17, 18, 19, 20, 21, 22, 23,
     24, 25, 26, 27, 28, 29, 30, 31,
@@ -194,7 +194,7 @@ unsigned char noand[256] =
     248, 249, 250, 251, 252, 253, 254, 255
 };                              /* only '&' is mapped to '+' */
 
-unsigned char *iso2web[256] = {
+static const char *iso2web[256] = {
     "%00", "%01", "%02", "%03", "%04", "%05", "%06", "%07",
     "%08", "%09", "%0a", "%0b", "%0c", "%0d", "%0e", "%0f",
     "%10", "%11", "%12", "%13", "%14", "%15", "%16", "%17",
@@ -308,7 +308,7 @@ void txxputnameoffset(const char *c)
     int pos = 0;
     int cnt = 0;
     char b;
-    unsigned char *prefx;
+    char *prefx;
 
     prefx = prefix;
 
@@ -344,7 +344,7 @@ void txxputstr(const char *c)
 {
     int cnt = 0;
     int pos;
-    unsigned char *prefx;
+    char *prefx;
 
     txxputnameoffset(c);
 
@@ -669,7 +669,7 @@ void parse_options(int argc, char **argv
     }
 }
 
-void parse_mp3(unsigned char *file)
+void parse_mp3(const char *file)
 {
     int bitrates[2][3][15] =
         { {{0, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384,
@@ -683,7 +683,7 @@ void parse_mp3(unsigned char *file)
      {0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160}}
     };
     FILE *fic;
-    unsigned char *c;
+    char *c;
     int lus;
 
     genre = 0;
@@ -773,7 +773,7 @@ void parse_mp3(unsigned char *file)
     }
 
     while(c < buffer + lus - 10) {
-        if(*c == 0xFF && (*(c + 1) & 0xF0) == 0xF0) {
+        if((unsigned char)*c == 0xFF && (*(c + 1) & 0xF0) == 0xF0) {
             int version;
             int lay;
             int bitrate_index;
@@ -823,10 +823,10 @@ void parse_mp3(unsigned char *file)
     fclose(fic);
 }
 
-void parse_ogg(unsigned char *file)
+void parse_ogg(const char *file)
 {
     FILE *fic;
-    unsigned char *c;
+    char *c;
     int lus;
     int sample_rate;
     int samples;
@@ -911,10 +911,10 @@ void parse_ogg(unsigned char *file)
     fclose(fic);
 }
 
-void parse_mpc(unsigned char *file)
+void parse_mpc(const char *file)
 {
     FILE *fic;
-    unsigned char *c;
+    char *c;
     int lus;
     int sample_rates[4] = { 44100, 48000, 37800, 32000 };
     int frame_count;
@@ -1253,9 +1253,9 @@ char * xml_escape_malloc(const char * in
 }
 #endif
 
-void parse_file(unsigned char *newpath, unsigned char * original_path)
+void parse_file(char *newpath, const char * original_path)
 {
-    unsigned char ext[5];
+    char ext[5];
     int j, encoding = 0;
 
     for(j = 0; j < 5; j++)
@@ -1457,11 +1457,11 @@ void parse_file(unsigned char *newpath, 
     }
 }
 
-void parse_directory(unsigned char *path, unsigned char * original_path)
+void parse_directory(char *path, const char * original_path)
 {
     int i, n;
     struct dirent **namelist;
-    unsigned char newpath[PATH_MAX];
+    char newpath[PATH_MAX];
     struct stat infos;
 
     if(debug)
@@ -1520,8 +1520,7 @@ int main(int argc, char **argv)
         break;
     case FORMAT_HTML:
         printf
-            ("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">%s%s<html>%s%s<head>%s<title>Playlist generated by FAPG "
-             VERSION
+            ("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">%s%s<html>%s%s<head>%s<title>Playlist generated by FAPG 0.42"
              "</title>%s<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\" />%s<style type=\"text/css\">%s<!--%s%sbody,td,tr {%s font-family: Verdana, Arial, Helvetica, sans-serif;%s  font-size: 12px;%s  color: #000000;%s}%s%sbody {%s  background: #ffffff;%s}%s%sth {%s  text-align: center;%s  background: #ffcccc;%s  padding-left: 15px;%s  padding-right: 15px;%s  border: 1px #dd8888 solid;%s}%s%std {%s  text-align: center;%s  background: #eeeeee;%s  padding-left: 15px;%s  padding-right: 15px;%s  border: 1px #cccccc solid;%s}%s%sh1 {%s  font-size: 25px;%s}%s%sp {%s  font-size: 10px;%s}%s%sa {%s  color: #993333;%s  text-decoration: none;%s}%s%sa:hover {%s text-decoration: underline;%s}%s%s-->%s</style>%s</head>%s%s<body>%s%s<h1>Playlist</h1>%s%s<table>%s<tr><th>Entry</th><th>Artist</th><th>Title</th><th>Length</th></tr>%s",
              eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol,
              eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol,
@@ -1538,10 +1537,8 @@ int main(int argc, char **argv)
             strftime(timebuffer, 255, "%a %d %b %Y %T %z",
                      localtime(&zeit));
             printf
-                ("<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>%s<!-- generator=\"FAPG "
-                 VERSION
-                 " -->%s<rss xmlns:itunes=\"http://www.itunes.com/DTDs/Podcast-1.0.dtd\" version=\"2.0\">%s    <channel>%s\t<title>%s - %s - %s</title>%s\t<description>Directory Tree %s</description>%s\t<link>%s</link>%s\t<itunes:image href=\"%s/xml/podcast.jpg\"/>%s\t<lastBuildDate>%s</lastBuildDate>%s\t<generator>FAPG "
-                 VERSION
+                ("<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>%s<!-- generator=\"FAPG 0.42"
+                 " -->%s<rss xmlns:itunes=\"http://www.itunes.com/DTDs/Podcast-1.0.dtd\" version=\"2.0\">%s    <channel>%s\t<title>%s - %s - %s</title>%s\t<description>Directory Tree %s</description>%s\t<link>%s</link>%s\t<itunes:image href=\"%s/xml/podcast.jpg\"/>%s\t<lastBuildDate>%s</lastBuildDate>%s\t<generator>FAPG 0.42"
                  "</generator>%s\t<image>%s\t\t<url>%s/podcast.jpg</url>%s\t\t<title>Server Logo</title>%s\t\t<link>%s</link>%s\t\t<description>Feed provided by FAPG. Click to visit.</description>%s\t</image>%s\t<itunes:owner>%s\t\t<itunes:name>Admin %s</itunes:name>%s\t\t<itunes:email>podcast@%s</itunes:email>%s\t</itunes:owner>%s\t<category>Various</category>%s\t<itunes:subtitle>Directory Tree %s</itunes:subtitle>%s\t<itunes:author>%s</itunes:author>%s\t<copyright>unknown</copyright>%s\t<language>%s</language>%s\t<itunes:explicit>No</itunes:explicit>%s\t<ttl>1800</ttl>%s",
                  eol, eol, eol, eol, hostname, dir, argv[optind], eol,
                  prefix, eol, base, eol, prefix, eol, timebuffer, eol, eol,
@@ -1566,7 +1563,7 @@ int main(int argc, char **argv)
 #ifdef HAVE_LIBURIPARSER
     case FORMAT_XSPF:
         printf("<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n"
-                "<!-- generator=\"FAPG " VERSION " -->\n"
+                "<!-- generator=\"FAPG 0.42 -->\n"
                 "<playlist version=\"1\" xmlns=\"http://xspf.org/ns/0/\">\n"
                 "<trackList>\n");
         break;
@@ -1581,7 +1578,7 @@ int main(int argc, char **argv)
         sprintf(pwd, "%s/", pwd_source);
         
         if(fromstdin) {
-            unsigned char path[PATH_MAX];
+            char path[PATH_MAX];
             int i;
             while(fgets(path, PATH_MAX, stdin)) {
                 for(i = 0; i < PATH_MAX; i++)
@@ -1621,7 +1618,7 @@ int main(int argc, char **argv)
     case FORMAT_HTML:
         printf
             ("</table>%s%s<p>Playlist generated by <a href=\"http://royale.zerezo.com/fapg/\">FAPG "
-             VERSION "</a></p>%s%s</body>%s%s</html>", eol, eol, eol, eol,
+             "0.42</a></p>%s%s</body>%s%s</html>", eol, eol, eol, eol,
              eol, eol);
         break;
     case FORMAT_RSS:
