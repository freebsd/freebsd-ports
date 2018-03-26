# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	nextcloudclient
PORTVERSION=	0.0.0.20180323
#DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	mr@freebsd.org
COMMENT=	NextCloud Desktop Syncing Client

LICENSE=	GPLv2

LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libqt5keychain.so:security/qtkeychain@qt5

USES=		cmake:outsource,noninja compiler:c++11-lib gmake iconv \
		localbase:ldflags pkgconfig sqlite ssl
USE_QT5=	buildtools_build concurrent core dbus gui linguist_build network \
		qmake_build sql webkit widgets xml
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=OFF \
		-DCMAKE_INSTALL_MANDIR:STRING=man \
		-DWITH_STACK_PROTECTOR:BOOL=OFF
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	nextcloud
GH_PROJECT=	client
GH_TAGNAME=	4c40789dcafe5b193e125620b63dcc95e08ffba5

#OPTIONS_DEFINE=		DEBUG DOCS
OPTIONS_DEFINE=		DEBUG # DOCS doesn't build currently

#DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
#			doxygen:devel/doxygen
#DOCS_USE=		tex=dvipsk:build,latex:build
#DOCS_CMAKE_ON=		-DWITH_DOC:BOOL=ON

DEBUG_CMAKE_ON=		-DCMAKE_BUILD_TYPE:STRING=Debug

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|.lst |.lst.sample |' ${WRKSRC}/CMakeLists.txt
.if ${OSVERSION} < 1100101
	@${REINPLACE_CMD} -e 's/ -fstack-protector-strong//' \
		${WRKSRC}/src/CMakeLists.txt
.endif

pre-configure:
	@(cd ${WRKSRC} && ${CP} -f sync-exclude.lst sync-exclude.lst.sample)

.include <bsd.port.post.mk>
