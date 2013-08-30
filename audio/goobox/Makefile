# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/goobox/Makefile,v 1.25 2007/08/15 03:03:09 mezz Exp $

PORTNAME=	goobox
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD player and ripper for GNOME Desktop environment

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	discid:${PORTSDIR}/audio/libdiscid \
		musicbrainz3:${PORTSDIR}/audio/libmusicbrainz3 \
		brasero-media:${PORTSDIR}/sysutils/brasero \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme

USE_XORG=	x11
USES=		gettext gmake
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20 gconf2 desktopfileutils
USE_GSTREAMER=	cdparanoia gconf core gio
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	goobox.schemas

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-notification
.else
CONFIGURE_ARGS+=--disable-notification
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
