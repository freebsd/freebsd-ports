diff -r -C 2 mumble-1.1.8/overlay/overlay.h overlay/overlay.h
*** mumble-1.1.8/overlay/overlay.h	2009-03-22 16:05:00.000000000 +0100
--- overlay/overlay.h	2009-08-06 20:07:48.000000000 +0200
***************
*** 43,46 ****
--- 43,65 ----
  #define OVERLAY_VERSION_SUB 0
  
+ /* BSD support */
+ #ifndef ElfW
+ # ifdef __FreeBSD__
+ #  if __ELF_WORD_SIZE == 32
+ #   define ElfW(type) Elf32_##type
+ #  else
+ #   define ElfW(type) Elf64_##type
+ #  endif
+ # else
+ # ifdef __NetBSD__
+ #  if ELFSIZE == 32
+ #   define ElfW(type) Elf32_##type
+ #  else 
+ #   define ElfW(type) Elf64_##type
+ #  endif
+ # endif
+ # endif
+ #endif
+ 
  struct TextEntry {
  	unsigned int color;
diff -r -C 2 mumble-1.1.8/src/mumble/ServerHandler.cpp src/mumble/ServerHandler.cpp
*** mumble-1.1.8/src/mumble/ServerHandler.cpp	2009-03-22 16:05:00.000000000 +0100
--- src/mumble/ServerHandler.cpp	2009-08-06 12:50:18.000000000 +0200
***************
*** 40,43 ****
--- 40,46 ----
  #include "PacketDataStream.h"
  #include "NetworkConfig.h"
+ #include <sys/types.h>
+ #include <sys/socket.h>
+ #include <netinet/in.h>
  
  ServerHandlerMessageEvent::ServerHandlerMessageEvent(QByteArray &msg, bool flush) : QEvent(static_cast<QEvent::Type>(SERVERSEND_EVENT)) {
