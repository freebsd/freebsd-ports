PORTNAME=	ctl
DISTVERSIONPREFIX=	ctl-
DISTVERSION=	1.5.4
PORTREVISION=	2
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-language

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Color Transformation Language
WWW=		https://github.com/ampas/CTL

LICENSE=	AMPAS
LICENSE_NAME=	Academy of Motion Picture Arts and Sciences (A.M.P.A.S.) license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

LIB_DEPENDS=	libAcesContainer.so:graphics/ampasACES-container \
		libImath.so:math/Imath \
		libOpenEXR.so:graphics/openexr \
		libtiff.so:graphics/tiff

USES=		cmake:testing pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ampas
GH_PROJECT=	CTL

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	CTL_BUILD_TESTS
CMAKE_TESTING_ON=	CTL_BUILD_TESTS

DATADIR=	share/CTL
DOCSDIR=	share/doc/CTL

OPTIONS_DEFINE=	DOCS

# tests as of 1.5.4: 100% tests passed, 0 tests failed out of 220

.include <bsd.port.mk>
