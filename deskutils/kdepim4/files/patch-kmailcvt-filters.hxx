Index: filters.hxx
===================================================================
--- kmailcvt/filters.hxx	(revision 427509)
+++ kmailcvt/filters.hxx	(working copy)
@@ -86,7 +86,58 @@
     QString m_info;
 };
 
+/** Glorified QString[N] for (a) understandability (b) older gcc
+*   compatibility, see for instance 
+* http://mail.kde.org/pipermail/kmail-devel/2005-April/017690.html
+*/
+template <unsigned int size> class FolderStructureBase
+{
+public:
+	typedef QString NString[size];
+	/** Constructor. Need a default constructor for QValueList. */
+	FolderStructureBase() {} ;
 
+	/** Constructor. Turn N QStrings into a folder structure 
+	*   description. 
+	*/
+	FolderStructureBase(const NString &s)
+	{
+	    for(unsigned int i=0; i<size; i++) d[i]=s[i];
+	} ;
+
+	/** Copy Constructor. */
+	FolderStructureBase(const FolderStructureBase &s)
+	{
+	    for(unsigned int i=0; i<size; i++) d[i]=s[i];
+	} ;
+
+	/** Assignment operator. Does the same thing as 
+	*   the copy constructor.
+	*/
+	FolderStructureBase &operator =(const FolderStructureBase &s)
+	{
+	    for(unsigned int i=0; i<size; i++) d[i]=s[i];
+	    return *this;
+	} ;
+
+	/** Access the different fields. There doesn't seem to
+	*   be a real semantics for the fields.
+	*/
+	const QString operator [](unsigned int i) const
+	{
+	    if (i<size) return d[i]; else return QString::null;
+	} ;
+
+	/** Access the different fields, for writing. */
+	QString &operator [](unsigned int i)
+	{
+	    Q_ASSERT(i<size);
+	    if (i<size) return d[i]; else return d[0];
+	} ;
+private:
+	QString d[size];
+} ;
+
 #endif
 
 // vim: ts=2 sw=2 et