# New ports collection makefile for:	ASCIIdates98 Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ASCIIdates98-fpw
PORTVERSION=	1.0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/ASCIIdates98/
DISTNAME=	${PORTNAME:S/-fpw//}-${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ascdates
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/ASCIIdates98-fpw/ascdates/data
	${INSTALL_DATA} ${WRKSRC}/ascdates/data/honmon ${PREFIX}/share/dict/ASCIIdates98-fpw/ascdates/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/ASCIIdates98-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ASCIIdates98-fpw
.for i in readme
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/ASCIIdates98-fpw
.endfor
.endif

.include <bsd.port.mk>
