PORTNAME=	hydrogen
DISTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/hydrogen-music/${PORTNAME}/releases/download/${DISTVERSION}/ \
		SF/hydrogen/Hydrogen/${DISTVERSION}%20Sources/

MAINTAINER=	FreeBSD@ShaneWare.Biz
COMMENT=	Advanced drum machine
WWW=		http://www.hydrogen-music.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		liblo.so:audio/liblo

USES=		cmake compiler:c++17-lang desktop-file-utils pkgconfig \
		localbase qt:5
USE_LDCONFIG=	yes
USE_QT=		core gui network widgets xml xmlpatterns buildtools:build \
		linguisttools:build qmake:build svg testlib:build

PLIST_SUB=	HYDROGEN_VERSION="${PORTVERSION}"

OPTIONS_DEFINE=		ALSA DEBUG JACK LADSPA LASH OSS PORTAUDIO \
			PULSEAUDIO RDF TEST
OPTIONS_DEFAULT=	JACK LADSPA LIBARCHIVE OSS RDF
OPTIONS_SINGLE=		EXPORT
OPTIONS_SINGLE_EXPORT=	LIBARCHIVE LIBTAR

EXPORT_DESC=		Export support for drumkit
LIBARCHIVE_DESC=	LibArchive support
LIBTAR_DESC=		Libtar support
RDF_DESC=		RDF File support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>=0:audio/alsa-plugins
ALSA_CMAKE_BOOL=	WANT_ALSA

DEBUG_CMAKE_BOOL=	WANT_DEBUG

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	WANT_JACK WANT_JACKSESSION

LADSPA_BUILD_DEPENDS=	ladspa>=0:audio/ladspa
LADSPA_RUN_DEPENDS=	analyseplugin:audio/ladspa
LADSPA_CMAKE_BOOL=	WANT_LADSPA
LADSPA_CMAKE_ON=	-DLADSPA_LIBRARIES:STRING=${LOCALBASE}/lib/ladspa

LASH_LIB_DEPENDS=	liblash.so:audio/lash
LASH_CMAKE_BOOL=	WANT_LASH

LIBARCHIVE_USES=	libarchive
LIBARCHIVE_CMAKE_BOOL=	WANT_LIBARCHIVE

LIBTAR_LIB_DEPENDS=	libtar.so:devel/libtar
LIBTAR_CMAKE_BOOL=	WANT_LIBTAR
LIBTAR_CMAKE_ON=	-DCMAKE_REQUIRED_INCLUDES:STRING=${LOCALBASE}/include/

OSS_CMAKE_BOOL=		WANT_OSS

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	WANT_PORTAUDIO

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WANT_PULSEAUDIO

RDF_LIB_DEPENDS=	liblrdf.so:textproc/liblrdf
RDF_CMAKE_BOOL=		WANT_LRDF
RDF_CMAKE_ON=		-DLRDF_INCLUDE_DIR:STRING=${LOCALBASE}/include/raptor2

TEST_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/cppunit.pc:devel/cppunit
TEST_CMAKE_BOOL=	WANT_CPPUNIT
TEST_LDFLAGS=		-lexecinfo

do-test-TEST-on:
	cd ${WRKSRC} && ./src/tests/tests

.include <bsd.port.mk>
