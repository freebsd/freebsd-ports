# Created by: Naram Qashat <cyberbotx@cyberbotx.com>
# $FreeBSD$

PORTNAME=	tiemu3
PORTVERSION=	3.03
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	SF/gtktiemu/tiemu-linux/TIEmu%20${DISTVERSION}
DISTNAME=	tiemu-${DISTVERSION}
EXTRACT_SUFX=	-nogdb.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	TI89(ti)/92(+)/V200 hand-helds emulator

LIB_DEPENDS=	ticalcs2:${PORTSDIR}/comms/libticalcs2 \
		ticables2:${PORTSDIR}/comms/libticables2 \
		tifiles2:${PORTSDIR}/devel/libtifiles2

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
USE_SDL=	sdl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -export-dynamic
CONFIGURE_ARGS=	--disable-gdb

MAN1=		tiemu.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

CONFIGURE_ARGS+=	--without-kde

post-patch: .SILENT
	${REINPLACE_CMD} -E 's,(install-data-am:).*$$,\1,' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's,defined(__LINUX__),& || defined(__BSD__),' \
		${WRKSRC}/src/gui/calc/pckeys.h ${WRKSRC}/src/misc/paths.h
	${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
