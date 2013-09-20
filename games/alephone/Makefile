# Created by: Michael Alyn Miller <malyn@strangeGizmo.com>
# $FreeBSD$

PORTNAME=	alephone
PORTVERSION=	20120514
CATEGORIES=	games
MASTER_SITES=	SF/marathon/Aleph%20One/2012-05-14
DISTNAME=	AlephOne-${PORTVERSION}

MAINTAINER=	fiziologus@gmail.com
COMMENT=	The open source version of Bungie's Marathon game

BUILD_DEPENDS+=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs

USE_GMAKE=	yes

USES=		pkgconfig
USE_BZIP2=	yes
USE_SDL+=	image net sdl sound
USE_GL=		yes
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-alsa --disable-sndfile
CONFIGURE_ENV=	PKG_CONFIG="${PKG_CONFIG}"

DATADIR=	${PREFIX}/share/AlephOne

MAN6=		alephone.6

OPTIONS_DEFINE=	MAD OGG SPEEX SMPEG TTF ZZIP
SMPEG_DESC=	Use SMPEG for movie playback
TTF_DESC=	Enable SDL_ttf font rendering
ZZIP_DESC=	Enable zziplib support

OPTIONS_DEFAULT=	MAD OGG SPEEX SMPEG TTF ZZIP

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAD}
LIB_DEPEND+=	mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if ${PORT_OPTIONS:MOGG}
LIB_DEPEND+=	vorbisfile.6:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=--disable-speex
.endif

.if ${PORT_OPTIONS:MSMPEG}
LIB_DEPENDS+=	smpeg.1:${PORTSDIR}/multimedia/smpeg
.else
CONFIGURE_ARGS+=--disable-smpeg
.endif

.if ${PORT_OPTIONS:MTTF}
USE_SDL+=	ttf
.else
CONFIGURE_ARGS+=--disable-ttf
.endif

.if ${PORT_OPTIONS:MZZIP}
LIB_DEPENDS+=	zzip.13:${PORTSDIR}/devel/zziplib
.else
CONFIGURE_ARGS+=--disable-zzip
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.html ${DOCSDIR}
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
