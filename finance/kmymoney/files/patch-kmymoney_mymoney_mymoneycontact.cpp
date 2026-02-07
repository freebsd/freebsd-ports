Adapt to API changes since kidentitymanagement 24.02.0.

--- kmymoney/mymoney/mymoneycontact.cpp.orig	2025-08-04 11:03:25 UTC
+++ kmymoney/mymoney/mymoneycontact.cpp
@@ -8,8 +8,8 @@
 #include "mymoneycontact.h"
 
 #ifdef ENABLE_ADDRESSBOOK
-#include <KIdentityManagement/Identity>
-#include <KIdentityManagement/IdentityManager>
+#include <KIdentityManagementCore/Identity>
+#include <KIdentityManagementCore/IdentityManager>
 #include <akonadi_version.h>
 
 #if AKONADI_VERSION >= QT_VERSION_CHECK(5, 18, 41)
@@ -33,8 +33,8 @@ bool MyMoneyContact::ownerExists() const
 bool MyMoneyContact::ownerExists() const
 {
 #ifdef ENABLE_ADDRESSBOOK
-    KIdentityManagement::IdentityManager im;
-    KIdentityManagement::Identity id = im.defaultIdentity();
+    KIdentityManagementCore::IdentityManager im;
+    KIdentityManagementCore::Identity id = im.defaultIdentity();
     return !id.isNull();
 #else
     return false;
@@ -44,8 +44,8 @@ QString MyMoneyContact::ownerEmail() const
 QString MyMoneyContact::ownerEmail() const
 {
 #ifdef ENABLE_ADDRESSBOOK
-    KIdentityManagement::IdentityManager im;
-    KIdentityManagement::Identity id = im.defaultIdentity();
+    KIdentityManagementCore::IdentityManager im;
+    KIdentityManagementCore::Identity id = im.defaultIdentity();
     return id.primaryEmailAddress();
 #else
     return QString();
@@ -55,8 +55,8 @@ QString MyMoneyContact::ownerFullName() const
 QString MyMoneyContact::ownerFullName() const
 {
 #ifdef ENABLE_ADDRESSBOOK
-    KIdentityManagement::IdentityManager im;
-    KIdentityManagement::Identity id = im.defaultIdentity();
+    KIdentityManagementCore::IdentityManager im;
+    KIdentityManagementCore::Identity id = im.defaultIdentity();
     return id.fullName();
 #else
     return QString();
