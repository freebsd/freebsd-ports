# New ports collection makefile for:	eclipse-vep
# Date created:				January 13, 2004
# Whom:					alex@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vep
PORTVERSION=	1.0.0.20040628
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/ve/downloads/drops/S-S20040628-200406281448/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	VE-SDK-S20040628
DIST_SUBDIR=	eclipse

MAINTAINER=	alex@FreeBSD.ORG
COMMENT=	A framework for creating GUI builders for Eclipse

RUN_DEPENDS+=	${LOCALBASE}/eclipse/features/org.eclipse.emf_2.0.0/feature.xml:${PORTSDIR}/java/eclipse-emf

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse

.include <bsd.port.mk>
