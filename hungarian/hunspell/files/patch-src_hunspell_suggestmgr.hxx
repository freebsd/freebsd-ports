
$FreeBSD$

--- src/hunspell/suggestmgr.hxx.orig
+++ src/hunspell/suggestmgr.hxx
@@ -61,8 +61,8 @@
 
 private:
    int testsug(char** wlst, const char * candidate, int wl, int ns, int cpdsuggest,
-     int * timer, time_t * timelimit);
-   int checkword(const char *, int, int, int *, time_t *);
+     int * timer, clock_t * timelimit);
+   int checkword(const char *, int, int, int *, clock_t *);
    int check_forbidden(const char *, int);
 
    int capchars(char **, const char *, int, int);
@@ -89,8 +89,8 @@
    int movechar_utf(char **, const w_char *, int, int, int);
 
    int mapchars(char**, const char *, int, int);
-   int map_related(const char *, int, char ** wlst, int, int, const mapentry*, int, int *, time_t *);
-   int map_related_utf(w_char *, int, int, int, char ** wlst, int, const mapentry*, int, int *, time_t *);
+   int map_related(const char *, int, char ** wlst, int, int, const mapentry*, int, int *, clock_t *);
+   int map_related_utf(w_char *, int, int, int, char ** wlst, int, const mapentry*, int, int *, clock_t *);
    int ngram(int n, char * s1, const char * s2, int opt);
    int mystrlen(const char * word);
    int leftcommonsubstring(char * s1, const char * s2);
