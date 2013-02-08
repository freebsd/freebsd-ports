# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	orage
PORTVERSION=	4.8.4
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	A calendar application to manage your time with Xfce 4

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20 intltool intlhack desktopfileutils
USE_PKGCONFIG=	build
USE_XFCE=	configenv libmenu panel
USE_XORG=	xext xrender xinerama xi xrandr xcursor xcomposite xdamage x11 \
		xfixes
LDFLAGS+=	-L${LOCALBASE}/lib
OPTIONS_DEFINE=	BDB ICAL DBUS NOTIFY
OPTIONS_DEFAULT=	DBUS NOTIFY

ICAL_DESC=	libical support

MAN1=		globaltime.1 orage.1 tz_convert.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-configure
CONFIGURE_ARGS+=--with-bdb4=yes --with-bdb4_dir=${LOCALBASE}
USE_BDB=	yes
# Only Berkeley DB 4.x
INVALIDE_BDB_VER=	5
.else
CONFIGURE_ARGS+=--with-bdb4=no
.endif

.if ${PORT_OPTIONS:MICAL}
CONFIGURE_ARGS+=--enable-libical
LIB_DEPENDS+=	ical:${PORTSDIR}/devel/libical
CFLAGS+=	-I${LOCALBASE}/include/libical
PLIST_SUB+=	WITH_ICAL="@comment "
.else
CONFIGURE_ARGS+=--disable-libical
PLIST_SUB+=	WITH_ICAL=""
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

post-patch:
.if ${PORT_OPTIONS:MBDB}
	@${REINPLACE_CMD} -e 's|%%BDB_INCLUDE_DIR%%|${BDB_INCLUDE_DIR}|g ; \
		s|%%BDB_LIB_DIR%%|${BDB_LIB_DIR}|g ; \
		s|%%BDB_LIB_NAME%%|${BDB_LIB_NAME}|g' ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(datadir)/orage/doc/C|(datadir)/doc/orage/C|' \
		${WRKSRC}/doc/C/Makefile.in \
		${WRKSRC}/doc/C/images/Makefile.in

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
