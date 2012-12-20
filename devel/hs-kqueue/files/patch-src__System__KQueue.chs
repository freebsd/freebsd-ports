--- ./src/System/KQueue.chs.orig	2012-01-03 14:00:32.000000000 +0100
+++ ./src/System/KQueue.chs	2012-01-27 07:17:17.000000000 +0100
@@ -21,6 +21,7 @@
 
 #include <sys/time.h>
 #include <sys/event.h>
+#include "MachDeps.h"
 
 import Control.Applicative ( (<$>), (<*>) )
 import Control.Exception   ( Exception, throwIO )
@@ -62,11 +63,19 @@
 
 -- | A kernel event.
 data KEvent = KEvent
+#if SIZEOF_HSWORD == 4
+  { ident    :: CUInt   -- ^ The identifier for the event, often a file descriptor.
+#else
   { ident    :: CULong  -- ^ The identifier for the event, often a file descriptor.
+#endif
   , evfilter :: Filter  -- ^ The kernel filter (type of event).
   , flags    :: [Flag]  -- ^ Actions to perform on the event.
   , fflags   :: [FFlag] -- ^ Filter-specific flags.
+#if SIZEOF_HSWORD == 4
+  , data_    :: CInt    -- ^ Filter-specific data value.
+#else
   , data_    :: CLong   -- ^ Filter-specific data value.
+#endif
   , udata    :: Ptr ()  -- ^ User-defined data, passed through unchanged.
   } deriving (Show, Eq)
 
@@ -122,8 +131,10 @@
   , NoteExit   = NOTE_EXIT
   , NoteFork   = NOTE_FORK
   , NoteExec   = NOTE_EXEC
+#ifndef __FreeBSD__
   , NoteSignal = NOTE_SIGNAL
   , NoteReap   = NOTE_REAP
+#endif
   };
 #endc
 
