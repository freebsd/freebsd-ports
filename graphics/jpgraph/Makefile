# ex:ts=8
# Ports collection makefile for:	jpgraph
# Date created:			Oct 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jpgraph
PORTVERSION=	1.14
CATEGORIES=	graphics
MASTER_SITES=	http://www.aditus.nu/jpgraph/downloads/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Draw both "quick and dirty" graphs with a minimum of code

NO_BUILD=	yes
USE_PHP=	yes
WANT_PHP_WEB=	yes

pre-everything::
	@${ECHO} ""
	@${ECHO} "You have to configure PHP with GD support."
	@${ECHO} ""
	@${ECHO} "If you have already compiled PHP without GD,"
	@${ECHO} "press CTRL+C now and rebuild it before installing jpgraph."
	@${ECHO} ""

do-install:
	@${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/src/*.php ${DATADIR}
	${CP} ${WRKSRC}/src/*.inc ${DATADIR}
	${CP} ${WRKSRC}/src/*.dat ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/src/Examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
