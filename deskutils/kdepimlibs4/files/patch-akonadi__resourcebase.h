commit e65bae22cf6da5c0db468691a8037ac81ffce291
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Sun Jun 2 02:29:49 2013 +0300

    Correctly expose that ResourceState is a friend class.
    
    ResourceState is a class that lives in kdepim-runtime and is outside the
    Akonadi namespace.
    
    clang < 3.3 and all versions of GCC erroneously consider the friend
    declaration in
    
      namespace N {
        class C {
          friend class A;
        };
      }
    
      class A {
      };
    
    to refer to the class A outside namespace N (technically speaking, this is
    item 3 of section 7.3.1.2 of the C++ standard). clang 3.3 fixes this
    behavior and makes the build of kdepim-runtime fail.
    
    Fix it by explicitly referring to ::ResourceState in the friend declaration.
    
    Alternatively, we could remove the friend declaration and make
    ResourceState::collectionsRetrieved use ImapResource::Append instead of
    Akonadi::ResourceBase::Append (since ImapResource also declares
    ResourceState as a friend).
    
    REVIEW: 110777

diff --git a/akonadi/resourcebase.h b/akonadi/resourcebase.h
index 2e112b5..cb25ef2 100644
--- akonadi/resourcebase.h
+++ akonadi/resourcebase.h
@@ -32,6 +32,7 @@
 
 class KJob;
 class Akonadi__ResourceAdaptor;
+class ResourceState;
 
 namespace Akonadi {
 
@@ -566,7 +567,7 @@ class AKONADI_EXPORT ResourceBase : public AgentBase
     void setHierarchicalRemoteIdentifiersEnabled( bool enable );
 
     friend class ResourceScheduler;
-    friend class ResourceState;
+    friend class ::ResourceState;
 
     /**
      * Describes the scheduling priority of a task that has been queued
