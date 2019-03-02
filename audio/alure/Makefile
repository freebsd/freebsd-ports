# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	alure
PORTVERSION=	1.2
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/alure-releases/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Utility library to help manage common tasks with OpenAL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake openal:soft pkgconfig
USE_LDCONFIG=	yes
LLD_UNSAFE=	yes	# lld disallows preemption of protected visibility syms
CMAKE_OFF=	BUILD_DOCS BUILD_STATIC

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS DUMB EXAMPLES FLAC FLUIDSYNTH MODPLUG MPG123 SNDFILE VORBIS
OPTIONS_DEFAULT=	FLAC SNDFILE VORBIS

DUMB_DESC=		DUMB audio library decoding support

DOCS_CMAKE_BOOL=	INSTALL_DOCS

DUMB_BUILD_DEPENDS=	${LOCALBASE}/include/dumb.h:audio/dumb
DUMB_CMAKE_BOOL=	DUMB

FLAC_CMAKE_BOOL=	FLAC
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

FLUIDSYNTH_CMAKE_BOOL=	FLUIDSYNTH
FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

MODPLUG_CMAKE_BOOL=	MODPLUG
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug

MPG123_CMAKE_BOOL=	MPG123
MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123

SNDFILE_CMAKE_BOOL=	SNDFILE
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile

VORBIS_CMAKE_BOOL=	VORBIS
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
