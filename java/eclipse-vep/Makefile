# New ports collection makefile for:	eclipse-vep
# Date created:				January 13, 2004
# Whom:					alex@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vep
PORTVERSION=	1.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/ve/downloads/drops/R-1.0-200409191449/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	VE-SDK-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	alex@FreeBSD.ORG
COMMENT=	A framework for creating GUI builders for Eclipse

RUN_DEPENDS+=	${LOCALBASE}/eclipse/features/org.eclipse.emf_2.0.1/feature.xml:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/eclipse/features/org.eclipse.gef_3.0.1/feature.xml:${PORTSDIR}/java/eclipse-gef

BROKEN=		Incomplete pkg-plist

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse

.include <bsd.port.mk>
