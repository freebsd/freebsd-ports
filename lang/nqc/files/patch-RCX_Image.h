--- rcxlib/RCX_Image.h.org	Sun Nov  9 06:14:23 2003
+++ rcxlib/RCX_Image.h	Tue Aug 17 12:58:19 2004
@@ -78,7 +78,6 @@
 	void		Clear();
 	int			GetSize() const;
 
-private:
 	class	Chunk
 	{
 	public:
@@ -106,6 +105,7 @@
 		friend class RCX_Image;
 	};
 	
+private:
 	struct	Variable
 	{
 		int		fIndex;
