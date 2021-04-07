PORTNAME=	fmoo-audiotools
PORTVERSION=	3.0
PORTREVISION=	4
CATEGORIES=	audio python
MASTER_SITES=	SF/audiotools/audiotools
DISTNAME=	audiotools-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ryu0@ymail.com
COMMENT=	Collection of command line audio handling utilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig python:3.6+
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	CDIO LAME MPG123 OPUS TWOLAME VORBIS
OPTIONS_DEFAULT=CDIO MPG123 OPUS TWOLAME VORBIS

CDIO_LIB_DEPENDS=	libcdio_cdda.so:sysutils/libcdio-paranoia
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame
VORBIS_LIB_DEPENDS=	libvorbisenc.so:audio/libvorbis

CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.options.mk>

post-configure:
	@${ECHO_CMD} '[Libraries]'             >  ${WRKSRC}/setup.cfg
	@${ECHO_CMD} 'alsa: no'                >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} 'libdvd-audio: no'        >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} 'libpulse: no'            >> ${WRKSRC}/setup.cfg

.if ${PORT_OPTIONS:MCDIO}
	@${ECHO_CMD} 'libcdio_paranoia: probe' >> ${WRKSRC}/setup.cfg
.else
	@${ECHO_CMD} 'libcdio_paranoia: no'    >> ${WRKSRC}/setup.cfg
.endif

.if ${PORT_OPTIONS:MLAME}
	@${ECHO_CMD} 'mp3lame: probe'          >> ${WRKSRC}/setup.cfg
.else
	@${ECHO_CMD} 'mp3lame: no'             >> ${WRKSRC}/setup.cfg
.endif

.if ${PORT_OPTIONS:MMPG123}
	@${ECHO_CMD} 'libmpg123: probe'        >> ${WRKSRC}/setup.cfg
.else
	@${ECHO_CMD} 'libmpg123: no'           >> ${WRKSRC}/setup.cfg
.endif

.if ${PORT_OPTIONS:MOPUS}
	@${ECHO_CMD} 'opus: probe'             >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} 'opusfile: probe'         >> ${WRKSRC}/setup.cfg
.else
	@${ECHO_CMD} 'opus: no'                >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} 'opusfile: no'            >> ${WRKSRC}/setup.cfg
.endif

.if ${PORT_OPTIONS:MTWOLAME}
	@${ECHO_CMD} 'twolame: probe'          >> ${WRKSRC}/setup.cfg
.else
	@${ECHO_CMD} 'twolame: no'             >> ${WRKSRC}/setup.cfg
.endif

.if ${PORT_OPTIONS:MVORBIS}
	@${ECHO_CMD} 'vorbisenc: probe'        >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} 'vorbisfile: probe'       >> ${WRKSRC}/setup.cfg
.else
	@${ECHO_CMD} 'vorbisenc: no'           >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} 'vorbisfile: no'          >> ${WRKSRC}/setup.cfg
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/audiotools/*.so

.include <bsd.port.mk>
