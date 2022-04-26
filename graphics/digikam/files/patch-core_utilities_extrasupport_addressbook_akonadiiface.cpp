--- core/utilities/extrasupport/addressbook/akonadiiface.cpp.orig	2022-04-22 10:48:13 UTC
+++ core/utilities/extrasupport/addressbook/akonadiiface.cpp
@@ -49,7 +49,7 @@
 #include <AkonadiCore/Item>
 #endif
 
-#include <Akonadi/Contact/ContactSearchJob>
+#include <AkonadiContact/Akonadi/ContactSearchJob>
 #include <KContacts/Addressee>
 
 #if defined(Q_OS_DARWIN) && defined(Q_CC_CLANG)
