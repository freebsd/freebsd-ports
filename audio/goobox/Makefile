# New ports collection makefile for:	guikachu
# Date created:		11 Nov 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/goobox/Makefile,v 1.25 2007/08/15 03:03:09 mezz Exp $
#

PORTNAME=	goobox
PORTVERSION=	1.9.2
PORTREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD player and ripper for GNOME Desktop environment

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz

USE_XORG=	x11
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libglade2 libbonobo \
		gnomedocutils nautiluscdburner
USE_GSTREAMER=	cdparanoia gconf core
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	goobox.schemas

OPTIONS=	NOTIFY "Enable libnotify support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=		notify.1:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=	--enable-notification
.else
CONFIGURE_ARGS+=	--disable-notification
.endif

.include <bsd.port.post.mk>
