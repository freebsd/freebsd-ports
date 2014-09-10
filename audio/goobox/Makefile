# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/goobox/Makefile,v 1.25 2007/08/15 03:03:09 mezz Exp $

PORTNAME=	goobox
PORTVERSION=	2.2.0
PORTREVISION=	5
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD player and ripper for GNOME Desktop environment

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	libdiscid.so:${PORTSDIR}/audio/libdiscid \
		libmusicbrainz3.so:${PORTSDIR}/audio/libmusicbrainz3 \
		libbrasero-media.so:${PORTSDIR}/sysutils/brasero \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme

USE_XORG=	x11
USES=		gettext gmake desktop-file-utils pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack gtk20 gconf2
USE_GSTREAMER=	cdparanoia gconf core gio
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	goobox.schemas

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

NOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	notification

.include <bsd.port.mk>
