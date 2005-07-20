# New ports collection makefile for:	rhythmbox
# Date created:		17 August 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rhythmbox
PORTVERSION=	0.8.8
PORTREVISION=	4
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.8
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Audio player for the Gnome 2 desktop environment

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		id3tag.2:${PORTSDIR}/audio/libid3tag

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui
WANT_GSTREAMER=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--enable-nautilus-menu
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lm" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

GCONF_SCHEMAS=	rhythmbox.schemas

OPTIONS=	XINE "Use xine backend instead of GStreamer" off \
		MONKEYMEDIA "Use MonkeyMedia metadata reader" off \
		IPOD "Enable iPod support" off

.include <bsd.port.pre.mk>

.ifdef (WITH_XINE)
LIB_DEPENDS+=		xine.13:${PORTSDIR}/multimedia/libxine \
			FLAC.7:${PORTSDIR}/audio/flac \
			mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=	--with-player=xine
WITH_MONKEYMEDIA=	yes
.else
CONFIGURE_ARGS+=	--with-player=gstreamer
USE_GSTREAMER+=		flac mad gnomevfs gconf
.endif

.ifdef (WITH_IPOD)
CONFIGURE_ARGS+=	--enable-ipod
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so)
WITH_VORBIS=	yes
.endif

.ifdef (WITH_VORBIS)
.ifndef (WITH_XINE)
USE_GSTREAMER+=		vorbis
.else
LIB_DEPENDS+=		vorbis.3:${PORTSDIR}/audio/libvorbis
.endif
.else
CONFIGURE_ARGS+=	--disable-vorbis --disable-vorbistest
.endif

.if !defined(WITH_XINE) && defined(WITH_FAAD)
USE_GSTREAMER+=		faad
.endif

pre-everything::
.if !defined(WITH_VORBIS)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_VORBIS to enable Vorbis support"
	@${ECHO_MSG}
.endif
.if !defined(WITH_XINE) && !defined(WITH_FAAD)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_FAAD to enable Faad support"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
