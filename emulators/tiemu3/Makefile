PORTNAME=	tiemu3
PORTVERSION=	3.03
PORTREVISION=	15
CATEGORIES=	emulators
MASTER_SITES=	SF/gtktiemu/tiemu-linux/TIEmu%20${DISTVERSION}
DISTNAME=	tiemu-${DISTVERSION}
EXTRACT_SUFX=	-nogdb.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	TI89(ti)/92(+)/V200 hand-helds emulator
WWW=		http://lpg.ticalc.org/prj_tiemu/

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libticables2.so:comms/libticables2 \
		libticalcs2.so:comms/libticalcs2 \
		libticonv.so:converters/libticonv \
		libtifiles2.so:devel/libtifiles2

USES=		gmake gnome groff libtool localbase pkgconfig sdl
USE_GNOME=	cairo gdkpixbuf gtk20 libglade2
USE_SDL=	sdl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-gdb --without-kde

LDFLAGS+=	-Wl,-E

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch: .SILENT
	${REINPLACE_CMD} -E 's,(install-data-am:).*$$,\1,' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's,defined(__LINUX__),& || defined(__BSD__),' \
		${WRKSRC}/src/gui/calc/pckeys.h ${WRKSRC}/src/misc/paths.h
	${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
