--- apps/swrx/IQStream.hpp.orig	2012-06-27 22:22:33 +0800
+++ apps/swrx/IQStream.hpp
@@ -130,6 +130,9 @@ namespace gpstk
    inline IQStream& operator<<(IQStream& s, const std::complex<float>& v)
    { s.writeComplex(v); return s; };
 
+   inline IQStream& operator<<(IQStream& s, const std::complex<double>& v)
+   { s.writeComplex(v); return s; };
+
 
    class IQ1Stream : public IQStream
    {
