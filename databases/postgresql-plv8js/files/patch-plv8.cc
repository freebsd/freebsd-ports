--- plv8.cc.orig	2025-07-05 17:44:26 UTC
+++ plv8.cc
@@ -232,10 +232,10 @@ void PromiseRejectCB(PromiseRejectMessage rejection) {
 
 void PromiseRejectCB(PromiseRejectMessage rejection) {
 	auto event = rejection.GetEvent();
-	if (event == kPromiseRejectAfterResolved || event == kPromiseResolveAfterResolved)
+	if (event == kDeprecatedPromiseRejectAfterResolved || event == kDeprecatedPromiseResolveAfterResolved)
 		return;
 	auto	promise = rejection.GetPromise();
-	auto	isolate = promise->GetIsolate();
+	auto	isolate = v8::Isolate::GetCurrent();
 
 	if (rejection.GetEvent() == v8::kPromiseHandlerAddedAfterReject) {
 		if (current_context->ignore_unhandled_promises) return;
@@ -753,7 +753,7 @@ DoCall(Local<Context> ctx, Handle<Function> fn, Handle
 DoCall(Local<Context> ctx, Handle<Function> fn, Handle<Object> receiver,
 	int nargs, Handle<v8::Value> args[], bool nonatomic)
 {
-	Isolate 	   *isolate = ctx->GetIsolate();
+	Isolate 	   *isolate = Isolate::GetCurrent();
 	TryCatch		try_catch(isolate);
 
 	if (isolate->IsExecutionTerminating() || current_context->interrupted) {
@@ -897,7 +897,7 @@ CallFunction(PG_FUNCTION_ARGS, plv8_exec_env *xenv,
 
 	Local<Object> recv = Local<Object>::New(xenv->isolate, xenv->recv);
 	Local<Function>		fn =
-		Local<Function>::Cast(recv->GetInternalField(0));
+		Local<Function>::Cast(recv->GetInternalField(0).As<v8::Value>());
 	
 	Local<v8::Value> result =
 		DoCall(context, fn, recv, nargs, args, nonatomic);
@@ -1014,7 +1014,7 @@ CallSRFunction(PG_FUNCTION_ARGS, plv8_exec_env *xenv,
 
 	Local<Object> recv = Local<Object>::New(xenv->isolate, xenv->recv);
 	Local<Function>		fn =
-		Local<Function>::Cast(recv->GetInternalField(0));
+		Local<Function>::Cast(recv->GetInternalField(0).As<v8::Value>());
 
 	Handle<v8::Value> result = DoCall(context, fn, recv, nargs, args, nonatomic);
 
@@ -1148,7 +1148,7 @@ CallTrigger(PG_FUNCTION_ARGS, plv8_exec_env *xenv)
 	TryCatch			try_catch(xenv->isolate);
 	Local<Object> recv = Local<Object>::New(xenv->isolate, xenv->recv);
 	Local<Function>		fn =
-		Local<Function>::Cast(recv->GetInternalField(0));
+		Local<Function>::Cast(recv->GetInternalField(0).As<v8::Value>());
 	Handle<v8::Value> newtup =
 		DoCall(context, fn, recv, lengthof(args), args, nonatomic);
 
@@ -1547,7 +1547,7 @@ CompileFunction(
 	Local<Context> context = Local<Context>::New(isolate, global_context->context);
 	Context::Scope	context_scope(context);
 	TryCatch		try_catch(isolate);
-	v8::ScriptOrigin origin(isolate, name);
+	v8::ScriptOrigin origin(name);
 
 	// set up the signal handlers
 	if (int_handler == NULL) {
