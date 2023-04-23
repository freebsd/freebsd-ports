PORTNAME=	simpleitk
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simplification layer built on top of the Insight Toolkit (ITK)
WWW=		https://simpleitk.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	clang consistently runs out of memory
BROKEN_i386=	clang consistently runs out of memory

LIB_DEPENDS=	libgdcmCommon.so:devel/gdcm \
		libhdf5.so:science/hdf5 \
		libITKCommon-${ITK_VER}.so:science/InsightToolkit \
		libvnl.so:misc/vxl
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++14-lang eigen:3 lua:53 # tests fail to configure due to GTest::GTest related issues, see also https://github.com/SimpleITK/SimpleITK/issues/1765
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SimpleITK
GH_PROJECT=	SimpleITK

CMAKE_OFF=	WRAP_DEFAULT
CMAKE_OFF+=	BUILD_TESTING BUILD_EXAMPLES
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DSimpleITK_LUA_EXECUTABLE=${LUA_CMD}
CMAKE_TESTING_ON=	BUILD_TESTING # tests fail to find GTest, see https://github.com/SimpleITK/SimpleITK/issues/1807

PLIST_SUB+=	VER=${DISTVERSION:R}

BINARY_ALIAS=	git=false

post-install: # remove contentless docs
	@${RM} -r ${STAGEDIR}${PREFIX}/share

.include <../../science/InsightToolkit/Makefile.version>
.include <bsd.port.mk>
