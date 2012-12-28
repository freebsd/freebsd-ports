# Created by: shanee@augusta.de
# $FreeBSD$

PORTNAME=	rosegarden
PORTVERSION=	12.12.25
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	General purpose music editor and sequencer suite

LICENSE=	GPLv2

BUILD_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		makedepend:${PORTSDIR}/devel/makedepend
LIB_DEPENDS=	asound:${PORTSDIR}/audio/alsa-lib \
		FLAC:${PORTSDIR}/audio/flac \
		jack:${PORTSDIR}/audio/jack \
		lo:${PORTSDIR}/audio/liblo \
		ogg:${PORTSDIR}/audio/libogg \
		samplerate:${PORTSDIR}/audio/libsamplerate \
		sndfile:${PORTSDIR}/audio/libsndfile \
		vorbis:${PORTSDIR}/audio/libvorbis \
		lirc_client:${PORTSDIR}/comms/lirc \
		icuuc:${PORTSDIR}/devel/icu \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		yajl:${PORTSDIR}/devel/yajl \
		curl:${PORTSDIR}/ftp/curl \
		png15:${PORTSDIR}/graphics/png \
		fftw3:${PORTSDIR}/math/fftw3 \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		lrdf:${PORTSDIR}/textproc/liblrdf \
		raptor2:${PORTSDIR}/textproc/raptor2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb
RUN_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		lilypond:${PORTSDIR}/print/lilypond

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	QTLIBDIR=${QT_LIBDIR}
USE_PKGCONFIG=	build
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_XORG=	ice sm x11 xau xdmcp xext xrender
USE_QT4=	gui xml network corelib sql qt3support \
		rcc_build moc_build uic_build linguist_build
USE_GNOME=	libxml2 libxslt
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
