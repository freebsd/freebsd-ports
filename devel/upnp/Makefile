# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	upnp
PORTVERSION=	1.6.22
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/p${PORTNAME}/p${PORTNAME}/libUPnP%20${PORTVERSION}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Universal Plug and Play Software Development Kit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		cpe libtool pathfix tar:bzip2
CPE_VENDOR=	libupnp_project
CPE_PRODUCT=	libupnp
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DEBUG DOCS

DEBUG_CONFIGURE_ON=	--enable-debug
DOCS_CONFIGURE_ON=	--with-documentation=${DOCSDIR}
DOCS_CONFIGURE_OFF=	--without-documentation

.include <bsd.port.mk>
