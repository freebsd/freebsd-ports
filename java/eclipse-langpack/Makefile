# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	eclipse
PORTVERSION=	3.2.1
PORTREVISION=	5
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	L-${PORTVERSION}_Language_Packs-200609210945
PKGNAMESUFFIX=	-langpack
DISTFILES=	NLpack1-eclipse-SDK-${PORTVERSION}-gtk${EXTRACT_SUFX} \
		NLpack2-eclipse-SDK-${PORTVERSION}-gtk${EXTRACT_SUFX} \
		NLpack2a-eclipse-SDK-${PORTVERSION}-gtk${EXTRACT_SUFX} \
		NLpackBidi-eclipse-SDK-${PORTVERSION}-gtk${EXTRACT_SUFX}
DIST_SUBDIR=    eclipse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eclipse Language Pack Feature

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

USES=		zip
NO_WRKSUBDIR=	yes
PLIST=		${WRKDIR}/pkg-plist

do-build:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	(cd ${WRKSRC}; ${FIND} eclipse -type f) | ${SORT} | ${SED} -e 's,^eclipse,lib/eclipse,' > ${PLIST}
	@${CAT} ${.CURDIR}/pkg-plist >> ${PLIST}

do-install:
	${SETENV} ${SH} ${FILESDIR}/install.sh ${WRKSRC} ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
