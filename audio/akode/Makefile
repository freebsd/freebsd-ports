# New ports collection makefile for:	mpeglib_artsplug
# Date created:				July 09 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	akode
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMEPREFIX=	kdemultimedia-
DISTNAME=	kdemultimedia-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Default KDE audio backend

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg \
		vorbis.3:${PORTSDIR}/audio/libvorbis

CONFLICTS=	kdemultimedia-3.[1-3]*

OPTIONS=	JACK "Jack output plugin" off \
		MPC "Monkey's Audio decoder plugin" on \
		MPEG "MPEG Audio (including mp3) plugin" on \
		OSS "OSS output plugin" on \
		POLYPAUDIO "Polypaudio output plugin" off \
		RESAMPLER "Resampler processing plugin" on \
		XIPH "FLAC/Speex/Vorbis decoder plugin" on

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdemultimedia-${PORTVERSION}
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_JACK)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_jack_sink.so:${PORTSDIR}/audio/akode-plugins-jack
.endif

.if !defined(WITHOUT_MPC)
RUN_DEPENDS+=   ${LOCALBASE}/lib/libakode_mpc_decoder.so:${PORTSDIR}/audio/akode-plugins-mpc
.endif

.if !defined(WITHOUT_MPEG)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_mpeg_decoder.so:${PORTSDIR}/audio/akode-plugins-mpeg
.endif

.if !defined(WITHOUT_OSS)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_oss_sink.so:${PORTSDIR}/audio/akode-plugins-oss
.endif

.if defined(WITH_POLYPAUDIO)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_polyp_sink.so:${PORTSDIR}/audio/akode-plugins-polypaudio
.endif

.if !defined(WITHOUT_RESAMPLER)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_src_resampler.so:${PORTSDIR}/audio/akode-plugins-resampler
.endif

.if !defined(WITHOUT_XIPH)
RUN_DEPENDS+=	${LOCALBASE}/lib/libakode_xiph_decoder.so:${PORTSDIR}/audio/akode-plugins-xiph
.endif

pre-configure:
	${ECHO_CMD} "akode" > ${WRKSRC}/inst-apps

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
