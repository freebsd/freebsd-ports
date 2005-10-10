# New ports collection makefile for:	eclipse-langpack
# Date created:				2003/09/03
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	3.1.1
PORTREVISION=	0
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	L-${PORTVERSION}_Language_Packs-200510051300
PKGNAMESUFFIX=	-langpack
DISTFILES=	NLpack1-eclipse-SDK-3.1.1a-gtk${EXTRACT_SUFX} \
		NLpack2-eclipse-SDK-3.1.1a-gtk${EXTRACT_SUFX} \
		NLpackBidi-eclipse-SDK-3.1.1a-gtk${EXTRACT_SUFX} \
		NLpack1_FeatureOverlay-eclipse-SDK-3.1.1${EXTRACT_SUFX} \
		NLpack2_FeatureOverlay-eclipse-SDK-3.1.1${EXTRACT_SUFX} \
		NLpackBidi_FeatureOverlay-eclipse-SDK-3.1.1${EXTRACT_SUFX}
DIST_SUBDIR=    eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	Eclipse Language Pack Feature

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
PLIST=		${WRKDIR}/pkg-plist

do-build:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@(cd ${WRKSRC}; ${FIND} eclipse -type f) | ${SORT} > ${PLIST}
	@${CAT} ${.CURDIR}/pkg-plist >> ${PLIST}

do-install:
	@${SETENV} ${SH} ${FILESDIR}/install.sh ${WRKSRC} \
			${PREFIX} ${SHAREOWN} ${SHAREGRP} 0755 0644

.include <bsd.port.mk>
