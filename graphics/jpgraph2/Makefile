# Ports collection makefile for:	jpgraph2
# Date created:			7 Dec 2006
# Whom:				Alex Dupre <ale@FreeBSD.org:
#
# $FreeBSD$
#

PORTNAME=	jpgraph
PORTVERSION=	2.1.4
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://web.comhem.se/jpgraph/jpgdownloads/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Draw both "quick and dirty" graphs with a minimum of code

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//}
USE_PHP=	gd
IGNORE_WITH_PHP=4

NO_CDROM=	The free version cannot be used in a commercial context

PORTDOCS=	*

LATEST_LINK=	jpgraph2

do-install:
	@${MKDIR} ${DATADIR}/lang
	${CP} ${WRKSRC}/src/*.php ${DATADIR}
	${CP} ${WRKSRC}/src/*.inc ${DATADIR}
	${CP} ${WRKSRC}/src/*.dat ${DATADIR}
	${CP} ${WRKSRC}/src/lang/*.php ${DATADIR}/lang
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/src/Examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
