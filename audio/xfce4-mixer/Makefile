# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce4-mixer
PORTVERSION=	4.11.0
PORTREVISION=	5
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Volume control for the Xfce desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus \
		libunique-1.0.so:x11-toolkits/unique \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce:gtk2
USE_GNOME=	cairo glib20 gtk20 intlhack intltool libxml2
USE_XFCE=	panel
USE_GSTREAMER=	good

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		KEYBIND NLS
OPTIONS_SUB=		yes

KEYBIND_DESC=		Multimedia keyboard shortcuts
KEYBIND_LIB_DEPENDS=	libkeybinder.so:x11/keybinder
KEYBIND_CONFIGURE_ENABLE=	keybinder

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' -or -name 'xfce-mixer-track.c' \
		-type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|(pkgdatadir)/icons|(datadir)/icons| ; \
		s|pixmaps/xfce4-mixer|pixmaps|'

.include <bsd.port.mk>
