# New ports collection makefile for:   dungeoncrawl
# Date created:        10 March 2003
# Whom:                refugee
#
# $FreeBSD$
#

PORTNAME=	dungeoncrawl
PORTVERSION=	4.0.0.b26
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.dungeoncrawl.org/dev/4.0.x/src/
DISTNAME=	dc${PORTVERSION:S/.//g}-src
EXTRACT_SUFX=	.tbz2

MAINTAINER=	refugee@vt.edu
COMMENT=	An old school roguelike game

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/source/

MAKEFILE=	${WRKSRC}/makefile.bsd

PLIST_SUB=	CRAWLDOCSDIR="${CRAWLDOCSDIR}"

CRAWLDOCSDIR?=	share/doc/${PORTNAME}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/${CRAWLDOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/crawl.txt ${PREFIX}/${CRAWLDOCSDIR}
.endif

.include <bsd.port.mk>
