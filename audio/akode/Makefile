# New ports collection makefile for:	mpeglib_artsplug
# Date created:				July 09 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	akode
PORTVERSION=	2.0.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=distfiles
DISTNAME=	30375-${PORTNAME}-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Default KDE audio backend

CONFLICTS=	kdemultimedia-3.[1-3]*

OPTIONS=	FFMPEG "FFMPEG decoder plugin" off \
		JACK "Jack output plugin" off \
		MPC "Monkey's Audio decoder plugin" on \
		MPEG "MPEG Audio (including mp3) plugin" on \
		OSS "OSS output plugin" on \
		RESAMPLER "Resampler processing plugin" on \
		XIPH "FLAC/Speex/Vorbis decoder plugin" on

USE_AUTOTOOLS=	libltdl libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--program-transform-name= \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-extra-includes=${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if defined(WITH_FFMPEG)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_ffmpeg_decoder.so:${PORTSDIR}/audio/akode-plugins-ffmpeg
.endif

.if defined(WITH_JACK)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_jack_sink.so:${PORTSDIR}/audio/akode-plugins-jack
.endif

.if !defined(WITHOUT_MPC)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_mpc_decoder.so:${PORTSDIR}/audio/akode-plugins-mpc
.endif

.if !defined(WITHOUT_MPEG)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_mpeg_decoder.so:${PORTSDIR}/audio/akode-plugins-mpeg
.endif

.if !defined(WITHOUT_OSS)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_oss_sink.so:${PORTSDIR}/audio/akode-plugins-oss
.endif

.if !defined(WITHOUT_RESAMPLER)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_src_resampler.so:${PORTSDIR}/audio/akode-plugins-resampler
.endif

.if !defined(WITHOUT_XIPH)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_xiph_decoder.so:${PORTSDIR}/audio/akode-plugins-xiph
.endif

post-patch:
	@${SETENV} TZ=UTC \
	${TOUCH} -t 200607222217.01 ${WRKSRC}/akode/lib/akode_export.h.in
	${REINPLACE_CMD} -e 's|akodeplay_LDFLAGS =.*|akodeplay_LDFLAGS = \
	$$(all_libraries) ${PTHREAD_LIBS}|g' \
		${WRKSRC}/akode/akodeplay/Makefile.in

.include <bsd.port.post.mk>
