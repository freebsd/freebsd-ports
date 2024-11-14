--- lld/ELF/Driver.cpp.orig
+++ lld/ELF/Driver.cpp
@@ -1723,6 +1723,10 @@
                      << arg->getValue() << "'";
     parallel::strategy = hardware_concurrency(threads);
     ctx.arg.thinLTOJobs = v;
+  } else if (sizeof(size_t) < 8) {
+    // On 32-bit systems, cap the number of threads at 1.
+    Log(ctx) << "set maximum concurrency to 1, specify --threads= to change";
+    parallel::strategy = hardware_concurrency(1);
   } else if (parallel::strategy.compute_thread_count() > 16) {
     Log(ctx) << "set maximum concurrency to 16, specify --threads= to change";
     parallel::strategy = hardware_concurrency(16);
