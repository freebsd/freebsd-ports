# $FreeBSD$

PORTNAME=	jpeg-xl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	JPEG XL reference encoder/decoder

LICENSE=	APACHE20 BSD3CLAUSE ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/third_party/skcms/LICENSE
LICENSE_FILE_ZLIB=	${WRKSRC}/third_party/lodepng/LICENSE

LIB_DEPENDS=	libbrotlienc.so:archivers/brotli

USES=		cmake compiler:c++11-lib pkgconfig shared-mime-info
USE_GITHUB=	nodefault
USE_GITLAB=	yes
USE_LDCONFIG=	yes
GH_TUPLE=	barmco:skcms:6437475:skcms/third_party/skcms \
		google:highway:v0.7.0:highway/third_party/highway \
		lvandeve:lodepng:48e5364:lodepng/third_party/lodepng \
		webmproject:sjpeg:868ab55:sjpeg/third_party/sjpeg \
		${NULL}
GL_ACCOUNT=	wg1
GL_COMMIT=	e2b1e60f5fda02f5fb395b0b6113f64d33cbb91d
CMAKE_ON=	JPEGXL_ENABLE_PLUGINS
CMAKE_OFF=	JPEGXL_WARNINGS_AS_ERRORS ${BENCHMARK FUZZERS TCMALLOC:L:S/^/JPEGXL_ENABLE_/}
CMAKE_OFF+=	${OpenGL GLUT:L:S/^/CMAKE_DISABLE_FIND_PACKAGE_/} # sjpeg
LDFLAGS+=	-Wl,--as-needed # brotlicommon, GIMP/OPENEXR/PNG deps

OPTIONS_DEFINE=	GIF GIMP JPEG LTO OPENEXR PIXBUF PNG TEST
OPTIONS_DEFAULT=GIF GIMP JPEG LTO OPENEXR PIXBUF PNG
OPTIONS_EXCLUDE_i386=	LTO # ConvolutionWithTranspose(): JXL_CHECK: out->xsize() == in.ysize()
OPTIONS_EXCLUDE_powerpc64=	${"${/usr/bin/ld:L:tA}"==/usr/bin/ld.lld:?LTO:} # LLVM bug 47353
OPTIONS_SUB=	yes

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_GIF

GIMP_DESC=		GIMP plugin support
GIMP_LIB_DEPENDS=	libgegl-0.4.so:graphics/gegl \
			libgimp-2.0.so:graphics/gimp-app \
			libbabl-0.1.so:x11/babl

JPEG_USES=		jpeg
JPEG_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_JPEG

LTO_CMAKE_BOOL=		CMAKE_INTERPROCEDURAL_OPTIMIZATION
LTO_CMAKE_ON=		-DCMAKE_POLICY_DEFAULT_CMP0069:STRING=NEW
.if exists(/usr/bin/ld.lld) && ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
# --plugin isn't supported by old GNU ld.bfd in base
LTO_LDFLAGS=		-fuse-ld=lld
.endif

OPENEXR_LIB_DEPENDS=	libHalf.so:graphics/ilmbase \
			libIlmImf.so:graphics/openexr
OPENEXR_CMAKE_BOOL=	JPEGXL_ENABLE_OPENEXR

PIXBUF_USES=		gnome
PIXBUF_USE=		GNOME=gdkpixbuf2

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_PNG

TEST_BUILD_DEPENDS=	googletest>0:devel/googletest
TEST_USES=		localbase:ldflags
TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} 's,/usr,${LOCALBASE},' \
		${WRKSRC}/plugins/gdk-pixbuf/jxl.thumbnailer

# pkg_check_modules doesn't support CMAKE_DISABLE_*
post-patch-GIMP-off:
	@${REINPLACE_CMD} -i.nogimp '/gimp/d' ${WRKSRC}/plugins/CMakeLists.txt
post-patch-PIXBUF-off:
	@${REINPLACE_CMD} -i.nopixbuf '/gdk-pixbuf/d' ${WRKSRC}/plugins/CMakeLists.txt

pre-install-TEST-on:	do-test

.include <bsd.port.mk>
