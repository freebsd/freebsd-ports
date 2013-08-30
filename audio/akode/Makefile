# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	akode
PORTVERSION=	2.0.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	laszlof
DISTNAME=	30375-${PORTNAME}-${PORTVERSION}

MAINTAINER=	swhetzel@gmail.com
COMMENT=	Default KDE audio backend

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	kdemultimedia-3.[1-3]*

OPTIONS_DEFINE=	FFMPEG JACK MPC MPEG OSS RESAMPLER XIPH
OPTIONS_DEFAULT=	MPC MPEG OSS RESAMPLER XIP

MPC_DESC=	Monkey's Audio decoder plugin
RESAMPLER_DESC=	Resampler processing plugin
XIPH_DESC=	FLAC/Speex/Vorbis decoder plugin

USES=		gmake
USE_AUTOTOOLS=	libltdl libtool
USE_BZIP2=	yes
USE_GCC=	any
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--program-transform-name= \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-extra-includes=${LOCALBASE}/include

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFFMPEG}
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_ffmpeg_decoder.so:${PORTSDIR}/audio/akode-plugins-ffmpeg
.endif

.if ${PORT_OPTIONS:MJACK}
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_jack_sink.so:${PORTSDIR}/audio/akode-plugins-jack
.endif

.if ${PORT_OPTIONS:MMPC}
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_mpc_decoder.so:${PORTSDIR}/audio/akode-plugins-mpc
.endif

.if ${PORT_OPTIONS:MMPEG}
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_mpeg_decoder.so:${PORTSDIR}/audio/akode-plugins-mpeg
.endif

.if ${PORT_OPTIONS:MOSS}
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_oss_sink.so:${PORTSDIR}/audio/akode-plugins-oss
.endif

.if ${PORT_OPTIONS:MRESAMPLER}
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_src_resampler.so:${PORTSDIR}/audio/akode-plugins-resampler
.endif

.if ${PORT_OPTIONS:MXIPH}
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_xiph_decoder.so:${PORTSDIR}/audio/akode-plugins-xiph
.endif

post-patch:
	@${SETENV} TZ=UTC \
	${TOUCH} -t 200607222217.01 ${WRKSRC}/akode/lib/akode_export.h.in
	${REINPLACE_CMD} -e 's|akodeplay_LDFLAGS =.*|akodeplay_LDFLAGS = \
	$$(all_libraries) ${PTHREAD_LIBS}|g' \
		${WRKSRC}/akode/akodeplay/Makefile.in

.include <bsd.port.mk>
