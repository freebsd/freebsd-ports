# New ports collection makefile for:	freecol
# Date created:			31 March 2007
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freecol
PORTVERSION=	0.8.3
CATEGORIES=	games java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An open source version of Colonization

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_JAVA=	yes
JAVA_VERSION=	1.5+

.if defined(NOPORTDATA)
IGNORE=		needs data file to run, unset NOPORTDATA
.endif

PLIST_FILES=	bin/freecol
PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="FreeCol" "${COMMENT}" "${DATADIR}/freecol.xpm" "freecol" "Game;ArcadeGame;" false

post-patch:
	@${REINPLACE_CMD} 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/freecol

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/freecol ${PREFIX}/bin/
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/FreeCol.jar ${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/freecol.xpm ${DATADIR}/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR}/)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} jars ${DATADIR}/)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/FreeCol.pdf ${DOCSDIR}/
.endif

.include <bsd.port.mk>
