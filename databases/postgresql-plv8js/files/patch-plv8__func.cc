--- plv8_func.cc.orig	2026-06-01 05:04:31 UTC
+++ plv8_func.cc
@@ -71,14 +71,15 @@ WrapCallback(FunctionCallback func)
 	Isolate* isolate = Isolate::GetCurrent();
 	return External::New(isolate,
 			reinterpret_cast<void *>(
-				reinterpret_cast<uintptr_t>(func)));
+				reinterpret_cast<uintptr_t>(func)),
+			v8::kExternalPointerTypeTagDefault);
 }
 
 static inline FunctionCallback
 UnwrapCallback(Handle<v8::Value> value)
 {
 	return reinterpret_cast<FunctionCallback>(
-			reinterpret_cast<uintptr_t>(External::Cast(*value)->Value()));
+			reinterpret_cast<uintptr_t>(External::Cast(*value)->Value(v8::kExternalPointerTypeTagDefault)));
 }
 
 static inline void
@@ -645,8 +646,8 @@ plv8_Prepare(const FunctionCallbackInfo<v8::Value> &ar
 	Local<ObjectTemplate> templ = Local<ObjectTemplate>::New(isolate, current_context->plan_template);
 
 	Local<v8::Object> result = templ->NewInstance(isolate->GetCurrentContext()).ToLocalChecked();
-	result->SetInternalField(0, External::New(isolate, saved));
-	result->SetInternalField(1, External::New(isolate, parstate));
+	result->SetInternalField(0, External::New(isolate, saved, v8::kExternalPointerTypeTagDefault));
+	result->SetInternalField(1, External::New(isolate, parstate, v8::kExternalPointerTypeTagDefault));
 
 	args.GetReturnValue().Set(result);
 }
@@ -669,7 +670,7 @@ plv8_PlanCursor(const FunctionCallbackInfo<v8::Value> 
 	plv8_param_state   *parstate = NULL;
 
 	plan = static_cast<SPIPlanPtr>(
-			Handle<External>::Cast(self->GetInternalField(0))->Value());
+			Handle<External>::Cast(self->GetInternalField(0))->Value(v8::kExternalPointerTypeTagDefault));
 
 	if (plan == NULL) {
 		StringInfoData	buf;
@@ -694,7 +695,7 @@ plv8_PlanCursor(const FunctionCallbackInfo<v8::Value> 
 	 * If the plan has the variable param info, use it.
 	 */
 	parstate = static_cast<plv8_param_state *>(
-			Handle<External>::Cast(self->GetInternalField(1))->Value());
+			Handle<External>::Cast(self->GetInternalField(1))->Value(v8::kExternalPointerTypeTagDefault));
 
 	if (parstate)
 		argcount = parstate->numParams;
@@ -777,7 +778,7 @@ plv8_PlanExecute(const FunctionCallbackInfo<v8::Value>
 
 
 	plan = static_cast<SPIPlanPtr>(
-			Handle<External>::Cast(self->GetInternalField(0))->Value());
+			Handle<External>::Cast(self->GetInternalField(0))->Value(v8::kExternalPointerTypeTagDefault));
 	/* XXX: Add plan validation */
 
 	if (args.Length() > 0)
@@ -793,7 +794,7 @@ plv8_PlanExecute(const FunctionCallbackInfo<v8::Value>
 	 * If the plan has the variable param info, use it.
 	 */
 	parstate = static_cast<plv8_param_state *>(
-			Handle<External>::Cast(self->GetInternalField(1))->Value());
+			Handle<External>::Cast(self->GetInternalField(1))->Value(v8::kExternalPointerTypeTagDefault));
 
 	if (parstate)
 		argcount = parstate->numParams;
@@ -868,19 +869,19 @@ plv8_PlanFree(const FunctionCallbackInfo<v8::Value> &a
 	int					status = 0;
 
 	plan = static_cast<SPIPlanPtr>(
-			Handle<External>::Cast(self->GetInternalField(0))->Value());
+			Handle<External>::Cast(self->GetInternalField(0))->Value(v8::kExternalPointerTypeTagDefault));
 
 	if (plan)
 		status = SPI_freeplan(plan);
 
-	self->SetInternalField(0, External::New(isolate, 0));
+	self->SetInternalField(0, External::New(isolate, nullptr, v8::kExternalPointerTypeTagDefault));
 
 	parstate = static_cast<plv8_param_state *>(
-			Handle<External>::Cast(self->GetInternalField(1))->Value());
+			Handle<External>::Cast(self->GetInternalField(1))->Value(v8::kExternalPointerTypeTagDefault));
 
 	if (parstate)
 		pfree(parstate);
-	self->SetInternalField(1, External::New(isolate, 0));
+	self->SetInternalField(1, External::New(isolate, nullptr, v8::kExternalPointerTypeTagDefault));
 
 	args.GetReturnValue().Set(Int32::New(isolate, status));
 }
