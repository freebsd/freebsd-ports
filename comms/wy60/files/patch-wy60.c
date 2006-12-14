
$FreeBSD$

--- wy60.c.orig
+++ wy60.c
@@ -59,6 +59,17 @@
 } ScreenBuffer;
 
 
+static void flushConsole(void);
+static void gotoXYforce(int x, int y);
+static void putCapability(const char *capability);
+static int  putConsole(int ch);
+static void putGraphics(char ch);
+static void showCursor(int flag);
+static void updateAttributes(void);
+static void failure(int exitCode, const char *message, ...);
+static void processSignal(int signalNumber, int pid, int pty);
+
+
 static int            euid, egid, uid, gid, oldStylePty, streamsIO, jobControl;
 static char           ptyName[40];
 static struct termios defaultTermios;
@@ -260,7 +271,6 @@
       logFd            = -1;
   }
   if (logFd >= 0) {
-    static void flushConsole(void);
     int  header[4];
 
     gettimeofday(&timeValue, 0);
@@ -295,7 +305,6 @@
   }
 
   if (logFd >= 0) {
-    static void flushConsole(void);
     char buffer[80];
 
     if (isatty(logFd))
@@ -369,8 +378,6 @@
 
 static void logDecodeFlush(void) {
   if (_decodeFd >= 0) {
-    static void flushConsole(void);
-
     if (isatty(_decodeFd))
       strcat(_decodeBuffer, "\x1B[39m");
     strcat(_decodeBuffer, "\r\n");
@@ -2203,14 +2210,6 @@
 
 
 static void displayCurrentScreenBuffer(void) {
-  static void flushConsole(void);
-  static void gotoXYforce(int x, int y);
-  static void putCapability(const char *capability);
-  static int  putConsole(int ch);
-  static void putGraphics(char ch);
-  static void showCursor(int flag);
-  static void updateAttributes(void);
-
   int x, y, lastAttributes      = -1;
   int oldX                      = currentBuffer->cursorX;
   int oldY                      = currentBuffer->cursorY;
@@ -2346,8 +2345,6 @@
 
 
 static void putCapability(const char *capability) {
-  static void failure(int exitCode, const char *message, ...);
-
   if (!capability || !strcmp(capability, "@"))
     failure(127, "Terminal has insufficient capabilities");
   logHostString(capability);
@@ -2756,8 +2753,6 @@
 
 
 static void putGraphics(char ch) {
-  static void updateAttributes(void);
-
   if (ch == '\x02')
     graphicsMode                  = 1;
   else if (ch == '\x03')
@@ -2839,7 +2834,6 @@
 
 
 static void executeExternalProgram(const char *argv[]) {
-  static void failure(int exitCode, const char *message, ...);
   int    pid, status;
 
   if ((pid = fork()) < 0) {
@@ -2886,8 +2880,6 @@
 
 
 static void requestNewGeometry(int pty, int width, int height) {
-  static void processSignal(int signalNumber, int pid, int pty);
-
   logDecode("setScreenSize(%d,%d)", width, height);
 
   if (screenWidth != width || screenHeight != height) {
