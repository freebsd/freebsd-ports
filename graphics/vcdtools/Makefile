# ex:ts=8
# New ports collection makefile for:	vcdtools
# Date created:	 	Mar 9, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vcdtools
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.mpegnews.com/files/video/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkvcdfs ${WRKSRC}/vcdmplex ${PREFIX}/bin
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${DOCSDIR}
.endif

.include <bsd.port.mk>
