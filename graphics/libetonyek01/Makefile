# $FreeBSD$

PORTNAME=	libetonyek
PORTVERSION=	0.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://dev-www.libreoffice.org/src/
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library to interpret and import Apple Keynote presentations

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

USES=		gperf
LIB_DEPENDS=	libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		librevenge-0.0.so:${PORTSDIR}/textproc/librevenge \
		libxml2.so:${PORTSDIR}/textproc/libxml2

OPTIONS_DEFINE=	TEST

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

TEST_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/cppunit.pc:${PORTSDIR}/devel/cppunit
TEST_CONFIGURE_OFF=	--disable-tests

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST}
post-build:
	@cd ${WRKSRC}/src/test && ${MAKE_CMD} check
.endif

.include <bsd.port.mk>
