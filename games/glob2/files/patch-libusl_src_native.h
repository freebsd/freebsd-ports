--- libusl/src/native.h.orig	2024-06-07 07:47:17 UTC
+++ libusl/src/native.h
@@ -42,7 +42,7 @@ struct NativeValuePrototype: Prototype (private)
 	template<typename Function>
 	void addMethod(const std::string& name, const boost::function<Function>& function)
 	{
-		BOOST_MPL_ASSERT(( boost::is_same<This, typename boost::function<Function>::arg1_type> ));
+		BOOST_MPL_ASSERT(( boost::is_same<This, typename boost::function_traits<Function>::arg1_type> ));
 		NativeCode* native = new NativeFunction<Function>(name, function, true);
 		Prototype::addMethod(native);
 	}
