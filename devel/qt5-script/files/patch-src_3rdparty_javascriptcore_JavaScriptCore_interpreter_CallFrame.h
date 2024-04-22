Index: src/3rdparty/javascriptcore/JavaScriptCore/interpreter/CallFrame.h
--- src/3rdparty/javascriptcore/JavaScriptCore/interpreter/CallFrame.h.orig
+++ src/3rdparty/javascriptcore/JavaScriptCore/interpreter/CallFrame.h
@@ -135,9 +135,11 @@ namespace JSC  {
         static CallFrame* noCaller() { return reinterpret_cast<CallFrame*>(HostCallFrameFlag); }
         int returnValueRegister() const { return this[RegisterFile::ReturnValueRegister].i(); }
 
+#pragma clang optimize off
         bool hasHostCallFrameFlag() const { return reinterpret_cast<intptr_t>(this) & HostCallFrameFlag; }
         CallFrame* addHostCallFrameFlag() const { return reinterpret_cast<CallFrame*>(reinterpret_cast<intptr_t>(this) | HostCallFrameFlag); }
         CallFrame* removeHostCallFrameFlag() { return reinterpret_cast<CallFrame*>(reinterpret_cast<intptr_t>(this) & ~HostCallFrameFlag); }
+#pragma clang optimize on
 
     private:
         void setArgumentCount(int count) { static_cast<Register*>(this)[RegisterFile::ArgumentCount] = Register::withInt(count); }
