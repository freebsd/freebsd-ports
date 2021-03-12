# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	taglib
DISTVERSION=	1.12
CATEGORIES=	audio
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://taglib.org/releases/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for manipulating ID3 tags and Ogg comments

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING.MPL

TEST_DEPENDS=	cppunit-config:devel/cppunit

USES=		cmake compiler:c++11-lang cpe pathfix
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_CXX_VISIBILITY_PRESET=hidden
CMAKE_ON=	VISIBILITY_HIDDEN \
		WITH_ASF \
		WITH_MP4

OPTIONS_DEFINE=	RCC STATIC TEST
OPTIONS_SUB=	yes

# The official patches for this can be obtained from:
#   http://darksoft.org/files/rusxmms/patches/
#
RCC_DESC=		Build with RusXMMS librcc patches (experimental)
RCC_LIB_DEPENDS=	librcc.so:devel/librcc
RCC_USES=		localbase:ldflags
RCC_EXTRA_PATCHES=	${FILESDIR}/extrapatch-rcc

STATIC_CMAKE_BOOL_OFF=	BUILD_SHARED_LIBS

TEST_BUILD_DEPENDS=	cppunit-config:devel/cppunit
TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_TARGET=		check
TEST_IMPLIES=		STATIC

post-patch-RCC-on:
	@${REINPLACE_CMD} -e 's|-ltag|-ltag -lrcc|g' \
		${WRKSRC}/taglib.pc.cmake ${WRKSRC}/taglib-config.cmake
	@${REINPLACE_CMD} -e 's|-ltag_c|-ltag_c -lrcc|g' \
		${WRKSRC}/bindings/c/taglib_c.pc.cmake

.include <bsd.port.mk>
