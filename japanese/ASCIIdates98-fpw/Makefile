# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ASCIIdates98-fpw
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/ASCIIdates98/
DISTNAME=	${PORTNAME:S/-fpw//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese dictionary for PC terms in '98 ASCII Dates Book (EPWING V1 format)

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ascdates
EXTRACT_BEFORE_ARGS=	-qL

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/share/dict/ASCIIdates98-fpw/ascdates/data
	${INSTALL_DATA} ${WRKSRC}/ascdates/data/honmon ${PREFIX}/share/dict/ASCIIdates98-fpw/ascdates/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/ASCIIdates98-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
