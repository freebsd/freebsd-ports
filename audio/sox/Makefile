# New ports collection makefile for:	sox - Sound Exchange
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sox
PORTVERSION=	12.18.2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	dnelson@allantgroup.com
COMMENT=	SOund eXchange - universal sound sample translator

CONFLICTS=	play-[0-9]*

MAN1=		sox.1 play.1 soxexam.1
MLINKS=		play.1 rec.1 sox.1 soxmix.1
GNU_CONFIGURE=	yes
MAKE_ENV=	PLAY_SUPPORT=1

OPTIONS=	LAME "Enable mp3 encoding with LAME" off \
		MAD "Enable mp3 decoding with MAD" off \
		VORBIS "Enable Ogg Vorbis support" off \
		GSM "Enable GSM audio codec support" off

PLIST_FILES=	bin/sox bin/soxmix bin/rec bin/play
CONFIGURE_ARGS=	--disable-alsa-dsp --disable-sun-audio

.include <bsd.port.pre.mk>

.if defined(WITH_VORBIS) || defined(WITH_LAME) || defined(WITH_MAD) || defined(WITH_GSM)
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
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

.if defined(WITH_GSM)
CONFIGURE_ARGS+=	--enable-external-gsm
LIB_DEPENDS+=		gsm.1:${PORTSDIR}/audio/gsm
.else
CONFIGURE_ARGS+=	--disable-external-gsm --disable-gsm
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's![[:<:]]gsm/!!' ${WRKSRC}/configure ${WRKSRC}/src/Makefile.gcc \
		${WRKSRC}/src/gsm.c ${WRKSRC}/src/wav.c

.include <bsd.port.post.mk>
