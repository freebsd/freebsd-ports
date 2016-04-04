# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce4-mixer
PORTVERSION=	4.11.0
PORTREVISION=	3
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Volume control for the Xfce desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libunique-1.0.so:x11-toolkits/unique

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USES=		gmake libtool pkgconfig gettext-tools xfce tar:bzip2
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	panel
USE_GSTREAMER=	good

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	KEYBIND NLS
KEYBIND_DESC=	Multimedia keyboard shortcuts
KEYBIND_LIB_DEPENDS=	libkeybinder.so:x11/keybinder
KEYBIND_CONFIGURE_ENABLE=	keybinder
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' -or -name 'xfce-mixer-track.c' \
		-type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|(pkgdatadir)/icons|(datadir)/icons| ; \
		s|pixmaps/xfce4-mixer|pixmaps|'

.include <bsd.port.mk>
