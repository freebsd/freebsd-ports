PORTNAME=	ampasCTL
PORTVERSION=	1.5.5
CATEGORIES=	graphics devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Color Transformation Language interpreter
WWW=		https://github.com/ampas/CTL

LICENSE=	AMPAS
LICENSE_NAME=	AMPAS
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libImath.so:math/Imath \
		libOpenEXR.so:graphics/openexr \
		libtiff.so:graphics/tiff

USES=		cmake:testing compiler:c++11-lang localbase:ldflags pathfix \
		pkgconfig

USE_CXXSTD=	c++11

USE_GITHUB=	yes
GH_ACCOUNT=	aces-aswf
GH_PROJECT=	CTL
GH_TAGNAME=	ctl-${PORTVERSION}

CMAKE_OFF=		CTL_BUILD_TESTS
CMAKE_TESTING_ON=	CTL_BUILD_TESTS

DOCSDIR=	${PREFIX}/share/doc/CTL

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
