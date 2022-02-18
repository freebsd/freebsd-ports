# Created by: Mathieu Arnold

PORTNAME=	nextcloudclient
PORTVERSION=	3.4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	mr@FreeBSD.org
COMMENT=	NextCloud Desktop Syncing Client

LICENSE=	GPLv2

BUILD_DEPENDS=	inkscape:graphics/inkscape
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libqt5keychain.so:security/qtkeychain

USES=		cmake:noninja compiler:c++14-lang desktop-file-utils gmake \
		gnome iconv localbase:ldflags pkgconfig qt:5 shared-mime-info \
		sqlite ssl
USE_QT=		buildtools_build concurrent core dbus declarative graphicaleffects \
		gui linguist_build location network printsupport qmake_build \
		quickcontrols2 sql svg testlib webchannel websockets \
		widgets xml
CMAKE_ARGS=	-DBUILD_UPDATER:BOOL=OFF \
		-DCMAKE_INSTALL_MANDIR:STRING=man \
		-DWITH_STACK_PROTECTOR:BOOL=OFF
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	nextcloud
GH_PROJECT=	desktop

#OPTIONS_DEFINE=		DEBUG DOCS
OPTIONS_DEFINE=		DEBUG WEBENGINE # DOCS doesn't build currently
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE
OPTIONS_DEFAULT_aarch64=	WEBENGINE

WEBENGINE_DESC=		QT5 Webengine support

#DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
#			doxygen:devel/doxygen
#DOCS_USE=		tex=dvipsk:build,latex:build
#DOCS_CMAKE_ON=		-DWITH_DOC:BOOL=ON

WEBENGINE_VARS=		USE_QT+=webengine

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.ifdef WITH_DEBUG
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Debug
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|.lst |.lst.sample |' ${WRKSRC}/CMakeLists.txt

post-patch-WEBENGINE-off:
	@${REINPLACE_CMD} -e '/^find_package.*COMPONENTS WebEngineWidgets WebEngine/d' \
		${WRKSRC}/src/CMakeLists.txt

pre-configure:
	@(cd ${WRKSRC} && ${CP} -f sync-exclude.lst sync-exclude.lst.sample)

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sync-exclude.lst ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
