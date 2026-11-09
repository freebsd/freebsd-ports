PKGNAMESUFFIX=	-gtk3

MASTERDIR=	${.CURDIR}/../../chinese/gcin
PLIST=		${.CURDIR}/pkg-plist
COMMENT=	Gtk3 support for gcin
LIB_DEPENDS=	libgcin-im-client.so:chinese/gcin
USE_GNOME=	gtk30
ALL_TARGET=	gtk3-im
BUILD_GCIN_LIST=gtk3

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/immodules
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gtk3-im/im-gcin.so ${STAGEDIR}${PREFIX}/lib/gtk-3.0/immodules

.include "${MASTERDIR}/Makefile"
