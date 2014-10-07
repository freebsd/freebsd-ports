# $FreeBSD$

PORTNAME=	libetonyek
PORTVERSION=	0.0.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library to interpret and import Apple Keynote presentations

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd \
		libxml2.so:${PORTSDIR}/textproc/libxml2

OPTIONS_DEFINE=	TEST

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes
USES=		gmake gperf libtool:keepla pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

TEST_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/cppunit.pc:${PORTSDIR}/devel/cppunit
TEST_CONFIGURE_OFF=	--disable-tests

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST}
post-build:
	@cd ${WRKSRC}/src/test && ${MAKE_CMD} check
.endif

post-stage:
	@${RM} -f ${STAGEDIR}${PREFIX}/bin/key*

.include <bsd.port.mk>
