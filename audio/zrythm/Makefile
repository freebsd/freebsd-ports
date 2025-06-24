PORTNAME=	zrythm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-alpha.26.0.13
PORTREVISION=	14
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern music production system, also known as DAW
WWW=		https://www.zrythm.org/en/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		help2man:misc/help2man \
		${LOCALBASE}/lib/libbacktrace.a:devel/libbacktrace \
		kf6-breeze-icons>0:x11-themes/kf6-breeze-icons
LIB_DEPENDS=	libaudec.so:audio/libaudec \
		libavcodec.so:multimedia/ffmpeg \
		libcyaml.so:textproc/libcyaml \
		libgtop-2.0.so:devel/libgtop \
		libcgraph.so:graphics/graphviz \
		libcurl.so:ftp/curl \
		libfftw3_threads.so:math/fftw3 \
		libfftw3f_threads.so:math/fftw3-float \
		libjack.so:audio/jack \
		libjson-glib-1.0.so:devel/json-glib \
		liblilv-0.so:audio/lilv \
		libpcre.so:devel/pcre \
		libpcre2-8.so:devel/pcre2 \
		libportaudio.so:audio/portaudio \
		libpulse.so:audio/pulseaudio \
		libreproc.so:devel/reproc \
		librubberband.so:audio/rubberband \
		libsamplerate.so:audio/libsamplerate \
		libserd-0.so:devel/serd \
		libsmf.so:audio/libsmf \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libasound.so:audio/alsa-lib \
		libsratom-0.so:audio/sratom \
		libsuil-0.so:audio/suil \
		libvamp-hostsdk.so:audio/vamp-plugin-sdk \
		libxxhash.so:devel/xxhash \
		libyaml.so:textproc/libyaml \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		kf6-breeze-icons>0:x11-themes/kf6-breeze-icons

USES=		compiler:c11 desktop-file-utils gettext-tools gettext-runtime \
		guile:2.2,3.0,alias,conflicts gnome libtool localbase:ldflags \
		meson pkgconfig python:build shared-mime-info shebangfix xorg
USE_GITHUB=	yes
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 gtksourceview3 libxml2 pango
USE_XORG=	x11

SHEBANG_FILES=	scripts/collect_translatables.sh
MESON_ARGS=	-Dlsp_dsp=disabled

GLIB_SCHEMAS=	org.zrythm.Zrythm.gschema.xml

LDFLAGS+=	${LOCALBASE}/lib/libfftw3_threads.so ${LOCALBASE}/lib/libfftw3f_threads.so # these libs are required but aren't returned by pkg-config for fftw3

BINARY_ALIAS=	git=false python3=${PYTHON_CMD}

post-patch: # https://git.zrythm.org/zrythm/zrythm/issues/299
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/ext/midilib/src/*.c

.include <bsd.port.mk>
