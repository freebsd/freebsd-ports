PKGNAMESUFFIX=	-qt5

MASTERDIR=	${.CURDIR}/../../chinese/gcin
PLIST=		${.CURDIR}/pkg-plist
COMMENT=	Qt5 support for gcin
USE_QT=		qdbus qmake:build buildtools:build core gui
USE_CXXSTD=	c++11
LIB_DEPENDS=	libgcin-im-client.so:chinese/gcin
ALL_TARGET=	qt5-im
BUILD_GCIN_LIST=qt5

do-install:
	@${MKDIR} ${STAGEDIR}${QT_PLUGINDIR}/platforminputcontexts
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/qt5-im/libgcinplatforminputcontextplugin.so ${STAGEDIR}${QT_PLUGINDIR}/platforminputcontexts

.include "${MASTERDIR}/Makefile"
