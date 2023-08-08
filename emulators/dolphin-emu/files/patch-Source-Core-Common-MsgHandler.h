commit 66f330e57316257fe81b46f57dad22ea6dee7bae
Author: Christopher Rudolph <rudolchr@b-tu.de>
Date:   Sat Jul 9 17:02:09 2022 +0200

    Add a check for libfmt version so that in case libfmt-9 is used the function is_compile_string is called under it's new namespace

--- Source/Core/Common/MsgHandler.h.orig	2022-07-06 07:23:55 UTC
+++ Source/Core/Common/MsgHandler.h
@@ -41,7 +41,11 @@ bool MsgAlertFmt(bool yes_no, MsgType style, Common::L
   static_assert(NumFields == sizeof...(args),
                 "Unexpected number of replacement fields in format string; did you pass too few or "
                 "too many arguments?");
+#if FMT_VERSION >= 90000
+  static_assert(fmt::detail::is_compile_string<S>::value);
+#else
   static_assert(fmt::is_compile_string<S>::value);
+#endif
   return MsgAlertFmtImpl(yes_no, style, log_type, file, line, format,
                          fmt::make_format_args(args...));
 }
@@ -56,7 +60,11 @@ bool MsgAlertFmtT(bool yes_no, MsgType style, Common::
   static_assert(NumFields == sizeof...(args),
                 "Unexpected number of replacement fields in format string; did you pass too few or "
                 "too many arguments?");
+#if FMT_VERSION >= 90000
+  static_assert(fmt::detail::is_compile_string<S>::value);
+#else
   static_assert(fmt::is_compile_string<S>::value);
+#endif
   auto arg_list = fmt::make_format_args(args...);
   return MsgAlertFmtImpl(yes_no, style, log_type, file, line, translated_format, arg_list);
 }
