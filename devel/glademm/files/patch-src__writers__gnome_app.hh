--- src/writers/gnome_app.hh-	Sat Dec 16 12:43:19 2006
+++ src/writers/gnome_app.hh	Sat Dec 16 12:43:40 2006
@@ -28,7 +28,7 @@
 	virtual bool NeedExplicitCtor(const Widget &w) const;
 	virtual void ConstructionArgs(const Widget &w, CxxFile &f) const;
 	virtual void Configure(const Widget &w, CxxFile &f,const std::string &instance) const;
-	virtual Subwidget Gnome_App::IsSubwidget(const Widget &w,const Widget &ch) const;
+	virtual Subwidget IsSubwidget(const Widget &w,const Widget &ch) const;
 	virtual const std::string InternalInstance(const Widget &parent,const Widget &w2) const;
 	virtual void AddChildren(const Widget &w,CxxFile &f,const std::string &instance,const WriterBase &writer_for_subw, const Widget &widget_for_subw) const;
 };
