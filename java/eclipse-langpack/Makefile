# New ports collection makefile for:	eclipse-langpack
# Date created:				2003/09/03
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	3.2.1
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	L-${PORTVERSION}_Language_Packs-200609210945
PKGNAMESUFFIX=	-langpack
DISTFILES=	NLpack1-eclipse-SDK-${PORTVERSION}-gtk${EXTRACT_SUFX} \
		NLpack2-eclipse-SDK-${PORTVERSION}-gtk${EXTRACT_SUFX} \
		NLpack2a-eclipse-SDK-${PORTVERSION}-gtk${EXTRACT_SUFX} \
		NLpackBidi-eclipse-SDK-${PORTVERSION}-gtk${EXTRACT_SUFX}
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
	@(cd ${WRKSRC}; ${FIND} eclipse -type f) | ${SORT} | ${SED} -e 's,^eclipse,lib/eclipse,' > ${PLIST}
	@${CAT} ${.CURDIR}/pkg-plist >> ${PLIST}

do-install:
	@${SETENV} ${SH} ${FILESDIR}/install.sh ${WRKSRC} \
			${PREFIX} ${SHAREOWN} ${SHAREGRP} 0755 0644

.include <bsd.port.mk>
