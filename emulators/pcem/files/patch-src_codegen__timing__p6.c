--- src/codegen_timing_p6.c.orig	2020-12-01 19:49:05 UTC
+++ src/codegen_timing_p6.c
@@ -80,7 +80,7 @@ static const p6_instruction_t aluc_op =
 {
         .nr_uops = 2,
         .uop[0] = {.type = UOP_ALU01, .throughput = 1, .latency = 1},
-        .uop[0] = {.type = UOP_ALU01, .throughput = 1, .latency = 1}
+        .uop[1] = {.type = UOP_ALU01, .throughput = 1, .latency = 1}
 };
 static const p6_instruction_t load_alu_op =
 {
@@ -146,7 +146,7 @@ static const p6_instruction_t bswap_op =
 {
         .nr_uops = 2,
         .uop[0] = {.type = UOP_ALU0,  .throughput = 1, .latency = 1},
-        .uop[0] = {.type = UOP_ALU01, .throughput = 1, .latency = 1}
+        .uop[1] = {.type = UOP_ALU01, .throughput = 1, .latency = 1}
 };
 static const p6_instruction_t leave_op =
 {
