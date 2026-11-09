PKGNAMESUFFIX=	-gtk4

MASTERDIR=	${.CURDIR}/../../chinese/gcin
PLIST=		${.CURDIR}/pkg-plist
COMMENT=	Gtk4 support for gcin
LIB_DEPENDS=	libgcin-im-client.so:chinese/gcin
USE_GNOME=	gtk40
ALL_TARGET=	gtk4-im
BUILD_GCIN_LIST=gtk4

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/immodules
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gtk4-im/libim-gcin.so ${STAGEDIR}${PREFIX}/lib/gtk-4.0/immodules

.include "${MASTERDIR}/Makefile"
