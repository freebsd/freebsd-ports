# New ports collection makefile for:	tiemu3
# Date created:				13 Aug 2007
# Whom:					Naram Qashat <cyberbotx@cyberbotx.com>
#
# $FreeBSD$
#

PORTNAME=	tiemu3
PORTVERSION=	3.02
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	SF/gtktiemu/tiemu-linux/TiEmu%20${PORTVERSION}
DISTNAME=	tiemu-${PORTVERSION}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	TI89(ti)/92(+)/V200 hand-helds emulator

LIB_DEPENDS=	ticalcs2.7:${PORTSDIR}/comms/libticalcs2 \
		ticables2.1:${PORTSDIR}/comms/libticables2 \
		tifiles2.5:${PORTSDIR}/devel/libtifiles2

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -export-dynamic"
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-gdb --mandir=${MANPREFIX}/man
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
USE_SDL=	sdl

MAN1=		tiemu.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

.if !defined(WITH_KDE)
CONFIGURE_ARGS+=	--without-kde
.else
USE_KDELIBS_VER=	3
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -E 's,(install-data-am:).*$$,\1,' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's,defined(__LINUX__),& || defined(__BSD__),' \
		${WRKSRC}/src/gui/calc/pckeys.h ${WRKSRC}/src/misc/paths.h
	${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|#define GTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/gui/device.c

pre-install:
	${CHMOD} +x ${WRKSRC}/install-sh

.include <bsd.port.mk>
