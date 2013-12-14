# $FreeBSD$

PORTNAME=	libwpg
PORTVERSION=	0.2.2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools to work with WordPerfect Graphics (WPG) files

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	libwpd-0.9.so:${PORTSDIR}/textproc/libwpd

USE_AUTOTOOLS=	libtool
USES=		pkgconfig perl5 pathfix
USE_GNOME=	gnomeprefix ltverhack
USE_BZIP2=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-werror

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PORTDOCS=	*
.else
post-patch:
	@${REINPLACE_CMD} -E '/^SUBDIRS = /s/docs//g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
