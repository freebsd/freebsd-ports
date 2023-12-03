--- core/cmake/rules/RulesKDEFramework.cmake.orig	2023-11-29 09:52:21 UTC
+++ core/cmake/rules/RulesKDEFramework.cmake
@@ -40,9 +40,9 @@ if(ENABLE_AKONADICONTACTSUPPORT)
     find_package(KF${QT_VERSION_MAJOR} ${AKONADI_MIN_VERSION} QUIET
                                             OPTIONAL_COMPONENTS
                                             Akonadi
-                                            AkonadiContact      # For KDE Mail Contacts support.
-                                            Contacts            # API for contacts/address book data.
     )
+    find_package(KPim${QT_VERSION_MAJOR}Akonadi ${AKONADI_MIN_VERSION} QUIET)
+    find_package(KPim${QT_VERSION_MAJOR}AkonadiContact ${AKONADI_MIN_VERSION} QUIET)
 
 endif()
 
