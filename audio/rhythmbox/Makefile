# New ports collection makefile for:	net-rhythmbox
# Date created:		14 February 2003
# Whom:			Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	net-rhythmbox
PORTVERSION=	0.4.8
PORTREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	http://web.verbum.org/net-rhythmbox/

MAINTAINER=	hendrik@scholz.net
COMMENT=	Audio player for the Gnome 2 desktop environment

BROKEN=		Does not configure

LIB_DEPENDS=	musicbrainz.2:${PORTSDIR}/audio/libmusicbrainz \
		gstplay-0.6.1:${PORTSDIR}/multimedia/gstreamer-plugins \
		FLAC.5:${PORTSDIR}/audio/flac \
		mad.1:${PORTSDIR}/audio/mad

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
USE_LIBTOOL=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"
CONFIGURE_ARGS=	--disable-lirc

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libxosd.so)
WITH_XOSD=	yes
.endif
.if exists(${LOCALBASE}/lib/libogg.so)
WITH_OGG=  yes
.endif

.ifdef (WITH_XOSD)
LIB_DEPENDS+=   xosd.4:${PORTSDIR}/misc/xosd
.else
CONFIGURE_ARGS+=    --disable-xosd
.endif
.ifdef (WITH_OGG)
LIB_DEPENDS+=   ogg.4:${PORTSDIR}/audio/libogg
.else
CONFIGURE_ARGS+=    --disable-oggtest
.endif

pre-everything::
.if !defined(WITH_XOSD)
	@${ECHO_CMD}
	@${ECHO_CMD} "define WITH_XOSD to enable On-Screen-Display support"
	@${ECHO_CMD}
.endif
.if !defined(WITH_OGG)
	@${ECHO_CMD}
	@${ECHO_CMD} "define WITH_OGG to enable Ogg support"
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
