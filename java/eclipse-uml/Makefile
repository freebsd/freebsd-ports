# New ports collection makefile for:	eclipse-uml
# Date created:				October 20, 2004
# Whom:					gldisater@gldis.ca
#
# $FreeBSD$
#

PORTNAME=	uml
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/uml2/downloads/drops/1.0.1/R200409171820/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	uml2-SDK-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.org
COMMENT=	A framework creating UML diagrams in Eclipse

RUN_DEPENDS+=	${LOCALBASE}/eclipse/features/org.eclipse.emf_2.0.1/feature.xml:${PORTSDIR}/java/eclipse-emf

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
PLIST_SUB=	RELEASEVERSION=${PORTVERSION}

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse

.include <bsd.port.mk>
