# $FreeBSD$

PORTNAME=	radiance
DISTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMESUFFIX=	-video

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Video art software for VJs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libmpv.so:multimedia/mpv \
		libportaudio.so:audio/portaudio \
		librtmidi.so:audio/rtmidi \
		libsamplerate.so:audio/libsamplerate

USES=		cmake compiler:c++14-lang gl localbase:ldflags qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	zbanks
GH_TUPLE=	zbanks:BTrack:1c5b72e:bt/BTrack
USE_QT=		core declarative graphicaleffects gui network  quickcontrols widgets \
		buildtools_build qmake_build
USE_GL=		gl glu

CMAKE_ARGS=	-DRADIANCE_SYSTEM_RESOURCES:STRING=${DATADIR}/

post-patch:
	@${REINPLACE_CMD} '/-march=native/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
