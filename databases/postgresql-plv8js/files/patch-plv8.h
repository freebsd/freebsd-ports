--- plv8.h.orig	2026-06-01 05:04:31 UTC
+++ plv8.h
@@ -217,15 +217,15 @@ class WindowFunctionSupport (public)
 		{
 			m_plv8obj = v8::Handle<v8::Object>::Cast(
 					context->Global()->Get(context, v8::String::NewFromUtf8Literal(
-						context->GetIsolate(),
+						v8::Isolate::GetCurrent(),
 						"plv8",
 						v8::NewStringType::kInternalized)).ToLocalChecked());
 			if (m_plv8obj.IsEmpty())
 				throw js_error("plv8 object not found");
 			/* Stash the current item, just in case of nested call */
-			m_prev_fcinfo = m_plv8obj->GetInternalField(PLV8_INTNL_FCINFO);
+			m_prev_fcinfo = m_plv8obj->GetInternalField(PLV8_INTNL_FCINFO).As<v8::Value>();
 			m_plv8obj->SetInternalField(PLV8_INTNL_FCINFO,
-					v8::External::New(context->GetIsolate(), fcinfo));
+					v8::External::New(v8::Isolate::GetCurrent(), fcinfo, v8::kExternalPointerTypeTagDefault));
 		}
 	}
 	bool IsWindowCall() { return WindowObjectIsValid(m_winobj); }
@@ -257,17 +257,17 @@ class SRFSupport (public)
 	{
 	    v8::Local<v8::Value> m_val;
 	    if (!context->Global()->Get(context, v8::String::NewFromUtf8Literal(
-                context->GetIsolate(),
+                v8::Isolate::GetCurrent(),
                 "plv8",
                 v8::NewStringType::kInternalized)).ToLocal(&m_val))
             throw js_error("plv8 object not found");
 	    m_plv8obj = v8::Handle<v8::Object>::Cast(m_val);
-		m_prev_conv = m_plv8obj->GetInternalField(PLV8_INTNL_CONV);
-		m_prev_tupstore = m_plv8obj->GetInternalField(PLV8_INTNL_TUPSTORE);
+		m_prev_conv = m_plv8obj->GetInternalField(PLV8_INTNL_CONV).As<v8::Value>();
+		m_prev_tupstore = m_plv8obj->GetInternalField(PLV8_INTNL_TUPSTORE).As<v8::Value>();
 		m_plv8obj->SetInternalField(PLV8_INTNL_CONV,
-									v8::External::New(context->GetIsolate(), conv));
+									v8::External::New(v8::Isolate::GetCurrent(), conv, v8::kExternalPointerTypeTagDefault));
 		m_plv8obj->SetInternalField(PLV8_INTNL_TUPSTORE,
-									v8::External::New(context->GetIsolate(), tupstore));
+									v8::External::New(v8::Isolate::GetCurrent(), tupstore, v8::kExternalPointerTypeTagDefault));
 	}
 	~SRFSupport()
 	{
