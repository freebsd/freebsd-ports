# New ports collection makefile for:	libcanberra
# Date created:				05 August 2008
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcanberra
PORTVERSION=	0.6
PORTREVISION=	4
CATEGORIES=	audio devel
MASTER_SITES=	http://0pointer.de/public/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec

LIB_DEPENDS=	vorbisfile.5:${PORTSDIR}/audio/libvorbis

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20 ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	PULSE "Enable Pulse Audio support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PULSE)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSE="" OSS="@comment "
CONFIGURE_ARGS+=--disable-oss
.else
CONFIGURE_ARGS+=--disable-pulse
PLIST_SUB+=	PULSE="@comment " OSS=""
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH}

.include <bsd.port.post.mk>
