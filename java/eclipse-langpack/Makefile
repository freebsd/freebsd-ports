# New ports collection makefile for:	eclipse-langpack
# Date created:				2003/09/03
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	2.1.2
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	http://download2.eclipse.org/downloads/drops/L-${PORTVERSION}_Translations-200312151300/:langpack
PKGNAMESUFFIX=	-langpack
DISTNAME=	eclipse${PORTVERSION}.1-SDK-linux-gtk-LanguagePackFeature
DISTFILES=	${DISTNAME}.zip:langpack
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	Eclipse Language Pack Feature

BUILD_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	LANGPACKVER=${PORTVERSION}

USE_ZIP=	yes
NO_BUILD=	yes

do-install:
	@${SETENV} PLIST_SUB=${PLIST_SUB} ${SH} ${FILESDIR}/install.sh ${WRKSRC} ${PREFIX} ${SHAREOWN} ${SHAREGRP} 0755 0644 ${PLIST}

.include <bsd.port.mk>
