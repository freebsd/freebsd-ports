# $FreeBSD$

PORTNAME=	libetonyek
PORTVERSION=	0.1.6
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://dev-www.libreoffice.org/src/${PORTNAME}/
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library to interpret and import Apple Keynote presentations

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/mdds-1.2/mdds/global.hpp:devel/mdds \
		${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		librevenge-0.0.so:textproc/librevenge \
		liblangtag.so:devel/liblangtag \
		libxml2.so:textproc/libxml2

OPTIONS_DEFINE=	TEST

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c++11-lib gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

TEST_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/cppunit.pc:devel/cppunit
TEST_CONFIGURE_OFF=	--disable-tests

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST}
post-build:
	@cd ${WRKSRC}/src/test && ${MAKE_CMD} check
.endif

.include <bsd.port.mk>
