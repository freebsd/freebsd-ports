--- olmocr/pipeline.py.orig	2026-03-12 16:30:29 UTC
+++ olmocr/pipeline.py
@@ -811,7 +811,7 @@ async def vllm_server_task(model_name_or_path, args, u
         model_name_or_path,
         "--port",
         str(args.port),
-        "--disable-log-requests",
+        "--no-enable-log-requests",
         "--uvicorn-log-level",
         "warning",
         "--served-model-name",
@@ -833,12 +833,15 @@ async def vllm_server_task(model_name_or_path, args, u
     if unknown_args:
         cmd.extend(unknown_args)
 
+    if getattr(args, "device", "cpu") == "cpu":
+        cmd.append("--enforce-eager")
+
     proc = await asyncio.create_subprocess_exec(
         *cmd,
         stdout=asyncio.subprocess.PIPE,
         stderr=asyncio.subprocess.PIPE,
         # OMP_NUM_THREADS needs to be 1, otherwise you could have contention if you are running multiple copies of olmOCR on a machine with several GPUS
-        env={**os.environ, "OMP_NUM_THREADS": "1"},
+        env={**os.environ, "OMP_NUM_THREADS": str(os.cpu_count()) if getattr(args, "device", "cpu") == "cpu" else "1"},
     )
 
     # Ensure the subprocess is terminated on exit
@@ -1211,7 +1214,7 @@ async def main():
     parser.add_argument(
         "--model",
         help="Path where the model is located, allenai/olmOCR-2-7B-1025-FP8 is the default, can be local, s3, or hugging face.",
-        default="allenai/olmOCR-2-7B-1025-FP8",
+        default="allenai/olmOCR-2-7B-1025",
     )
 
     # More detailed config options, usually you shouldn't have to change these
@@ -1256,6 +1259,7 @@ async def main():
     vllm_group.add_argument("--tensor-parallel-size", "-tp", type=int, default=1, help="Tensor parallel size for vLLM")
     vllm_group.add_argument("--data-parallel-size", "-dp", type=int, default=1, help="Data parallel size for vLLM")
     vllm_group.add_argument("--port", type=int, default=30024, help="Port to use for the VLLM server")
+    vllm_group.add_argument("--device", type=str, default="cpu", help="Device to use for inference (cpu, cuda, etc.)")
 
     # Beaker/job running stuff
     beaker_group = parser.add_argument_group("beaker/cluster execution")
@@ -1421,7 +1425,7 @@ async def main():
 
     # If you get this far, then you are doing inference and need a GPU
     # check_sglang_version()
-    if use_internal_server:
+    if use_internal_server and args.device != "cpu":
         check_torch_gpu_available()
 
     logger.info(f"Starting pipeline with PID {os.getpid()}")
