PORTNAME=	nextcloudclient
PORTVERSION=	3.13.2
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	mr@FreeBSD.org
COMMENT=	NextCloud Desktop Syncing Client
WWW=		https://github.com/nextcloud/desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	inkscape:graphics/inkscape
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libqt5keychain.so:security/qtkeychain@qt5

USES=		cmake:noninja compiler:c++14-lang desktop-file-utils gmake \
		gnome iconv kde:5 localbase:ldflags pkgconfig qt:5 shared-mime-info \
		sqlite ssl
USE_KDE=	archive
USE_LDCONFIG=	yes
USE_QT=		buildtools:build concurrent core dbus declarative graphicaleffects \
		gui linguist:build network qmake:build quickcontrols \
		quickcontrols2 sql svg websockets widgets xml

CMAKE_ARGS=	-DBUILD_UPDATER:BOOL=OFF \
		-DWITH_STACK_PROTECTOR:BOOL=OFF

PLIST_SUB=	VERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	nextcloud
GH_PROJECT=	desktop

OPTIONS_DEFINE=			DOCS DEBUG GNOME KDE WEBENGINE
OPTIONS_DEFAULT=		GNOME
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE

OPTIONS_SUB=	yes

KDE_DESC=		KDE desktop environment support
WEBENGINE_DESC=		Use Webengine to provide web login flow

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
			doxygen:devel/doxygen
DOCS_USES=		tex
DOCS_USE=		TEX=dvipsk:build,latex:build
DOCS_CMAKE_BOOL=	WITH_DOC
DOCS_VARS=		PORTDOCS=*

GNOME_CMAKE_BOOL=	BUILD_SHELL_INTEGRATION_NAUTILUS

KDE_USES=		xorg
KDE_USE=		KDE=completion,config,coreaddons,ecm,jobwidgets,kio,service,solid,widgetsaddons,windowsystem \
			XORG=x11
KDE_CMAKE_BOOL=		BUILD_SHELL_INTEGRATION_DOLPHIN

WEBENGINE_USE=		QT=webchannel,webengine,printsupport,location
WEBENGINE_CMAKE_BOOL=	BUILD_WITH_WEBENGINE

.include <bsd.port.pre.mk>

.ifdef WITH_DEBUG
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Debug
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|.lst |.lst.sample |' ${WRKSRC}/CMakeLists.txt

pre-configure:
	@(cd ${WRKSRC} && ${CP} -f sync-exclude.lst sync-exclude.lst.sample)

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sync-exclude.lst ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
