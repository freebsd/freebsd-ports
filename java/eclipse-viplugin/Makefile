# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	viPlugin
PORTVERSION=	1.14.0
PORTREVISION=	5
CATEGORIES=	java devel editors
MASTER_SITES=	http://www.satokar.com/viplugin/files/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	${PORTNAME}_${PORTVERSION}_E30
DIST_SUBDIR=	eclipse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vi like keybinding Eclipse plugin FREETRIAL Version

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
PLIST_SUB=	RELEASEVERSION=${PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/plugins  ${STAGEDIR}${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/features ${STAGEDIR}${PREFIX}/lib/eclipse

.include <bsd.port.mk>
