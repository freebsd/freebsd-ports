# New ports collection makefile for:	sox - Sound Exchange
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sox
PORTVERSION=	13.0.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	dnelson@allantgroup.com
COMMENT=	SOund eXchange - universal sound sample translator

CONFLICTS=	play-[0-9]*

MAN1=		sox.1
MAN3=		libst.3
MAN7=		soxexam.7
MLINKS=		sox.1 play.1 sox.1 rec.1
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
# src/Makefile uses ${RM} but never sets it
MAKE_ENV+=	RM="rm -f"

OPTIONS=	FLAC "Enable libflac" on \
		GSM "Use libgsm from ports (else use bundled lib)" on \
		LAME "Enable mp3 encoding with LAME" on \
		MAD "Enable mp3 decoding with MAD" on \
		SNDFILE "Enable libsndfile" on \
		VORBIS "Enable Ogg Vorbis support" on

.include <bsd.port.pre.mk>

.if defined(WITH_FLAC) || defined(WITH_GSM) || defined(WITH_LAME) || \
    defined(WITH_MAD) || defined(WITH_SNDFILE) || defined(WITH_VORBIS)
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.endif

.if defined(WITH_VORBIS)
CONFIGURE_ARGS+=	--with-ogg-vorbis
LIB_DEPENDS+=		vorbis.4:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--without-ogg-vorbis
# Above configure flag does not exist, so workaround with the below line
CONFIGURE_ENV+=		ac_cv_header_vorbis_codec_h=no
.endif

.if defined(WITH_SNDFILE)
CONFIGURE_ARGS+=	--with-sndfile
LIB_DEPENDS+=		sndfile.1:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ARGS+=	--without-sndfile
.endif

.if defined(WITH_LAME)
CONFIGURE_ARGS+=	--with-lame
LIB_DEPENDS+=		mp3lame.0:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=	--without-lame
.endif

.if defined(WITH_FLAC)
CONFIGURE_ARGS+=	--with-flac
LIB_DEPENDS+=		FLAC.7:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=	--without-flac
.endif

.if defined(WITH_MAD)
CONFIGURE_ARGS+=	--with-mad
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=	--without-mad
.endif

.if defined(WITH_GSM)
CONFIGURE_ARGS+=	--with-external-gsm
LIB_DEPENDS+=		gsm.1:${PORTSDIR}/audio/gsm
.else
CONFIGURE_ARGS+=	--without-external-gsm
# Above configure flag does not exist, so workaround with the below line
CONFIGURE_ENV+=		ac_cv_header_gsm_h=no
.endif

# Tell configure that libgsm's headers are in $LOCALDIR/include
post-patch:
	@${REINPLACE_CMD} -Ee 's![[:<:]]gsm/gsm.h!gsm.h!' ${WRKSRC}/configure \
		${WRKSRC}/src/gsm.c ${WRKSRC}/src/wav.c

.include <bsd.port.post.mk>
