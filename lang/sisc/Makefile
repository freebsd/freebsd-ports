# New ports collection makefile for:	SISC
# Date created:				18 March 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	sisc
PORTVERSION=	1.8.7
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extensible Java-based Scheme interpreter

USE_JAVA=	1.3+

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes
NO_BUILD=	yes
PORTDOCS=	COPYING README *.html

post-patch:
	${REINPLACE_CMD} -e 's|\(SISC_HOME=\).*$$|\1${DATADIR}|' \
		-e "s| java | ${LOCALBASE}/bin/javavm |" ${WRKSRC}/sisc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sisc ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${WRKSRC}/*.shp ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/scheme-src/*.scm ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING README doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
