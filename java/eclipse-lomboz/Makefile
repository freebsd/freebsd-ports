# New ports collection makefile for:	eclipse-lomboz
# Date created:				June 18, 2004
# Whom:					sugimura@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	lomboz
PORTVERSION=	3.0.1
CATEGORIES=	java
MASTER_SITES=	http://download.forge.objectweb.org/lomboz/ \
		http://download.us.forge.objectweb.org/lomboz/ \
		http://download.forge.objectweb.org/lomboz/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	lomboz.301
DIST_SUBDIR=	eclipse

MAINTAINER=	sugimura@jp.FreeBSD.ORG
COMMENT=	A J2EE developer tool build as a plugin for the eclipse platform

RUN_DEPENDS+=	${LOCALBASE}/eclipse/features/org.eclipse.emf_2.0.0/feature.xml:${PORTSDIR}/java/eclipse-emf

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse

.include <bsd.port.mk>
