--- src/directory.h.orig	Fri Aug  4 09:26:00 2000
+++ src/directory.h	Sat Sep  7 10:46:20 2002
@@ -89,7 +89,7 @@
 			
 			class proxy
 			{
-				friend dir_it;
+				friend class dir_it;
 				proxy(std::string const &ent): entry(ent) {}
 			public:
 				std::string operator*() const { return entry; }
@@ -296,31 +296,33 @@
 
 		class unknown_uid: public std::invalid_argument
 		{
-		public:
-			unknown_uid(uid_t u): std::invalid_argument("unknown user ID"), m_uid(u) {}
-			uid_t uid() const { return m_uid; }
 		private:
 			uid_t m_uid;
+		public:
+			unknown_uid(uid_t u) throw() : std::invalid_argument("unknown user ID"), m_uid(u) {}
+			~unknown_uid() throw() {}
+			uid_t uid() const { return m_uid; }
 		};
 		struct uid { typedef uid_t value_type; };
 		template<> uid_t get<uid>(dir_it const &);
 		template<> void set<uid>(dir_it const &, uid_t);
-		class unknown_uname: public invalid_argument
+		class unknown_uname: public std::invalid_argument
 		{
-		public:
-			unknown_uname(string u): std::invalid_argument("unknown user name"), m_uname(u) {}
-			string uname() const { return m_uname; }
 		private:
-			string m_uname;
+			std::string m_uname;
+		public:
+			unknown_uname(std::string u) throw() : std::invalid_argument("unknown user name"), m_uname(u) {}
+			~unknown_uname() throw () {}
+			std::string uname() const { return m_uname; }
 		};
-		struct uname { typedef string value_type; };
-		template<> string get<uname>(dir_it const &);
-		template<> void set<uname>(dir_it const &, string );
+		struct uname { typedef std::string value_type; };
+		template<> std::string get<uname>(dir_it const &);
+		template<> void set<uname>(dir_it const &, std::string );
 
-		class unknown_gid: public invalid_argument
+		class unknown_gid: public std::invalid_argument
 		{
 		public:
-			unknown_gid(gid_t g): std::invalid_argument("unknown group ID"), m_gid(g) {}
+			unknown_gid(gid_t g) throw() : std::invalid_argument("unknown group ID"), m_gid(g) {}
 			gid_t gid() const { return m_gid; }
 		private:
 			gid_t m_gid;
@@ -328,17 +330,18 @@
 		struct gid { typedef gid_t value_type; };
 		template<> gid_t get<gid>(dir_it const &);
 		template<> void set<gid>(dir_it const &, gid_t);
-		class unknown_gname: public invalid_argument
+		class unknown_gname: public std::invalid_argument
 		{
 		public:
-			unknown_gname(string g): std::invalid_argument("unknown group name"), m_gname(g) {}
-			string gname() const { return m_gname; }
+			unknown_gname(std::string g) throw() : std::invalid_argument("unknown group name"), m_gname(g) {}
+			~unknown_gname() throw() {}
+			std::string gname() const { return m_gname; }
 		private:
-			string m_gname;
+			std::string m_gname;
 		};
-		struct gname { typedef string value_type; };
-		template<> string get<gname>(dir_it const &);
-		template<> void set<gname>(dir_it const &, string );
+		struct gname { typedef std::string value_type; };
+		template<> std::string get<gname>(dir_it const &);
+		template<> void set<gname>(dir_it const &, std::string );
 
 #endif
 
@@ -352,9 +355,9 @@
 	{
 	public:
 		typedef ptrdiff_t          difference_type;
-		typedef string             value_type;
-		typedef string             *pointer;
-		typedef string             &reference;
+		typedef std::string             value_type;
+		typedef std::string             *pointer;
+		typedef std::string             &reference;
 		typedef input_iterator_tag iterator_category;
 	};
 } // namespace std
