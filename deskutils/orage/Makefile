# New ports collection makefile for:	xfce4-calendar
# Date created:		2003-01-14
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	orage
PORTVERSION=	4.8.2
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	A calendar application to manage your time with Xfce 4

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20 intltool intlhack pkgconfig desktopfileutils
USE_XFCE=	configenv libgui panel
USE_XORG=	xext xrender xinerama xi xrandr xcursor xcomposite xdamage x11 \
		xfixes
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	BDB	"Enable BDB support"		off \
		ICAL	"Enable libical support"	off \
		DBUS	"Enable D-BUS support"		on \
		NOTIFY	"Enable notification support"	on

MAN1=		globaltime.1 orage.1 tz_convert.1

.include <bsd.port.pre.mk>

.if defined(WITH_BDB)
CONFIGURE_ARGS+=--with-bdb4=yes --with-bdb4_dir=${PREFIX}
USE_BDB=	yes
.else
CONFIGURE_ARGS+=--with-bdb4=no
.endif

.if defined(WITH_ICAL)
LIB_DEPENDS+=	ical.44:${PORTSDIR}/devel/libical
CFLAGS+=	-I${LOCALBASE}/include/libical
PLIST_SUB+=	WITH_ICAL="@comment "
.else
CONFIGURE_ARGS+=--disable-libical
PLIST_SUB+=	WITH_ICAL=""
.endif

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS="@comment "
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

post-patch:
.if !defined(WITH_ICAL)
	@${REINPLACE_CMD} -e 's|libical-|no-&|g' ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(datadir)/orage/doc/C|(datadir)/doc/orage/C|' \
		${WRKSRC}/doc/C/Makefile.in \
		${WRKSRC}/doc/C/images/Makefile.in

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
