# New ports collection makefile for:	guikachu
# Date created:		11 Nov 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/audio/goobox/Makefile,v 1.15 2006/04/13 07:52:30 bland Exp $
#

PORTNAME=	goobox
PORTVERSION=	0.9.93
PORTREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD player and ripper for GNOME Desktop environment

RUN_DEPENDS=	cddb-slave2-properties:${PORTSDIR}/audio/gnomemedia2

USE_X_PREFIX=	yes
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libglade2 libbonobo \
		gnomedocutils
USE_GSTREAMER80=	cdparanoia gconf
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	goobox.schemas

OPTIONS=	NOTIFY "Enable libnotify support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	does not build on 4.X
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=		notify.1:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=	--enable-notification
.else
CONFIGURE_ARGS+=	--disable-notification
.endif

.include <bsd.port.post.mk>
