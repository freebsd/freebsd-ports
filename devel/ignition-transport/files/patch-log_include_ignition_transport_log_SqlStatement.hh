--- log/include/ignition/transport/log/SqlStatement.hh.orig	2018-11-20 22:07:06 UTC
+++ log/include/ignition/transport/log/SqlStatement.hh
@@ -59,22 +59,22 @@ namespace ignition
 
         /// \sa Set(std::nullptr_t)
         /// \brief Construct NULL parameter
-        public: explicit SqlParameter(std::nullptr_t);
+        public: SqlParameter(std::nullptr_t);
 
         /// \sa Set(int64_t)
         /// \brief Construct integer parameter
         /// \param[in] _integer an integer
-        public: explicit SqlParameter(int64_t _integer);
+        public: SqlParameter(int64_t _integer);
 
         /// \sa Set(double)
         /// \brief Construct real parameter
         /// \param[in] _real a real number
-        public: explicit SqlParameter(double _real);
+        public: SqlParameter(double _real);
 
         /// \sa Set(const std::string &)
         /// \brief Construct string parameter
         /// \param[in] _string a string
-        public: explicit SqlParameter(const std::string &_text);
+        public: SqlParameter(const std::string &_text);
 
         /// \brief Copy constructor
         /// \param[in] _other Another SqlParameter
