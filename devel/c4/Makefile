# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	c4
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES+=	devel
MASTER_SITES=	http://public.perforce.com/public/perforce/utils/c4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CVS-like Frontend to Perforce

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

ALL_TARGET=	c4

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/c4 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/c4.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/c4.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/c4.ps ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
