PORTNAME=	simpleitk
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.1 # last version compatible with InsightToolkit-5.2.1, next versions require InsightToolkit-5.3-RC*
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simplification layer built on top of the Insight Toolkit (ITK)
WWW=		https://simpleitk.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libITKCommon-${ITK_VER}.so:science/InsightToolkit
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++14-lang eigen:3 lua:53 # tests fail to configure due to GTest::GTest related issues, tests might work in newer versions
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SimpleITK
GH_PROJECT=	SimpleITK

CMAKE_OFF=	WRAP_DEFAULT
CMAKE_OFF+=	BUILD_TESTING BUILD_EXAMPLES
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DSimpleITK_LUA_EXECUTABLE=${LUA_CMD}
CMAKE_TESTING_ON=	BUILD_TESTING

PLIST_SUB+=	VER=${DISTVERSION:R}

post-install: # remove contentless docs
	@${RM} -r ${STAGEDIR}${PREFIX}/share

.include <../../science/InsightToolkit/Makefile.version>
.include <bsd.port.mk>
