PORTNAME=	qtractor
DISTVERSIONPREFIX=	qtractor_
DISTVERSION=	0_9_25
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/rncbc/qtractor/archive/refs/tags/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio/MIDI multi-track sequencer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libaubio.so:audio/aubio \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjack.so:audio/jack \
		liblilv-0.so:audio/lilv \
		liblo.so:audio/liblo \
		libmad.so:audio/libmad \
		libogg.so:audio/libogg \
		librubberband.so:audio/rubberband \
		libsamplerate.so:audio/libsamplerate \
		libserd-0.so:devel/serd \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom \
		libsuil-0.so:audio/suil \
		libvorbis.so:audio/libvorbis \
		libvorbisenc.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis

USES=		cmake desktop-file-utils gettext-runtime gnome localbase:ldflags pkgconfig qt:5 shared-mime-info
USE_GNOME=	atk cairo gdkpixbuf2 gtk20 gtkmm24 pango
USE_QT=		core gui widgets xml buildtools_build linguisttools_build qmake_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}_${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} \
		's|the ALSA Sequencer kernel module (snd-seq-midi)|alsa-seq-server (installed by audio/alsa-seq-server)|' \
		${WRKSRC}/src/qtractorMainForm.cpp

.include <bsd.port.mk>
