PORTNAME=	libjxl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	JPEG XL reference encoder/decoder
WWW=		https://jpeg.org/jpegxl/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbrotlienc.so:archivers/brotli \
		libhwy.so:devel/highway
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lib cpe localbase:ldflags pkgconfig shared-mime-info
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_TUPLE=	jbeich:skcms:b25b07b:skcms/third_party/skcms \
		libjxl:testdata:d6168ff:testdata/testdata \
		webmproject:sjpeg:868ab55:sjpeg/third_party/sjpeg \
		${NULL}
CFLAGS_powerpc64=	-DHWY_DISABLE_PPC8_CRYPTO
CFLAGS_powerpc=	-DHWY_DISABLE_PPC8_CRYPTO
CMAKE_ON=	JPEGXL_ENABLE_PLUGINS
CMAKE_OFF=	${BENCHMARK FUZZERS TCMALLOC:L:S/^/JPEGXL_ENABLE_/}
CMAKE_OFF+=	${OpenGL GLUT:L:S/^/CMAKE_DISABLE_FIND_PACKAGE_/} # sjpeg
CMAKE_OFF+=	${CMAKE_TESTING_ON}
LDFLAGS+=	-Wl,--as-needed # brotlicommon, OPENEXR/PNG deps

OPTIONS_DEFINE=	GIF JPEG LTO MANPAGES OPENEXR PIXBUF PNG
OPTIONS_DEFAULT=GIF JPEG LTO MANPAGES OPENEXR PIXBUF PNG
OPTIONS_EXCLUDE_i386=	LTO # ConvolutionWithTranspose(): JXL_CHECK: out->xsize() == in.ysize()
OPTIONS_EXCLUDE_powerpc64=	${"${/usr/bin/ld:L:tA}"==/usr/bin/ld.lld:?LTO:} # https://github.com/llvm/llvm-project/issues/46697
OPTIONS_EXCLUDE_riscv64=	LTO # bug 262871
OPTIONS_SUB=	yes

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_GIF

JPEG_USES=		jpeg
JPEG_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_JPEG

LTO_CMAKE_BOOL=		CMAKE_INTERPROCEDURAL_OPTIMIZATION
LTO_CMAKE_ON=		-DCMAKE_POLICY_DEFAULT_CMP0069:STRING=NEW

MANPAGES_BUILD_DEPENDS=	a2x:textproc/asciidoc
MANPAGES_USES=		python:build
MANPAGES_CMAKE_BOOL=	JPEGXL_ENABLE_MANPAGES

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr
OPENEXR_CMAKE_BOOL=	JPEGXL_ENABLE_OPENEXR

PIXBUF_USES=		gnome
PIXBUF_USE=		GNOME=gdkpixbuf2
PIXBUF_CMAKE_BOOL=	JPEGXL_ENABLE_PLUGIN_GDKPIXBUF

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_PNG

post-patch:
	@${REINPLACE_CMD} 's,/usr,${LOCALBASE},' \
		${WRKSRC}/plugins/gdk-pixbuf/jxl.thumbnailer

.include <bsd.port.mk>
