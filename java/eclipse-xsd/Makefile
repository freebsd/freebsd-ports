# New ports collection makefile for:	eclipse-xsd
# Date created:				January 13, 2004
# Whom:					alex@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eclipse-xsd
PORTVERSION=	1.1.1.1
CATEGORIES=	java textproc
MASTER_SITES=	http://download.eclipse.org/tools/downloads/xsd/
DISTNAME=	xsd_1.1.1.1_20031120_1149WL
DIST_SUBDIR=	eclipse


MAINTAINER=	alex@FreeBSD.ORG
COMMENT=	Eclipse XML Schema Infoset Model

RUN_DEPENDS+=	${LOCALBASE}/eclipse/features/org.eclipse.emf_1.1.1/feature.xml:${PORTSDIR}/java/eclipse-emf
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.mk>
