# New ports collection makefile for:	eclipse-gef-examples
# Date created:				July 8, 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eclipse-gef-examples
PORTVERSION=	2.1.1
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/gef/downloads/drops/R-2.1.1-200306180934/
DISTNAME=	GEF-examples-I20030618
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	Graphical Editing Framework for the Eclipse IDE (examples)

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.mk>
