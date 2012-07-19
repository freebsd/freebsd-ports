# New ports collection makefile for:	alephone
# Date created:		27 February 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	alephone
PORTVERSION=	20120128
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/marathon/Aleph%20One/2012-01-28
DISTNAME=	AlephOne-${PORTVERSION}

MAINTAINER=	fiziologus@gmail.com
COMMENT=	The open source version of Bungie's Marathon game

BUILD_DEPENDS+=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs

USE_GMAKE=	yes

USE_BZIP2=	yes
USE_SDL+=	image net sdl sound
USE_GL=		yes
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-alsa --disable-sndfile
CONFIGURE_ENV=	PKG_CONFIG="${PKG_CONFIG}"

DATADIR=	${PREFIX}/share/AlephOne

MAN6=		alephone.6

OPTIONS=	MAD "use libmad for mp3 playback" on \
		OGG "enable ogg/vorbis music playback" on \
		SPEEX "enable speex net mic playback" on \
		SMPEG "use SMPEG for movie playback" on \
		TTF "enable SDL_ttf font rendering" on \
		ZZIP "enable zziplib support" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_MAD)
CONFIGURE_ARGS+=--disable-mad
.else
LIB_DEPEND+=	mad.2:${PORTSDIR}/audio/libmad
.endif

.if defined(WITHOUT_OGG)
CONFIGURE_ARGS+=--disable-vorbis
.else
LIB_DEPEND+=	vorbisfile.6:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITHOUT_SPEEX)
CONFIGURE_ARGS+=--disable-speex
.else
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
.endif

.if defined(WITHOUT_SMPEG)
CONFIGURE_ARGS+=--disable-smpeg
.else
LIB_DEPENDS+=	smpeg.1:${PORTSDIR}/multimedia/smpeg
.endif

.if defined(WITHOUT_TTF)
CONFIGURE_ARGS+=--disable-ttf
.else
USE_SDL+=	ttf
.endif

.if defined(WITHOUT_ZZIP)
CONFIGURE_ARGS+=--disable-zzip
.else
LIB_DEPENDS+=	zzip.13:${PORTSDIR}/devel/zziplib
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.html ${DOCSDIR}
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
