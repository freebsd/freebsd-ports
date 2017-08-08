--- src/System/KQueue.chs.orig	2016-05-30 14:31:11 UTC
+++ src/System/KQueue.chs
@@ -21,6 +21,7 @@ module System.KQueue
 
 #include <sys/time.h>
 #include <sys/event.h>
+#include "MachDeps.h"
 
 #if __GLASGOW_HASKELL__ <= 708
 import Control.Applicative ( (<$>), (<*>) )
@@ -57,6 +58,7 @@ import Foreign.C           ( CInt )
 import Foreign.C           ( CLong
                            , CTime
                            , CULong
+                           , CUInt
                            )
 
 -- | A kernel event queue.
@@ -68,11 +70,19 @@ kqueue = KQueue <$> {#call kqueue as kqueue_ #}
 
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
 
@@ -128,8 +138,10 @@ enum FFlag
   , NoteExit   = NOTE_EXIT
   , NoteFork   = NOTE_FORK
   , NoteExec   = NOTE_EXEC
+#ifndef __FreeBSD__
   , NoteSignal = NOTE_SIGNAL
 //  , NoteReap   = NOTE_REAP
+#endif
   };
 #endc
 
