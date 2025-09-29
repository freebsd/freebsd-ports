PORTNAME=	nextcloudclient
PORTVERSION=	3.17.2
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	mr@FreeBSD.org
COMMENT=	NextCloud Desktop Syncing Client
WWW=		https://github.com/nextcloud/desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	inkscape:graphics/inkscape
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libqt6keychain.so:security/qtkeychain@qt6 \
		libxkbcommon.so:x11/libxkbcommon \
		libp11.so:security/libp11

USES=		cmake:noninja compiler:c++20-lang desktop-file-utils gl gmake \
		gnome iconv kde:6 localbase:ldflags pkgconfig qt:6 shared-mime-info \
		sqlite ssl
USE_CXXSTD=	c++20
USE_GL=		opengl
USE_KDE=	archive
USE_LDCONFIG=	yes
USE_QT=		5compat base declarative positioning svg websockets
CMAKE_ARGS=	-DBUILD_UPDATER:BOOL=OFF \
		-DWITH_STACK_PROTECTOR:BOOL=OFF

PLIST_SUB=	VERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	nextcloud
GH_PROJECT=	desktop

OPTIONS_DEFINE=			DEBUG GNOME GUIADDONS KDE WEBENGINE
OPTIONS_DEFAULT=		GNOME GUIADDONS
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE

OPTIONS_SUB=	yes

GUIADDONS_DESC=		Use KDE guiaddons (implies KDE)
KDE_DESC=		KDE desktop environment support
WEBENGINE_DESC=		Use Webengine to provide web login flow

GNOME_CMAKE_BOOL=	BUILD_SHELL_INTEGRATION_NAUTILUS

KDE_USES=		xorg
KDE_USE=		KDE=completion,config,coreaddons,ecm:build,jobwidgets,kio,service,solid,widgetsaddons,windowsystem \
			XORG=x11
KDE_CMAKE_BOOL=		BUILD_SHELL_INTEGRATION_DOLPHIN

GUIADDONS_IMPLIES=	KDE
GUIADDONS_USE=		KDE=guiaddons

WEBENGINE_USE=		QT=location,webchannel,webengine
WEBENGINE_CMAKE_BOOL=	BUILD_WITH_WEBENGINE

.include <bsd.port.pre.mk>

.ifdef WITH_DEBUG
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Debug
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|.lst |.lst.sample |' ${WRKSRC}/CMakeLists.txt

post-patch-GUIADDONS-off:
	@${REINPLACE_CMD} -e '/^find_package.*KF6GuiAddons/d' \
		${WRKSRC}/src/gui/CMakeLists.txt

pre-configure:
	@(cd ${WRKSRC} && ${CP} -f sync-exclude.lst sync-exclude.lst.sample)

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sync-exclude.lst ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
