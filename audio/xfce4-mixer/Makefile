# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$
#

PORTNAME=	xfce4-mixer
PORTVERSION=	4.10.0
PORTREVISION=	2
CATEGORIES=	audio xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	A volume control for the Xfce desktop

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
	unique-1:${PORTSDIR}/x11-toolkits/unique

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 intltool intlhack desktopfileutils
USE_XFCE=	configenv libmenu libutil panel xfconf
USE_PKGCONFIG=	build
USE_GSTREAMER=	good

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	KEYBIND

KEYBIND_DESC=	Global keyboard shortcuts

MAN1=	xfce4-mixer.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKEYBIND}
LIB_DEPENDS+=	keybinder:${PORTSDIR}/x11/keybinder
CONFIGURE_ARGS+=--enable-keybinder
.else
CONFIGURE_ARGS+=--disable-keybinder
.endif

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' -or -name 'xfce-mixer-track.c' \
		-type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|(pkgdatadir)/icons|(datadir)/icons| ; \
		s|pixmaps/xfce4-mixer|pixmaps|'

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
