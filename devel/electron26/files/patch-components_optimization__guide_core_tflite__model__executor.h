--- components/optimization_guide/core/tflite_model_executor.h.orig	2023-08-10 01:48:40 UTC
+++ components/optimization_guide/core/tflite_model_executor.h
@@ -189,7 +189,11 @@ class TFLiteModelExecutor : public ModelExecutor<Outpu
   void SendForBatchExecution(
       BatchExecutionCallback callback_on_complete,
       base::TimeTicks start_time,
+#if defined(__clang__) && (__clang_major__ >= 15)
       ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs)
+#else
+      typename ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs)
+#endif
       override {
     DCHECK(execution_task_runner_->RunsTasksInCurrentSequence());
     DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
