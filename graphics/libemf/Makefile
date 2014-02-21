# Created by: NAKATA Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libEMF
PORTVERSION=	1.0.7
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Enhanced Metafile Library

OPTIONS_DEFINE=	DOCS

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
