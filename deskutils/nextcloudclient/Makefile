# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	nextcloudclient
PORTVERSION=	3.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	mr@FreeBSD.org
COMMENT=	NextCloud Desktop Syncing Client

LICENSE=	GPLv2

LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libqt5keychain.so:security/qtkeychain

USES=		cmake:noninja compiler:c++11-lib gmake gnome iconv \
		localbase:ldflags pkgconfig qt:5 sqlite ssl
USE_QT=		buildtools_build concurrent core dbus declarative graphicaleffects \
		gui linguist_build location network printsupport qmake_build \
		quickcontrols2 sql svg webchannel webengine websockets \
		widgets xml
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=OFF \
		-DBUILD_UPDATER:BOOL=OFF \
		-DCMAKE_INSTALL_MANDIR:STRING=man \
		-DWITH_STACK_PROTECTOR:BOOL=OFF \
		-DNO_SHIBBOLETH=1
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

DEBUG=		yes
USE_GITHUB=	yes
GH_ACCOUNT=	nextcloud
GH_PROJECT=	desktop

#OPTIONS_DEFINE=		DEBUG DOCS
OPTIONS_DEFINE=		DEBUG # DOCS doesn't build currently

#DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
#			doxygen:devel/doxygen
#DOCS_USE=		tex=dvipsk:build,latex:build
#DOCS_CMAKE_ON=		-DWITH_DOC:BOOL=ON

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.ifdef WITH_DEBUG
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Debug
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085 && !${SSL_DEFAULT:Mopenssl}
BROKEN=	nextcloudclient requires OpenSSL 1.1.0, add DEFAULT_VERSIONS+=ssl=openssl to /etc/make.conf
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|.lst |.lst.sample |' ${WRKSRC}/CMakeLists.txt

pre-configure:
	@(cd ${WRKSRC} && ${CP} -f sync-exclude.lst sync-exclude.lst.sample)

.include <bsd.port.post.mk>
