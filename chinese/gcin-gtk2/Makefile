PKGNAMESUFFIX=	-gtk2

MASTERDIR=	${.CURDIR}/../../chinese/gcin
PLIST=		${.CURDIR}/pkg-plist
COMMENT=	Gtk2 support for gcin
LIB_DEPENDS=	libgcin-im-client.so:chinese/gcin
USE_GNOME=	gtk20
CMAKE_ARGS+=	-DGCIN_USE_GTK2_IM:BOOL=ON
ALL_TARGET=	gtk-im
BUILD_GCIN_LIST=gtk2

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/immodules
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gtk-im/im-gcin.so ${STAGEDIR}${PREFIX}/lib/gtk-2.0/immodules

.include "${MASTERDIR}/Makefile"
