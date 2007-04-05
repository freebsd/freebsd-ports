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
WRKSRC=		${WRKDIR}/${DISTNAME}/source
MAKEFILE=	${WRKSRC}/makefile.bsd

PLIST_FILES=	bin/dungeoncrawl
PORTDOCS=	buglist.txt crawl.txt
MAN6=		dungeoncrawl.6

post-patch:
	@${REINPLACE_CMD} -e "s|g++|${CXX}|; \
		s|/tmp/CRAWLTEST/testdev|${PREFIX}/bin|; \
		s|crawl|dungeoncrawl|; \
		s|CFLAGS =|CFLAGS=${CXXFLAGS} |;" \
			${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dungeoncrawl ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/crawl.6 ${PREFIX}/man/man6/dungeoncrawl.6

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/docs/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
