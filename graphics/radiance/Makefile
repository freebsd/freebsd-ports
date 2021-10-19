PORTNAME=	radiance
DISTVERSION=	0.6.1.20200216
CATEGORIES=	graphics
MASTER_SITES=	https://raw.githubusercontent.com/mpv-player/mpv/v0.32.0/libmpv/:qthelper
PKGNAMESUFFIX=	-video
DISTFILES=	qthelper.hpp:qthelper
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} zbanks-BTrack-1c5b72e_GH0${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Video art software for VJs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Application uses deprecated OpenGL support in libmpv, see the comment in https://github.com/zbanks/radiance/issues/118
EXPIRATION_DATE=	2022-01-19

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libmpv.so:multimedia/mpv \
		libportaudio.so:audio/portaudio \
		librtmidi.so:audio/rtmidi \
		libsamplerate.so:audio/libsamplerate

USES=		cmake compiler:c++14-lang cpe gl localbase:ldflags qt:5
USE_GITHUB=	yes
USE_QT=		core declarative graphicaleffects gui network  quickcontrols widgets \
		buildtools_build qmake_build
USE_GL=		gl glu

GH_ACCOUNT=	zbanks
GH_TAGNAME=	baf2c40
GH_TUPLE=	zbanks:BTrack:1c5b72e:bt/BTrack

CMAKE_ARGS=	-DRADIANCE_SYSTEM_RESOURCES:STRING=${DATADIR}/

PORTSCOUT=	limit:^[0-9\.]*$$ # prevent tags like release-YYYYMMDD

post-patch:
	@${REINPLACE_CMD} '/-march=native/d' ${WRKSRC}/CMakeLists.txt
	@${MKDIR} ${WRKSRC}/mpv && ${CP} ${DISTDIR}/${DIST_SUBDIR}/qthelper.hpp ${WRKSRC}/mpv

.include <bsd.port.mk>
