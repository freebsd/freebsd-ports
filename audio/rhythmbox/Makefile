# New ports collection makefile for:	rhythmbox
# Date created:		17 August 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rhythmbox
PORTVERSION=	0.5.1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.5
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@freebsd.org
COMMENT=	Audio player for the Gnome 2 desktop environment

LIB_DEPENDS=	musicbrainz.2:${PORTSDIR}/audio/libmusicbrainz \
		gstplay-0.6.1:${PORTSDIR}/multimedia/gstreamer-plugins \
		FLAC.5:${PORTSDIR}/audio/flac \
		mad.1:${PORTSDIR}/audio/mad

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
USE_LIBTOOL=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libvorbis.so)
WITH_VORBIS=	yes
.endif

.ifdef (WITH_VORBIS)
LIB_DEPENDS+=		vorbis.2:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--disable-vorbistest
.endif

pre-everything::
.if !defined(WITH_VORBIS)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_VORBIS to enable Vorbis support"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
