*** xmine.c~	Sat Apr  2 00:20:15 1994
--- xmine.c	Thu Jun 30 10:20:34 1994
***************
*** 78,83 ****
--- 78,90 ----
  #define GSPACEX 16
  #define GSPACEY 16
  
+ /* some systems might be better off with using "random()" instead of "rand()"*/
+ #if defined __FreeBSD__
+ # define USE_RANDOM 1
+ #else
+ # define USE_RANDOM 0
+ #endif
+ 
  #define SCORE_FILE "~/.xmine_scores"
  #define TOPMARGIN 60
  #define BOTMARGIN 12
***************
*** 911,922 ****
--- 918,938 ----
  {
  	int i, x, y, xd, yd, tries;
  
+ #if USE_RANDOM
+ 	srandom((unsigned) time(0));
+ #else
  	srand((unsigned int) time(0));
+ #endif
  	for (i = 0; i != mine_count; i++) {
  		tries = 1000;
  		do {
+ #if USE_RANDOM
+ 			x = (random()>>1) % gsizex;
+ 			y = (random()>>1) % gsizey;
+ #else
  			x = (rand()>>1) % gsizex;
  			y = (rand()>>1) % gsizey;
+ #endif
  			tries--;
  		} while (tries && (grid[x][y] ||
  				   !(x < fx-1 || x > fx+1 || y < fy-1
*** Imakefile~	Mon Dec 26 12:42:58 1994
--- Imakefile	Mon Dec 26 12:49:44 1994
***************
*** 20,25 ****
--- 20,29 ----
  # define WarnLevel
  #endif
  
+ # for FreeBSD package: do not compress man page, otherwise gzip will
+ # complain when building the package target
+ COMPRESSMANCMD = echo
+ 
          DEPLIBS = XawClientDepLibs
  LOCAL_LIBRARIES = XawClientLibs
    EXTRA_DEFINES = WarnLevel Xaw3dDefs
