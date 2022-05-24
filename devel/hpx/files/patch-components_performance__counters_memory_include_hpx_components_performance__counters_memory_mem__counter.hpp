--- components/performance_counters/memory/include/hpx/components/performance_counters/memory/mem_counter.hpp.orig	2022-05-24 18:40:32 UTC
+++ components/performance_counters/memory/include/hpx/components/performance_counters/memory/mem_counter.hpp
@@ -19,6 +19,7 @@ namespace hpx { namespace performance_counters { names
     std::uint64_t read_psm_resident(bool);
 
 #if defined(__linux) || defined(linux) || defined(linux__) || defined(__linux__) \
+ || defined(__FreeBSD__) \
  || defined(HPX_WINDOWS)
     // returns total available memory
     std::uint64_t read_total_mem_avail(bool);
