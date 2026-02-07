PORTNAME=	gammaray
DISTVERSION=	3.3.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/KDAB/GammaRay/releases/download/v${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Debugging tool for Qt-application
WWW=		https://www.kdab.com/development-resources/qt-tools/gammaray/

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2+ LGPL20+ LGPL21 LGPL3 MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSES/BSD-2-Clause.txt
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSES/BSD-3-Clause.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt
LICENSE_FILE_LGPL20+ =	${WRKSRC}/LICENSES/LGPL-2.0-or-later.txt
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSES/LGPL-2.1-only.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/LICENSES/LGPL-3.0-only.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT.txt

RUN_DEPENDS=	lsof:sysutils/lsof

USES=		cmake kde:6 pkgconfig qt:6

USE_KDE=	coreaddons syntaxhighlighting
USE_QT=		3d base declarative location positioning svg \
		webchannel tools:build
QT_VERSION=${QT6_VERSION:C/\./_/:C/\..*//}

CMAKE_ON=	STACK_DETAILS_DWARF
CMAKE_OFF=	STACK_DETAILS_AUTO_DETECT

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	WEBENGINE=""
USE_QT+=	webengine
.else
PLIST_SUB+=	WEBENGINE="@comment "
.endif

PLIST_SUB+=	ARCH=${ARCH:S/amd64/x86_64/:S/i386/i686/:C/armv./arm/} \
		PORTMAJMIN=${PORTVERSION:C/(.*)\..*/\1/} \
		PORTVERSION=${PORTVERSION} QTVER=${QT_VERSION}

WRKSRC=		${WRKDIR}/GammaRay-${DISTVERSION}

.include <bsd.port.post.mk>