@@ -899,7 +900,7 @@ plv8_CursorFetch(const FunctionCallbackInfo<v8::Value>
 		throw js_error("cannot find cursor");
 	}
 
-	CString				cname(self->GetInternalField(0));
+	CString				cname(self->GetInternalField(0).As<v8::Value>());
 	Portal				cursor = SPI_cursor_find(cname);
 	int					nfetch = 1;
 	bool				forward = true, wantarray = false;
@@ -965,7 +966,7 @@ plv8_CursorMove(const FunctionCallbackInfo<v8::Value>&
 {
 	Isolate*			isolate = args.GetIsolate();
 	Handle<v8::Object>	self = args.This();
-	CString				cname(self->GetInternalField(0));
+	CString				cname(self->GetInternalField(0).As<v8::Value>());
 	Portal				cursor = SPI_cursor_find(cname);
 	int					nmove = 1;
 	bool				forward = true;
@@ -1007,7 +1008,7 @@ plv8_CursorClose(const FunctionCallbackInfo<v8::Value>
 plv8_CursorClose(const FunctionCallbackInfo<v8::Value> &args)
 {
 	Handle<v8::Object>	self = args.This();
-	CString				cname(self->GetInternalField(0));
+	CString				cname(self->GetInternalField(0).As<v8::Value>());
 	Portal				cursor = SPI_cursor_find(cname);
 
 	if (!cursor)
@@ -1035,17 +1036,17 @@ plv8_ReturnNext(const FunctionCallbackInfo<v8::Value>&
 plv8_ReturnNext(const FunctionCallbackInfo<v8::Value>& args)
 {
 	Handle<v8::Object>	self = args.This();
-	Handle<v8::Value>	conv_value = self->GetInternalField(PLV8_INTNL_CONV);
+	Handle<v8::Value>	conv_value = self->GetInternalField(PLV8_INTNL_CONV).As<v8::Value>();
 
 	if (!conv_value->IsExternal())
 		throw js_error("return_next called in context that cannot accept a set");
 
 	Converter *conv = static_cast<Converter *>(
-			Handle<External>::Cast(conv_value)->Value());
+			Handle<External>::Cast(conv_value)->Value(v8::kExternalPointerTypeTagDefault));
 
 	Tuplestorestate *tupstore = static_cast<Tuplestorestate *>(
 			Handle<External>::Cast(
-				self->GetInternalField(PLV8_INTNL_TUPSTORE))->Value());
+				self->GetInternalField(PLV8_INTNL_TUPSTORE).As<v8::Value>())->Value(v8::kExternalPointerTypeTagDefault));
 
 	conv->ToDatum(args[0], tupstore);
 
@@ -1158,7 +1159,7 @@ plv8_GetWindowObject(const FunctionCallbackInfo<v8::Va
 	Isolate*			isolate = args.GetIsolate();
 	Handle<v8::Object>	self = args.This();
 	Handle<v8::Value>	fcinfo_value =
-			self->GetInternalField(PLV8_INTNL_FCINFO);
+			self->GetInternalField(PLV8_INTNL_FCINFO).As<v8::Value>();
 
 	if (!fcinfo_value->IsExternal())
 		throw js_error("get_window_object called in wrong context");
@@ -1179,7 +1180,7 @@ plv8_MyWindowObject(const FunctionCallbackInfo<v8::Val
 	Handle<v8::Object>	self = args.This();
 	/* fcinfo is embedded in the internal field.  See plv8_GetWindowObject() */
 	FunctionCallInfo fcinfo = static_cast<FunctionCallInfo>(
-			Handle<External>::Cast(self->GetInternalField(0))->Value());
+			Handle<External>::Cast(self->GetInternalField(0))->Value(v8::kExternalPointerTypeTagDefault));
 
 	if (fcinfo == NULL)
 		throw js_error("window function api called with wrong object");
@@ -1201,7 +1202,7 @@ plv8_MyArgType(const FunctionCallbackInfo<v8::Value>& 
 {
 	Handle<v8::Object>	self = args.This();
 	FunctionCallInfo fcinfo = static_cast<FunctionCallInfo>(
-			Handle<External>::Cast(self->GetInternalField(0))->Value());
+			Handle<External>::Cast(self->GetInternalField(0))->Value(v8::kExternalPointerTypeTagDefault));
 
 	if (fcinfo == NULL)
 		throw js_error("window function api called with wrong object");
@@ -1636,7 +1637,7 @@ void GetMemoryInfo(v8::Local<v8::Object> obj) {
 
 void GetMemoryInfo(v8::Local<v8::Object> obj) {
 	HeapStatistics  	v8_heap_stats;
-	Isolate 		   *isolate = obj->GetIsolate();
+	Isolate 		   *isolate = Isolate::GetCurrent();
 	Handle<Context> context = isolate->GetCurrentContext();
 
 	isolate->GetHeapStatistics(&v8_heap_stats);
