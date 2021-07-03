# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	simpleviewer
PORTVERSION=	3.1.7
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/andreyu/simple-viewer-gl/get/
DISTNAME=	v${PORTVERSION}	# version tag, has no embedded ${PORTNAME}
DIST_SUBDIR=	${PORTNAME}	# and that's why we need ${DIST_SUBDIR}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small and simple image viewer based on OpenGL

LICENSE=	GPLv2

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libglfw.so:graphics/glfw \
		liblz4.so:archivers/liblz4 \
		libpng.so:graphics/png

USES=		cmake:insource compiler:c++11-lang gl jpeg pkgconfig \
		tar:bzip2 xorg
USE_GL=		gl glu
USE_XORG=	ice sm x11 xcursor xext xinerama xrandr xxf86vm
CMAKE_ARGS=	-DAPP_VERSION_MAJOR:STRING=${PORTVERSION:S/./ /g:[1]} \
		-DAPP_VERSION_MINOR:STRING=${PORTVERSION:S/./ /g:[2]} \
		-DAPP_VERSION_RELEASE:STRING=${PORTVERSION:S/./ /g:[3]}

WRKSRC=		${WRKDIR}/andreyu-simple-viewer-gl-d8928067922d

PLIST_FILES=	bin/sviewgl ${DATADIR_REL}/Icon-1024.png \
		${DATADIR_REL}/Icon-16.png ${DATADIR_REL}/Icon-32.png
PORTDOCS=	README.md
PORTEXAMPLES=	config.example
SUB_FILES=	pkg-message

EXTRA_FEATURES=	CURL GIF IMLIB2 JPEG2000 LCMS2 LIBEXIF OPENEXR TIFF WEBP
OPTIONS_DEFINE=	DOCS EXAMPLES ${EXTRA_FEATURES}
OPTIONS_DEFAULT=	${EXTRA_FEATURES}

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CMAKE_OFF=		-DDISABLE_CURL_SUPPORT:STRING=1

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CMAKE_OFF=		-DDISABLE_GIF_SUPPORT:STRING=1

IMLIB2_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
IMLIB2_CMAKE_OFF=	-DDISABLE_IMLIB2_SUPPORT:STRING=1

JPEG2000_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
JPEG2000_CMAKE_OFF=	-DDISABLE_JPEG2000_SUPPORT:STRING=1

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_CMAKE_OFF=	-DDISABLE_LCMS2_SUPPORT:STRING=1

LIBEXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
LIBEXIF_CMAKE_OFF=	-DDISABLE_EXIF_SUPPORT:STRING=1

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
			libImath.so:math/Imath
OPENEXR_CMAKE_OFF=	-DDISABLE_OPENEXR_SUPPORT:STRING=1

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_OFF=		-DDISABLE_TIFF_SUPPORT:STRING=1

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CMAKE_OFF=		-DDISABLE_WEBP_SUPPORT:STRING=1

post-patch:
	@${REINPLACE_CMD} -e '/#include/s,lz4/,,' \
		${WRKSRC}/src/formats/formatage.cpp
	@${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},' \
		${WRKSRC}/src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sviewgl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/res/Icon-*.png ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config.example ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

JPEG2000_DESC+=	via OpenJPEG
