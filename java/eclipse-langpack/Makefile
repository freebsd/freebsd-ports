# New ports collection makefile for:	eclipse-langpack
# Date created:				2003/09/03
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	L-${PORTVERSION}_Translations-200409161125
PKGNAMESUFFIX=	-langpack
DISTNAME=	NLpack-eclipse-SDK-3.0.x-linux-gtk
DIST_SUBDIR=    eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	Eclipse Language Pack Feature

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
NO_BUILD=	yes

do-install:
	@${SETENV} ${SH} ${FILESDIR}/install.sh ${WRKSRC} \
			${PREFIX} ${SHAREOWN} ${SHAREGRP} 0755 0644

.include <bsd.port.mk>
