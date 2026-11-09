PKGNAMESUFFIX=	-qt6

MASTERDIR=	${.CURDIR}/../../chinese/gcin
PLIST=		${.CURDIR}/pkg-plist
USE_QT=		base
USE_CXXSTD=	c++11
COMMENT=	Qt6 support for gcin
LIB_DEPENDS=	libgcin-im-client.so:chinese/gcin
ALL_TARGET=	qt6-im
BUILD_GCIN_LIST=qt6

do-install:
	@${MKDIR} ${STAGEDIR}${QT_PLUGINDIR}/platforminputcontexts
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/qt6-im/libgcinplatforminputcontextplugin.so ${STAGEDIR}${QT_PLUGINDIR}/platforminputcontexts

.include "${MASTERDIR}/Makefile"
