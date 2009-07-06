# ex:ts=8
# New ports collection makefile for:	darkice
# Date created:			Dec 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	darkice
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	http://darkice.tyrell.hu/dist/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IceCast, IceCast2 and ShoutCast live audio streamer

OPTIONS=	VORBIS "Ogg Vorbis support" on \
		LAME "LAME support for MP3" off \
		TWOLAME "TwoLAME support for MP2" off \
		FAAC "FAAC support for AAC" off \
		JACK "Jack support" off

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--without-alsa

MAN1=		darkice.1
MAN5=		darkice.cfg.5
PLIST_FILES=	bin/darkice etc/darkice.cfg

.include <bsd.port.pre.mk>

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--without-vorbis
.else
CONFIGURE_ARGS+=	--with-vorbis-prefix=${LOCALBASE}
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_LAME)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--with-lame-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-lame
.endif

.if defined(WITH_TWOLAME)
LIB_DEPENDS+=	twolame.0:${PORTSDIR}/audio/twolame
CONFIGURE_ARGS+=	--with-twolame-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-twolame
.endif

.if defined(WITH_FAAC)
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
CONFIGURE_ARGS+=	--with-faac-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-faac
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=	--with-jack-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-jack
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g ; \
		s|PTHREAD_CFLAGS=.*$$|PTHREAD_CFLAGS=|g ; \
		s|PTHREAD_LIBS=.*$$|PTHREAD_LIBS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-O2 -pedantic||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
