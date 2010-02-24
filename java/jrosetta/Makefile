# New ports collection makefile for:	jrosetta
# Date created:				11 February 2010
# Whom:					rfarmer@predatorlabs.net
#
# $FreeBSD$
#

PORTNAME=	jrosetta
PORTVERSION=	1.0.2
CATEGORIES=	java devel
MASTER_SITES=	http://www.predatorlabs.net/dl/
EXTRACT_SUFX=	-gpl.zip

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	API for building a graphical console in Swing

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_BUILD=	yes
JAVA_RUN=	yes
USE_ANT=	yes

ALL_TARGET=	make
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-gpl

PLIST_FILES=	%%JAVAJARDIR%%/jrosetta-API.jar \
		%%JAVAJARDIR%%/jrosetta-engine.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/jrosetta-API.jar ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/jrosetta-engine.jar ${JAVAJARDIR}

.include <bsd.port.mk>
