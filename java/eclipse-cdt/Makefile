# New ports collection makefile for:	eclipse-cdt
# Date created:				March 1, 2004
# Whom:					gldisater@gldis.ca
#
# $FreeBSD$
#

PORTNAME=	cdt
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/cdt/releases/new/zips/${PORTVERSION}/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	org.eclipse.cdt-${PORTVERSION}-linux.${ECLIPSE_ARCH}
DIST_SUBDIR=	eclipse

MAINTAINER=	java@freebsd.org
COMMENT=	C/C++ IDE for Eclipse

RUN_DEPENDS=	${LOCALBASE}/eclipse:${PORTSDIR}/java/eclipse

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
PLIST_SUB=	RELEASEVERSION=${PORTVERSION}

ECLIPSE_ARCH=	x86

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins  ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse

.include <bsd.port.mk>
