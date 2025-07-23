PORTNAME=	libopenmpt
DISTVERSION=	0.8.2
DISTVERSIONSUFFIX=	+release.autotools
CATEGORIES=	audio
MASTER_SITES=	https://lib.openmpt.org/files/libopenmpt/src/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module music library based on OpenMPT
WWW=		https://lib.openmpt.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmpg123.so:audio/mpg123 \
		libvorbis.so:audio/libvorbis

USES=		compiler:c++17-lang cpe gmake libtool pkgconfig
CPE_VENDOR=	openmpt
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-doxygen-doc \
		--with-mpg123 \
		--with-vorbis \
		--with-vorbisfile \
		--without-portaudiocpp

TEST_TARGET=	check

OPTIONS_DEFINE=		DOCS EXAMPLES OPENMPT123 PULSEAUDIO
OPTIONS_DEFAULT=	OPENMPT123
OPTIONS_SUB=		yes

OPENMPT123_DESC=	Enable command line player
PULSEAUDIO_DESC=	Enable PulseAudio support for openmpt123

OPENMPT123_LIB_DEPENDS=		libFLAC.so:audio/flac \
				libogg.so:audio/libogg \
				libportaudio.so:audio/portaudio \
				libsndfile.so:audio/libsndfile
OPENMPT123_CONFIGURE_OFF=	--disable-openmpt123
OPENMPT123_CONFIGURE_WITH=	flac portaudio sndfile

PULSEAUDIO_IMPLIES=		OPENMPT123
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio

pre-configure:
	@${REINPLACE_CMD} -e 's/+release.autotools//' \
		${PATCH_WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopenmpt.so.*

post-install-DOCS-on:
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSE # do not install twice

post-install-EXAMPLES-on:
	@${MV} ${STAGEDIR}${DOCSDIR}/examples ${STAGEDIR}${EXAMPLESDIR}

post-install-EXAMPLES-off:
	@${RM} -rf ${STAGEDIR}${DOCSDIR}/examples

.include <bsd.port.mk>
