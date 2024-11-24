--- common/kiid.cpp.orig
+++ common/kiid.cpp
@@ -40,15 +40,15 @@
 
 #include <wx/log.h>
 
-// boost:mt19937 is not thread-safe
+// OBSOLTE: boost:mt19937 is not thread-safe
 static std::mutex                                           rng_mutex;
 
 // Static rng and generators are used because the overhead of constant seeding is expensive
 // We rely on the default non-arg constructor of basic_random_generator to provide a random seed.
 // We use a separate rng object for cases where we want to control the basic_random_generator
 // initial seed by calling SeedGenerator from unit tests and other special cases.
-static boost::mt19937                                       rng;
-static boost::uuids::basic_random_generator<boost::mt19937> randomGenerator;
+static std::mt19937                                       rng;
+static boost::uuids::basic_random_generator<std::mt19937> randomGenerator;
 
 // These don't have the same performance penalty, but we might as well be consistent
 static boost::uuids::string_generator                       stringGenerator;
@@ -235,15 +235,7 @@
 
 size_t KIID::Hash() const
 {
-    size_t hash = 0;
-
-    // Note: this is NOT little-endian/big-endian safe, but as long as it's just used
-    // at runtime it won't matter.
-
-    for( int i = 0; i < 4; ++i )
-        boost::hash_combine( hash, reinterpret_cast<const uint32_t*>( m_uuid.data )[i] );
-
-    return hash;
+    return boost::uuids::hash_value(m_uuid);
 }
 
 
@@ -300,7 +292,7 @@
 void KIID::SeedGenerator( unsigned int aSeed )
 {
     rng.seed( aSeed );
-    randomGenerator = boost::uuids::basic_random_generator<boost::mt19937>( rng );
+    randomGenerator = boost::uuids::basic_random_generator<std::mt19937>( rng );
 }
 
 
