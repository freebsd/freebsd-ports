# New ports collection makefile for:	rhythmbox
# Date created:		17 August 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rhythmbox
PORTVERSION=	0.8.5
PORTREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.8
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@freebsd.org
COMMENT=	Audio player for the Gnome 2 desktop environment

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		FLAC.5:${PORTSDIR}/audio/flac \
		mad.2:${PORTSDIR}/audio/libmad \
		id3tag.2:${PORTSDIR}/audio/libid3tag

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack lthack gnomeprefix libgnomeui
USE_INC_LIBTOOL_VER=13
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lm" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

OPTIONS=	XINE "Use xine backend instead of GStreamer" off \
		MONKEYMEDIA "Use MonkeyMedia metadata reader" off \
		IPOD "Enable iPod support" off

.include <bsd.port.pre.mk>

.ifdef (WITH_XINE)
LIB_DEPENDS+=		xine.9:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=	--with-player=xine
WITH_MONKEYMEDIA=	yes
.else
CONFIGURE_ARGS+=	--with-player=gstreamer
USE_GNOME+=		gstreamerplugins
.endif

.ifdef (WITH_MONKEYMEDIA)
CONFIGURE_ARGS+=	--with-metadata=monkeymedia
.else
CONFIGURE_ARGS+=	--with-metadata=gstreamer
USE_GNOME+=		gstreamerplugins
.endif

.ifdef (WITH_IPOD)
CONFIGURE_ARGS+=	--enable-ipod
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so)
WITH_VORBIS=	yes
.endif

.ifdef (WITH_VORBIS)
LIB_DEPENDS+=		vorbis.3:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis --disable-vorbistest
.endif

pre-everything::
.if !defined(WITH_XINE)
	@${ECHO_MSG}
	@${ECHO_MSG} "You must have gstreamer-plugins built with MAD support!"
	@${ECHO_MSG}
.endif
.if !defined(WITH_VORBIS)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_VORBIS to enable Vorbis support"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
