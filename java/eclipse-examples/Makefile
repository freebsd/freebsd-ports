# New ports collection makefile for:	eclipse-examples
# Date created:				July 3, 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eclipse-examples
PORTVERSION=	2.1.1
CATEGORIES=	java devel
MASTER_SITES=	http://download2.eclipse.org/downloads/drops/%SUBDIR%/ \
		http://ftp-stud.fht-esslingen.de/pub/Mirrors/eclipse/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/softeng/eclipse/%SUBDIR%/ \
		ftp://ftp.tu-clausthal.de/pub/eclipse/downloads/drops/%SUBDIR%/
MASTER_SITE_SUBDIR=	R-2.1.1-200306271545
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	Examples for the Eclipse IDE

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse

.include <bsd.port.mk>
