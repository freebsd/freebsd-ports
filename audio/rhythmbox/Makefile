# New ports collection makefile for:	rhythmbox
# Date created:		17 August 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/rhythmbox/Makefile,v 1.54 2006/04/25 17:52:32 marcus Exp $
#

PORTNAME=	rhythmbox
PORTVERSION=	0.9.4.1
PORTREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.9
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Audio player for the Gnome 2 desktop environment

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		totem-plparser.2:${PORTSDIR}/multimedia/totem-gstreamer \
		dbus-1.2:${PORTSDIR}/devel/dbus \
		sexy.1:${PORTSDIR}/x11-toolkits/libsexy \
		soup-2.2.8:${PORTSDIR}/devel/libsoup \
		gnome-media-profiles.0:${PORTSDIR}/audio/gnomemedia2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui nautiluscdburner
WANT_GNOME=	yes
USE_GSTREAMER=	flac mad gnomevfs gconf jpeg
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--enable-nautilus-menu --with-playback=gstreamer-0-10
CONFIGURE_ENV=	LIBS="-lm" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

GCONF_SCHEMAS=	rhythmbox.schemas

OPTIONS=	IPOD "Enable iPod support" off \
		DAAP "Enable iTunes music sharing" off \
		FAAD "Enable FAAD decoder support" off \
		NOTIFY "Enable libnotify support" on \
		VORBIS "Enable Ogg/Vorbis support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build on 4.X
.endif

.ifdef (WITH_IPOD)
CONFIGURE_ARGS+=	--enable-ipod
.endif

.if !defined(WITHOUT_VORBIS)
USE_GSTREAMER+=		vorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis --disable-vorbistest
.endif

.if defined(WITH_FAAD)
USE_GSTREAMER+=		faad
.endif

.if defined(WITH_DAAP)
CONFIGURE_ARGS+=	--enable-daap  --with-mdns=avahi
LIB_DEPENDS+=		 avahi-client:${PORTSDIR}/net/avahi
.else
.if exists(${LOCALBASE}/lib/libavahi-client.a)
LIB_DEPENDS+=		avahi-client:${PORTSDIR}/net/avahi
.endif
CONFIGURE_ARGS+=	--disable-daap
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=		notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.if ${HAVE_GNOME:Mpygtk2}!=""
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygtk2
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.post.mk>
