# $FreeBSD$

PORTNAME=	libpuzzle
PORTVERSION=	0.11
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/releases/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Library to find similar pictures

LICENSE=	BSD

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS NEWS README THANKS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
