# New ports collection makefile for:	eclipse-emf
# Date created:				January 13, 2004
# Whom:					alex@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eclipse-emf
PORTVERSION=	1.1.1
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/downloads/emf/
DISTNAME=	emf_1.1.1_20031120_1149WL
DIST_SUBDIR=	eclipse

MAINTAINER=	alex@FreeBSD.ORG
COMMENT=	Eclipse Modeling Framework

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.mk>
