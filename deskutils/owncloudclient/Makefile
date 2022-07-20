PORTNAME=	owncloudclient
DISTVERSION=	2.8.2
DISTVERSIONSUFFIX=	.4246
CATEGORIES=	deskutils
MASTER_SITES=	https://download.owncloud.com/desktop/ownCloud/stable/${DISTVERSION}${DISTVERSIONSUFFIX}/source/
DISTNAME=	ownCloud-${DISTVERSION}${DISTVERSIONSUFFIX}

PATCH_SITES=	https://github.com/owncloud/client/commit/
PATCHFILES=	ff43c9394b45dd78106069ba89ae92f25abba158.patch:-p1

MAINTAINER=	daniel@morante.net
COMMENT=	OwnCloud Desktop Syncing Client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libqt5keychain.so:security/qtkeychain

USES=		cmake:noninja compiler:c++11-lib desktop-file-utils gmake \
		iconv kde:5 localbase:ldflags pkgconfig qt:5 shared-mime-info \
		sqlite tar:xz
USE_KDE=	completion config coreaddons jobwidgets kio service \
		widgetsaddons windowsystem
USE_LDCONFIG=	yes
USE_QT=		concurrent core dbus gui network sql webkit widgets xml \
		buildtools_build linguist_build qmake_build

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR:STRING=man \
		-DSYSCONF_INSTALL_DIR="${PREFIX}/etc"
CMAKE_OFF=	BUILD_WITH_QT4 WITH_DOC WITH_STACK_PROTECTOR

PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=		DEBUG

DEBUG_CMAKE_ON=		-DCMAKE_BUILD_TYPE:STRING=Debug

post-patch:
	@${REINPLACE_CMD} -e \
		's|.lst |.lst.sample |' ${WRKSRC}/CMakeLists.txt

pre-configure:
	@cd ${WRKSRC} && ${CP} -f sync-exclude.lst sync-exclude.lst.sample

.include <bsd.port.mk>
