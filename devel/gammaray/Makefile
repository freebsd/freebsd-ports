PORTNAME=	gammaray
DISTVERSION=	3.4.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/KDAB/GammaRay/releases/download/v${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Debugging tool for Qt-application
WWW=		https://www.kdab.com/development-resources/qt-tools/gammaray/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	upstream only supports aarch64, amd64, armv6, armv7, and i386

BUILD_DEPENDS=	vulkan-headers>=1.4:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	lsof:sysutils/lsof

USES=		cmake compiler:c++17-lang gl kde:6 pkgconfig qt:6
USE_GL=		opengl
USE_KDE=	coreaddons syntaxhighlighting
USE_QT=		3d base connectivity declarative location positioning \
		scxml svg tools webchannel

CMAKE_ON=	STACK_DETAILS_DWARF
CMAKE_OFF=	STACK_DETAILS_AUTO_DETECT

WRKSRC=		${WRKDIR}/GammaRay-${DISTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	WEBENGINE=""
USE_QT+=	webengine
.else
PLIST_SUB+=	WEBENGINE="@comment "
.endif

PLIST_SUB+=	ARCH=${ARCH:S|amd64|x86_64|:S|i386|i686|:C|armv.|arm|} \
		PORTMAJMIN=${PORTVERSION:C|(.*)\..*|\1|} \
		PORTVERSION=${PORTVERSION} \
		QTVER=${QT6_VERSION:C|\.|_|:C|\..*||}

.include <bsd.port.post.mk>
