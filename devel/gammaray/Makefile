PORTNAME=	gammaray
DISTVERSION=	3.2.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/KDAB/GammaRay/releases/download/v${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Debugging tool for Qt-application
WWW=		https://www.kdab.com/development-resources/qt-tools/gammaray/

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2 GPLv2+ GPLv3 GPLv3+ LGPL20+ LGPL21 LGPL21+ LGPL3 MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSES/BSD-2-Clause.txt
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSES/BSD-3-Clause.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSES/GPL-2.0-only.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSES/GPL-3.0-only.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt
LICENSE_FILE_LGPL20+ =	${WRKSRC}/LICENSES/LGPL-2.0-or-later.txt
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSES/LGPL-2.1-only.txt
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/LICENSES/LGPL-3.0-only.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT.txt

LIB_DEPENDS=	libdwarf.so:devel/libdwarf \
		libelf.so:devel/libelf
RUN_DEPENDS=	lsof:sysutils/lsof

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

qt5_PKGNAMESUFFIX=		-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}
qt6_CONFLICTS_INSTALL=	${PORTNAME}-qt5

USES=		cmake pkgconfig

USE_KDE=	coreaddons syntaxhighlighting
USE_QT=		3d declarative location svg webchannel

.if ${FLAVOR} == qt5
USES+=		kde:5 qt:5
USE_QT+=	buildtools:build concurrent core designer gui help \
		linguisttools network printsupport qdoc:build \
		qmake:build script scripttools uiplugin widgets xml
QT_VERSION=${QT5_VERSION:C/\./_/:C/\..*//}
.else
USES+=		gl kde:6 qt:6
USE_GL=		gl
USE_QT+=	base positioning shadertools tools:build
QT_VERSION=${QT6_VERSION:C/\./_/:C/\..*//}
.endif

CMAKE_ARGS+=	QT_VERSION_MAJOR=${_QT_VER}
CMAKE_ON=	STACK_DETAILS_DWARF
CMAKE_OFF=	STACK_DETAILS_AUTO_DETECT

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB=	WEBENGINE=""
USE_QT+=	webengine
.else
PLIST_SUB=	WEBENGINE="@comment "
.endif

.if ${FLAVOR} == qt5
PLIST_SUB+=	QT5="" \
		QT6="@comment "
.else
PLIST_SUB+=	QT5="@comment " \
		QT6=""
.endif

PLIST_SUB+=	ARCH=${ARCH:S/amd64/x86_64/:S/i386/i686/:C/armv./arm/} \
		PORTMAJMIN=${PORTVERSION:C/(.*)\..*/\1/} \
		PORTVERSION=${PORTVERSION} \
		QTVER=${QT_VERSION}

WRKSRC=		${WRKDIR}/GammaRay-${DISTVERSION}

.include <bsd.port.mk>
