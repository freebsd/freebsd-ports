# New ports collection makefile for:	eclipse-vep
# Date created:				January 13, 2004
# Whom:					alex@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eclipse-vep
PORTVERSION=	0.5.0
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/ve/downloads/drops/R-0.5.0-200312051712/
DISTNAME=	VE-SDK-$(PORTVERSION)
DIST_SUBDIR=	eclipse

MAINTAINER=	alex@FreeBSD.ORG
COMMENT=	First-class GUI building tools for Eclipse

RUN_DEPENDS+=	${LOCALBASE}/eclipse/features/org.eclipse.emf_1.1.1/feature.xml:${PORTSDIR}/java/eclipse-emf
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.mk>
