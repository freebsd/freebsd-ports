# New ports collection makefile for:	net-rhythmbox
# Date created:		14 February 2003
# Whom:			Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	net-rhythmbox
PORTVERSION=	0.4.8
PORTREVISION=	8
CATEGORIES=	audio gnome
MASTER_SITES=	http://download.raisdorf.net/files/

MAINTAINER=	hendrik@scholz.net
COMMENT=	Audio player for the Gnome 2 desktop environment

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		FLAC.5:${PORTSDIR}/audio/flac \
		mad.2:${PORTSDIR}/audio/mad \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui gstreamerplugins
USE_LIBTOOL_VER=	13
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"
CONFIGURE_ARGS=	--disable-lirc

BROKEN=	"Needs update for gstreamer-0.8"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libxosd.so)
WITH_XOSD=	yes
.endif
.if exists(${LOCALBASE}/lib/libvorbis.so)
WITH_VORBIS=	yes
.endif

.ifdef (WITH_XOSD)
LIB_DEPENDS+=		xosd.4:${PORTSDIR}/misc/xosd
.else
CONFIGURE_ARGS+=	--disable-xosd
.endif
.ifdef (WITH_VORBIS)
LIB_DEPENDS+=		vorbis.3:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--disable-vorbistest
.endif

pre-everything::
.if !defined(WITH_XOSD)
	@${ECHO_CMD}
	@${ECHO_CMD} "define WITH_XOSD to enable On-Screen-Display support"
	@${ECHO_CMD}
.endif
.if !defined(WITH_VORBIS)
	@${ECHO_CMD}
	@${ECHO_CMD} "define WITH_VORBIS to enable Vorbis support"
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
