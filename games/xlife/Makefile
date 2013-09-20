# Created by: asami
# $FreeBSD$

PORTNAME=	xlife
PORTVERSION=	6.6.1
CATEGORIES=	games
MASTER_SITES=	http://litwr2.atspace.eu/xlife/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	John Horton Conway's Game of Life

LICENSE=	MIT GPLv2
LICENSE_COMB=	multi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_BZIP2=	yes
USE_XORG=	x11

MLINKS=		xlife.6 lifeconv.6
MAN6=		xlife.6
PORTDOCS=	*

DESKTOP_ENTRIES="XLife" "" "" "${PORTNAME}" "" false

DOC_FILES=	CHANGES DEVELOPMENT-TREE HACKING HOW-TO-INSTALL INSTALL \
		MISSED README SHORT-INFO changelog.debian changelog.openbsd

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${LN} -sf xlife.man ${WRKSRC}/xlife.6

pre-patch:
	@(${CAT} ${WRKDIR}/xlife6.6to6.6.1.patch | ${PATCH} -d ${WRKSRC} -p1 -s)

do-configure:
	@(cd ${WRKSRC} && ${SED} -e \
		's|/usr/games|$$(PREFIX)/bin| ; \
		 s|/usr/share|$$(PREFIX)/share| ; \
		 s|/usr/X11R6|$$(LOCALBASE)| ; \
		 s|-g -O3|$$(CFLAGS)| ; \
		 s|-lstdc++|| ; \
		 s|$$(CC) -o|$$(CXX) -o|' < Makefile.common > Makefile)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} xlife ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} table2r ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} xlife.6 ${MAN6PREFIX}/man/man6)
	@${LN} -sf xlife ${PREFIX}/bin/lifeconv
	@${MKDIR} ${DATADIR}/patterns
	@(cd ${WRKSRC}/patterns && ${COPYTREE_SHARE} . ${DATADIR}/patterns)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOC_FILES} ${DOCSDIR})
	@${MKDIR} ${DOCSDIR}/doc
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}/doc)
.endif

.include <bsd.port.mk>
