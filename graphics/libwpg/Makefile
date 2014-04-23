# $FreeBSD$

PORTNAME=	libwpg
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools to work with WordPerfect Graphics (WPG) files

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	libwpd-0.9.so:${PORTSDIR}/textproc/libwpd

USES=		libtool:keepla pathfix perl5 pkgconfig
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-werror

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
PORTDOCS=	*

.include <bsd.port.mk>
