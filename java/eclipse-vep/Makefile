# New ports collection makefile for:	eclipse-vep
# Date created:				January 13, 2004
# Whom:					alex@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vep
PORTVERSION=	1.0.0.20040730
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/ve/downloads/drops/S-1.0M2-200407301410/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	VE-SDK-1.0M2
DIST_SUBDIR=	eclipse

MAINTAINER=	alex@FreeBSD.ORG
COMMENT=	A framework for creating GUI builders for Eclipse

RUN_DEPENDS+=	${LOCALBASE}/eclipse/features/org.eclipse.emf_2.0.1/feature.xml:${PORTSDIR}/java/eclipse-emf

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
PLIST_SUB=	RELEASEVERSION=1.0.0

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse

.include <bsd.port.mk>
