# $FreeBSD$

PORTNAME=	libetonyek
PORTVERSION=	0.0.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library to interpret and import Apple Keynote presentations

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	gperf:${PORTSDIR}/devel/gperf
LIB_DEPENDS=	libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd \
		libxml2.so:${PORTSDIR}/textproc/libxml2

OPTIONS_DEFINE=	DOCS TEST

CONFIGURE_ARGS=	--disable-werror
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes
USES=		gmake libtool:keepla pathfix pkgconfig
USE_LDCONFIG=	yes
USE_XZ=		yes

PORTDOCS=	*
DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs
TEST_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/cppunit.pc:${PORTSDIR}/devel/cppunit
TEST_CONFIGURE_OFF=	--disable-tests

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST}
post-build:
	@cd ${WRKSRC}/src/test && ${GMAKE} check
.endif

.include <bsd.port.mk>
