The SocketEvents_SA_CLOSE piece is yet to be submitted, the other hunk is

https://github.com/dotnet/runtime/pull/130372

--- src/runtime/src/native/libs/System.Native/pal_networking.c.orig	2026-06-26 17:46:11 UTC
+++ src/runtime/src/native/libs/System.Native/pal_networking.c
@@ -3254,13 +3254,9 @@ static SocketEvents GetSocketEvents(int16_t filter, ui
         case EVFILT_WRITE:
             events = SocketEvents_SA_WRITE;
 
-            // kqueue does not play well with disconnected connection-oriented sockets, frequently
-            // reporting spurious EOF events. Fortunately, EOF may be handled as an EVFILT_READ |
-            // EVFILT_WRITE event: the usual processing for these events will recognize and
-            // handle the EOF condition.
             if ((flags & EV_EOF) != 0)
             {
-                events |= SocketEvents_SA_READ;
+                events |= SocketEvents_SA_CLOSE;
             }
             break;
 
@@ -3301,13 +3297,8 @@ static int32_t TryChangeSocketEventRegistrationInner(
 static int32_t TryChangeSocketEventRegistrationInner(
     int32_t port, int32_t socket, SocketEvents currentEvents, SocketEvents newEvents, uintptr_t data)
 {
-#ifdef EV_RECEIPT
-    const uint16_t AddFlags = EV_ADD | EV_CLEAR | EV_RECEIPT;
-    const uint16_t RemoveFlags = EV_DELETE | EV_RECEIPT;
-#else
     const uint16_t AddFlags = EV_ADD | EV_CLEAR;
     const uint16_t RemoveFlags = EV_DELETE;
-#endif
 
     assert(currentEvents != newEvents);
 
@@ -3328,20 +3319,6 @@ static int32_t TryChangeSocketEventRegistrationInner(
                0,
                0,
                GetKeventUdata(data));
-#if defined(__FreeBSD__)
-        // Issue: #30698
-        // FreeBSD seems to have some issue when setting read/write events together.
-        // As a workaround use separate kevent() calls.
-        if (writeChanged)
-        {
-            while ((err = kevent(port, events, GetKeventNchanges(i), NULL, 0, NULL)) < 0 && errno == EINTR);
-            if (err != 0)
-            {
-                return SystemNative_ConvertErrorPlatformToPal(errno);
-            }
-            i = 0;
-        }
-#endif
     }
 
     if (writeChanged)
