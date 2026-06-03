--- drivers/sdl/SDL_build_config_private.h.orig	2026-02-25 14:00:27 UTC
+++ drivers/sdl/SDL_build_config_private.h
@@ -75,26 +75,14 @@
 #define SDL_SENSOR_WINDOWS 1
 
 // Linux defines
-#elif defined(SDL_PLATFORM_LINUX)
+#elif defined(SDL_PLATFORM_LINUX) || defined(SDL_PLATFORM_FREEBSD) || defined(SDL_PLATFORM_OPENBSD) || defined(SDL_PLATFORM_NETBSD)
 
-#define SDL_PLATFORM_PRIVATE_NAME "Linux"
 #define SDL_PLATFORM_UNIX 1
 
 #define HAVE_STDIO_H 1
 #define HAVE_LIBC 1
-#define HAVE_LINUX_INPUT_H 1
 #define HAVE_POLL 1
 
-#ifdef __linux__
-#define HAVE_INOTIFY 1
-#define HAVE_INOTIFY_INIT1 1
-// Don't add these defines, for some reason they mess with C#'s ability
-// to use environment variables (see GH-109024)
-//#define HAVE_GETENV 1
-//#define HAVE_SETENV 1
-//#define HAVE_UNSETENV 1
-#endif
-
 #ifdef DBUS_ENABLED
 #define HAVE_DBUS_DBUS_H 1
 #define SDL_USE_LIBDBUS 1
@@ -105,17 +93,57 @@
 #define HAVE_LIBUDEV_H 1
 #define SDL_USE_LIBUDEV
 #ifdef SOWRAP_ENABLED
-#define SDL_UDEV_DYNAMIC "libudev.so.1"
+#define SDL_UDEV_DYNAMIC "libudev.so.0"
 #endif
 #endif
 
 #define SDL_LOADSO_DLOPEN 1
-#define SDL_HAPTIC_LINUX 1
 #define SDL_TIMER_UNIX 1
+#define SDL_THREAD_PTHREAD 1
+
+#ifdef SDL_PLATFORM_LINUX
+#define SDL_PLATFORM_PRIVATE_NAME "Linux"
+
+#define HAVE_LINUX_INPUT_H 1
+#define SDL_HAPTIC_LINUX 1
 #define SDL_JOYSTICK_LINUX 1
-#define SDL_JOYSTICK_HIDAPI 1
 #define SDL_INPUT_LINUXEV 1
-#define SDL_THREAD_PTHREAD 1
+
+#define HAVE_INOTIFY 1
+#define HAVE_INOTIFY_INIT1 1
+
+// Don't add these defines, for some reason they mess with C#'s ability
+// to use environment variables (see GH-109024)
+//#define HAVE_GETENV 1
+//#define HAVE_SETENV 1
+//#define HAVE_UNSETENV 1
+
+#else
+
+#ifdef SDL_PLATFORM_FREEBSD
+#define SDL_PLATFORM_PRIVATE_NAME "FreeBSD"
+//#define HAVE_USBHID_H 1  // this needs more work
+#define HAVE_LINUX_INPUT_H 1
+#define SDL_HAPTIC_LINUX 1
+#define SDL_JOYSTICK_LINUX 1
+#define SDL_INPUT_LINUXEV 1
+#elif defined(SDL_PLATFORM_OPENBSD)
+#define SDL_PLATFORM_PRIVATE_NAME "OpenBSD"
+#define HAVE_USBHID_H 1
+#define USBHID_NEW 1
+#define USBHID_UCR_DATA 1
+#elif defined(SDL_PLATFORM_NETBSD)
+#define SDL_PLATFORM_PRIVATE_NAME "NetBSD"
+#define HAVE_USBHID_H 1
+#define USBHID_NEW 1
+#define USBHID_UCR_DATA 1
+#endif
+
+#define SDL_HAPTIC_DISABLED 1
+#define SDL_JOYSTICK_USBHID 1
+
+#endif
+
 
 // MacOS defines
 #elif defined(SDL_PLATFORM_MACOS)
