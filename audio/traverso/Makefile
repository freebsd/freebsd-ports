# $FreeBSD$

PORTNAME=	traverso
DISTVERSION=	0.49.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://traverso-daw.org/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Digital audio workstation (DAW) with an innovative user interface

BROKEN=		unfetchable

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libFLAC.so:audio/flac \
		libjack.so:audio/jack \
		liblilv-0.so:audio/lilv \
		libmad.so:audio/libmad \
		libogg.so:audio/libogg \
		libsamplerate.so:audio/libsamplerate \
		libserd-0.so:devel/serd \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom \
		libvorbisfile.so:audio/libvorbis \
		libwavpack.so:audio/wavpack

USES=		cmake compiler:c++11-lang desktop-file-utils localbase:ldflags pkgconfig qt:5
USE_QT=		core gui printsupport xml widgets buildtools_build qmake_build

CMAKE_OFF=	WANT_ALSA

post-install:
		${INSTALL_DATA} ${WRKSRC}/resources/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
		cd ${WRKSRC}/resources/freedesktop/icons && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/hicolor

.include <bsd.port.mk>
