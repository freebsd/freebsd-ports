# New ports collection makefile for:	sox - Sound Exchange
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sox
PORTVERSION=	12.17.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sox

MAINTAINER=	dnelson@allantgroup.com
COMMENT=	SOund eXchange - universal sound sample translator

CONFLICTS=	play-[0-9]*

MAN1=			sox.1 play.1 soxexam.1
MLINKS=			play.1 rec.1 sox.1 soxmix.1
GNU_CONFIGURE=		yes
MAKE_ENV=		PLAY_SUPPORT=1

OPTIONS=	LAME "Enable mp3 encoding with LAME" off \
		MAD "Enable mp3 decoding with MAD" off \
		VORBIS "Enable Ogg Vorbis support" off

.include <bsd.port.pre.mk>

.if defined(WITH_VORBIS) || defined(WITH_LAME) || defined(WITH_MAD)
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
.endif

.if defined(WITH_VORBIS)
CONFIGURE_ARGS+=	--enable-ogg-vorbis
LIB_DEPENDS+=		vorbis.3:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--disable-ogg-vorbis
.endif

.if defined(WITH_LAME)
CONFIGURE_ARGS+=	--enable-lame
LIB_DEPENDS+=		mp3lame.0:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=	--disable-lame
.endif

.if defined(WITH_MAD)
CONFIGURE_ARGS+=	--enable-mad
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=	--disable-mad
.endif

.include <bsd.port.post.mk>
