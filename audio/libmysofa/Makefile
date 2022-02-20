PORTNAME=	libmysofa
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1-16
DISTVERSIONSUFFIX=	-g52590e1
CATEGORIES=	audio

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	SOFA (Spatially Oriented Format for Acoustics) file reader

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	node:www/node

USES=		cmake cpe
USE_LDCONFIG=	yes

CPE_VENDOR=	symonics

USE_GITHUB=	yes
GH_ACCOUNT=	hoene

OPTIONS_DEFINE=		TEST
OPTIONS_SUB=		yes

TEST_BUILD_DEPENDS=	cunit>0:devel/cunit
TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_TEST_TARGET=	test

# The tests are expected to be in ../tests relative to the build
# directory and the build results are expected to be in build/ relative
# to ${WRKSRC}.  USES=cmake does not allow overwriting ${WRKDIR}/.build
# as the build directory.
post-patch:
	@${RLN} ${WRKSRC}/build ${CONFIGURE_WRKSRC}

.include <bsd.port.mk>
