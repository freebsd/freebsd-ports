# New ports collection makefile for:	lmms
# Date created:				04 Dec 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lmms
PORTVERSION=	20061204
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jylefort

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An all-in-one sequencer, drum machine, sampler and more

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	jack:${PORTSDIR}/audio/jack \
		vorbis:${PORTSDIR}/audio/libvorbis \
		FLAC:${PORTSDIR}/audio/flac \
		samplerate:${PORTSDIR}/audio/libsamplerate \
		sndfile:${PORTSDIR}/audio/libsndfile
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_BZIP2=	yes
USE_QT_VER=	3
USE_SDL=	sdl sound
USE_GMAKE=	yes

USE_AUTOTOOLS=	autoconf:262 autoheader:262 automake:19 aclocal:19 libtool:15
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-a
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--without-vst --without-stk

MAN1=		lmms.1

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|; s|@LOCALBASE@|${LOCALBASE}|' \
		${WRKSRC}/plugins/ladspa_base/ladspa_manager.cpp \
		${WRKSRC}/src/core/config_mgr.cpp
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/data/lmms \
		${WRKSRC}/data/lmms.desktop

pre-configure:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE}

post-install:
	# make it setuid-root to be able to set realtime priority
	# (root privileges are dropped in the main routine)
	${CHMOD} u+s ${PREFIX}/bin/lmms

.include <bsd.port.mk>
