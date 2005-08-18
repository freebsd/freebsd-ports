# New ports collection makefile for:	eclipse-viPlugin
# Date created:				2005-08-01
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	viPlugin
PORTVERSION=	1.12.1
CATEGORIES=	java devel editors
MASTER_SITES=	http://www.satokar.com/viplugin/files/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork
PKGNAMEPREFIX=	eclipse-
DISTNAME=	${PORTNAME}_${PORTVERSION}_E30_trial
DIST_SUBDIR=	eclipse

MAINTAINER=	java@freebsd.org
COMMENT=	Vi like keybinding Eclipse plugin FREETRIAL Version

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
		@${CP} -r ${WRKSRC}/plugins  ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.mk>
