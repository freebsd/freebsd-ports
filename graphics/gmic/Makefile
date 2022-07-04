PORTNAME=	gmic
DISTVERSION=	3.1.5
CATEGORIES=	graphics
MASTER_SITES=	https://gmic.eu/files/source/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for image processing

LICENSE=	CeCILL
LICENSE_NAME=	CeCILL
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_i386=	error: "c++ crashes, clang-5 and 6 fail: undefined reference to `__atomic_load'"

BUILD_DEPENDS=	gimptool-2.0:graphics/gimp-app
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libGraphicsMagick++.so:graphics/GraphicsMagick \
		libOpenEXR.so:graphics/openexr \
		libImath.so:math/Imath \
		libopencv_core.so:graphics/opencv \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		compiler:c++11-lang gettext-runtime gmake jpeg localbase:ldflags pkgconfig xorg
USE_LDCONFIG=	yes
USE_XORG=	x11 xau xcb xdmcp

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	lib

PORTSCOUT=	limit:[0-9]\..* # not v.220 and similar

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgmic.so.*

.include <bsd.port.mk>
