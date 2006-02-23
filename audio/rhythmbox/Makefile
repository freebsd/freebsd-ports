# New ports collection makefile for:	rhythmbox
# Date created:		17 August 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/rhythmbox/Makefile,v 1.40 2005/10/28 08:03:53 jylefort Exp $
#

PORTNAME=	rhythmbox
PORTVERSION=	0.9.3.1
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.9
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Audio player for the Gnome 2 desktop environment

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		totem-plparser.1:${PORTSDIR}/multimedia/totem-gstreamer \
		dbus-1.2:${PORTSDIR}/devel/dbus

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui nautiluscdburner
USE_GSTREAMER=	flac mad gnomevfs gconf jpeg
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--enable-nautilus-menu
CONFIGURE_ENV=	LIBS="-lm" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

GCONF_SCHEMAS=	rhythmbox.schemas

OPTIONS=	IPOD "Enable iPod support" off \
		DAAP "Enable iTunes music sharing" off \
		FAAD "Enable FAAD decoder support" off \
		NOTIFY "Enable libnotify support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build on 4.X
.endif

.ifdef (WITH_IPOD)
CONFIGURE_ARGS+=	--enable-ipod
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so)
WITH_VORBIS=	yes
.endif

.ifdef (WITH_VORBIS)
USE_GSTREAMER+=		vorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis --disable-vorbistest
.endif

.if defined(WITH_FAAD)
USE_GSTREAMER+=		faad
.endif

.if defined(WITH_DAAP)
CONFIGURE_ARGS+=	--enable-daap  --with-mdns=howl
LIB_DEPENDS+=		soup-2.2.8:${PORTSDIR}/devel/libsoup \
			howl.0:${PORTSDIR}/net/howl
.else
.if exists(${LOCALBASE}/lib/libhowl.a)
LIB_DEPENDS+=		howl.0:${PORTSDIR}/net/howl
.endif
CONFIGURE_ARGS+=	--disable-daap
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=		notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

pre-everything::
.if !defined(WITH_VORBIS)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_VORBIS to enable Vorbis support"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
