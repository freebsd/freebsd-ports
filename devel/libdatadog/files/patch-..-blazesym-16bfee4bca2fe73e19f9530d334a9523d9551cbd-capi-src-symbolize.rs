Obtained from:  https://github.com/libbpf/blazesym/commit/007ae06cc29feb3b836edff766f1817154aa32af

--- ../blazesym-16bfee4bca2fe73e19f9530d334a9523d9551cbd/capi/src/symbolize.rs.orig	2024-02-23 17:10:31 UTC
+++ ../blazesym-16bfee4bca2fe73e19f9530d334a9523d9551cbd/capi/src/symbolize.rs
@@ -584,7 +584,7 @@ fn convert_symbolizedresults_to_c(results: Vec<Symboli
     let raw_buf = unsafe { raw_buf_with_sz.add(mem::size_of::<u64>()) };
 
     let result_ptr = raw_buf as *mut blaze_result;
-    let mut syms_last = unsafe { &mut (*result_ptr).syms as *mut blaze_sym };
+    let mut syms_last = unsafe { (*result_ptr).syms.as_mut_slice().as_mut_ptr() };
     let mut inlined_last = unsafe {
         raw_buf.add(mem::size_of::<blaze_result>() + mem::size_of::<blaze_sym>() * results.len())
     } as *mut blaze_symbolize_inlined_fn;
