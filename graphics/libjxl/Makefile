PORTNAME=	libjxl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	adb32f3f8f37.patch:-p1 # https://github.com/libjxl/libjxl/pull/193
PATCHFILES+=	c31dca74e68f.patch:-p1 # https://github.com/libjxl/libjxl/pull/678

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	JPEG XL reference encoder/decoder

LICENSE=	BSD3CLAUSE ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_ZLIB=	${WRKSRC}/third_party/lodepng/LICENSE

BUILD_DEPENDS=	highway>0:devel/highway
LIB_DEPENDS=	libbrotlienc.so:archivers/brotli
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lib cpe localbase:ldflags pkgconfig shared-mime-info
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_TUPLE=	barmco:skcms:6437475:skcms/third_party/skcms \
		lvandeve:lodepng:48e5364:lodepng/third_party/lodepng \
		webmproject:sjpeg:868ab55:sjpeg/third_party/sjpeg \
		${NULL}
CMAKE_ON=	JPEGXL_ENABLE_PLUGINS
CMAKE_OFF=	JPEGXL_WARNINGS_AS_ERRORS ${BENCHMARK FUZZERS TCMALLOC:L:S/^/JPEGXL_ENABLE_/}
CMAKE_OFF+=	${OpenGL GLUT:L:S/^/CMAKE_DISABLE_FIND_PACKAGE_/} # sjpeg
CMAKE_OFF+=	${CMAKE_TESTING_ON}
LDFLAGS+=	-Wl,--as-needed # brotlicommon, GIMP/OPENEXR/PNG deps

OPTIONS_DEFINE=	GIF GIMP JPEG LTO MANPAGES OPENEXR PIXBUF PNG
OPTIONS_DEFAULT=GIF GIMP JPEG LTO MANPAGES OPENEXR PIXBUF PNG
OPTIONS_EXCLUDE_i386=	LTO # ConvolutionWithTranspose(): JXL_CHECK: out->xsize() == in.ysize()
OPTIONS_EXCLUDE_powerpc64=	${"${/usr/bin/ld:L:tA}"==/usr/bin/ld.lld:?LTO:} # https://github.com/llvm/llvm-project/issues/46697
OPTIONS_SUB=	yes

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_GIF

GIMP_DESC=		GIMP plugin support
GIMP_USES=		gnome
GIMP_USE=		GNOME=gtk20
GIMP_LIB_DEPENDS=	libgegl-0.4.so:graphics/gegl \
			libgimp-2.0.so:graphics/gimp-app \
			libbabl-0.1.so:x11/babl

JPEG_USES=		jpeg
JPEG_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_JPEG

LTO_CMAKE_BOOL=		CMAKE_INTERPROCEDURAL_OPTIMIZATION
LTO_CMAKE_ON=		-DCMAKE_POLICY_DEFAULT_CMP0069:STRING=NEW

MANPAGES_BUILD_DEPENDS=	a2x:textproc/asciidoc
MANPAGES_USES=		python:build
MANPAGES_CMAKE_BOOL=	JPEGXL_ENABLE_MANPAGES

OPENEXR_LIB_DEPENDS=	libImath.so:math/Imath \
			libOpenEXR.so:graphics/openexr
OPENEXR_CMAKE_BOOL=	JPEGXL_ENABLE_OPENEXR

PIXBUF_USES=		gnome
PIXBUF_USE=		GNOME=gdkpixbuf2

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_PNG

post-patch:
	@${REINPLACE_CMD} 's,/usr,${LOCALBASE},' \
		${WRKSRC}/plugins/gdk-pixbuf/jxl.thumbnailer

# pkg_check_modules doesn't support CMAKE_DISABLE_*
post-patch-GIMP-off:
	@${REINPLACE_CMD} -i.nogimp '/gimp/d' ${WRKSRC}/plugins/CMakeLists.txt
post-patch-PIXBUF-off:
	@${REINPLACE_CMD} -i.nopixbuf '/gdk-pixbuf/d' ${WRKSRC}/plugins/CMakeLists.txt

.include <bsd.port.mk>
