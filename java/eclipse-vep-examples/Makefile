# New ports collection makefile for:	eclipse-vep-examples
# Date created:				July 15, 2004
# Whom:					sugimura@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vep
PORTVERSION=	1.0.1.1
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/ve/downloads/drops/R-1.0.1.1-200410221351/
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-examples
DISTNAME=	VE-examples-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	Visual Editor Project for the Eclipse IDE (examples)

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
PLIST_SUB=	RELEASEVERSION=1.0.1

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse

.include <bsd.port.mk>
