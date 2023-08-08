PORTNAME=	alure
PORTVERSION=	1.2
PORTREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/alure-releases/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Utility library to help manage common tasks with OpenAL
WWW=		https://kcat.strangesoft.net/alure.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang openal:soft pkgconfig
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_DOCS BUILD_STATIC
LDFLAGS_i386=	-Wl,-znotext

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS DUMB EXAMPLES FLAC FLUIDSYNTH MODPLUG MPG123 SNDFILE VORBIS
OPTIONS_DEFAULT=	FLAC SNDFILE VORBIS

DUMB_DESC=		DUMB audio library decoding support

DOCS_CMAKE_BOOL=	INSTALL_DOCS
DUMB_BUILD_DEPENDS=	${LOCALBASE}/include/dumb.h:audio/dumb
DUMB_CMAKE_BOOL=	DUMB
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CMAKE_BOOL=	FLAC
FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CMAKE_BOOL=	FLUIDSYNTH
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CMAKE_BOOL=	MODPLUG
MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MPG123_CMAKE_BOOL=	MPG123
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CMAKE_BOOL=	SNDFILE
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CMAKE_BOOL=	VORBIS

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
