# New ports collection makefile for:	eclipse-langpack
# Date created:				2003/09/03
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	2.1.1.1
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://download2.eclipse.org/downloads/drops/L-2.1.x%20Translations-200307021300/:langpack \
		http://people.debian.org/~tora/tmp/:jppack
PKGNAMESUFFIX=	-langpack
DISTNAME=	eclipse${PORTVERSION}-SDK-LanguagePackFeature-patch
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:langpack eclipse-2.1-NLS-menu${EXTRACT_SUFX}:jppack
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	Eclipse Language Pack Feature

BUILD_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
NO_BUILD=	yes

post-extract:
	@${MV} ${WRKSRC}/../plugins/org.eclipse.ui.workbench.nl1_2.1.0/ ${WRKSRC}/plugins/

do-install:
	@${SH} ${FILESDIR}/install.sh ${WRKSRC} ${PREFIX} ${SHAREOWN} ${SHAREGRP} 0755 0644 ${PLIST}

.include <bsd.port.mk>
