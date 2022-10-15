--- sources/xray_re/xr_image_dds.cxx.orig	2018-09-02 12:42:44 UTC
+++ sources/xray_re/xr_image_dds.cxx
@@ -7,6 +7,7 @@
 #include <nvmath/Color.h>
 #include <nvtt/nvtt.h>
 #pragma warning(pop)
+#undef sqrt
 #include "xr_image.h"
 #include "xr_file_system.h"
 
@@ -14,13 +15,14 @@ bool xr_image::load_dds(const std::string& path)
 
 bool xr_image::load_dds(const std::string& path)
 {
-	nv::DirectDrawSurface dds(path.c_str());
+	nv::DirectDrawSurface dds;
+	dds.load(path.c_str());
 	if (!dds.isValid() || !dds.isTexture2D())
 		return false;
 	nv::Image image;
-	dds.mipmap(&image, 0, 0);
-	m_width = image.width();
-	m_height = image.height();
+	imageFromDDS(&image, dds, 0, 0);
+	m_width = image.width;
+	m_height = image.height;
 	m_data = new rgba32[m_width*m_height];
 	for (unsigned i = m_height*m_width; i > 0;) {
 		const nv::Color32& pix = image.pixel(--i);
@@ -50,6 +52,7 @@ struct dds_writer: public nvtt::OutputHandler {
 			dds_writer(xr_writer& _w);
 
 	virtual void	beginImage(int size, int width, int height, int depth, int face, int miplevel);
+	virtual void	endImage();
 	virtual bool	writeData(const void* data, int size);
 	xr_writer&	w;
 };
@@ -60,6 +63,10 @@ void dds_writer::beginImage(int size, int width, int h
 {
 }
 
+void dds_writer::endImage()
+{
+}
+
 bool dds_writer::writeData(const void* data, int size)
 {
 	w.w_raw(data, size_t(size & INT_MAX));
