# ex:ts=8
# Ports collection makefile for:	jpgraph
# Date created:			Oct 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jpgraph
PORTVERSION=	1.20.5
CATEGORIES=	graphics
MASTER_SITES=	http://members.chello.se/jpgraph/jpgdownloads/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Draw both "quick and dirty" graphs with a minimum of code

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//}
USE_PHP=	gd
DEFAULT_PHP_VER=4
IGNORE_WITH_PHP=5

NO_CDROM=	The free version cannot be used in a commercial context

PORTDOCS=	*

do-install:
	@${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/src/*.php ${DATADIR}
	${CP} ${WRKSRC}/src/*.inc ${DATADIR}
	${CP} ${WRKSRC}/src/*.dat ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/src/Examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
