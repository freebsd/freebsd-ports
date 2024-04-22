PORTNAME=	ctl
DISTVERSIONPREFIX=	ctl-
DISTVERSION=	1.5.3
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-language

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	3871cd7717fd184d9fbb667730d35f1a89391f09.patch:-p1 # FreeBSD compatibility patch: https://github.com/ampas/CTL/pull/145

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Color Transformation Language
WWW=		https://github.com/ampas/CTL

LICENSE=	AMPAS
LICENSE_NAME=	Academy of Motion Picture Arts and Sciences (A.M.P.A.S.) license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

LIB_DEPENDS=	libImath.so:math/Imath \
		libOpenEXR.so:graphics/openexr \
		libtiff.so:graphics/tiff

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	ampas
GH_PROJECT=	CTL

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	CTL_BUILD_TESTS
CMAKE_TESTING_ON=	CTL_BUILD_TESTS

DATADIR=	share/CTL
DOCSDIR=	share/doc/CTL

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
