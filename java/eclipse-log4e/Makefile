# New ports collection makefile for:	eclipse-log4e
# Date created:				August 30, 2004
# Whom:					sugimura@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	log4e
PORTVERSION=	0.7.6
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	http://log4e.jayefem.de/download/eclipse3/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	de.jayefem.${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	eclipse

MAINTAINER=	sugimura@jp.FreeBSD.ORG
COMMENT=	Eclipse plugin to use logger easily in Java projects

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.mk>
