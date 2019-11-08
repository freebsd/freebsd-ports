# Created by: Naram Qashat <cyberbotx@cyberbotx.com>
# $FreeBSD$

PORTNAME=	tiemu3
PORTVERSION=	3.03
PORTREVISION=	9
CATEGORIES=	emulators
MASTER_SITES=	SF/gtktiemu/tiemu-linux/TIEmu%20${DISTVERSION}
DISTNAME=	tiemu-${DISTVERSION}
EXTRACT_SUFX=	-nogdb.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	TI89(ti)/92(+)/V200 hand-helds emulator

LIB_DEPENDS=	libticalcs2.so:comms/libticalcs2 \
		libticables2.so:comms/libticables2 \
		libtifiles2.so:devel/libtifiles2

USES=		gmake gnome groff libtool pkgconfig sdl
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 libglade2
USE_SDL=	sdl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -export-dynamic
CONFIGURE_ARGS=	--disable-gdb --without-kde

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
