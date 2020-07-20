# $FreeBSD$

PORTNAME=	zrythm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.694
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern music production system, also known as DAW

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	fftw3>0:math/fftw3 \
		help2man:misc/help2man \
		kf5-breeze-icons>0:x11-themes/kf5-breeze-icons
LIB_DEPENDS=	libaudec.so:audio/libaudec \
		libavcodec.so:multimedia/ffmpeg \
		libcyaml.so:textproc/libcyaml \
		libgtop-2.0.so:devel/libgtop \
		libcgraph.so:graphics/graphviz \
		libguile-2.2.so:lang/guile2 \
		libjack.so:audio/jack \
		liblilv-0.so:audio/lilv \
		libpcre.so:devel/pcre \
		libportaudio.so:audio/portaudio \
		librubberband.so:audio/rubberband \
		libsamplerate.so:audio/libsamplerate \
		libserd-0.so:devel/serd \
		libsmf.so:audio/libsmf \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libasound.so:audio/alsa-lib \
		libsratom-0.so:audio/sratom \
		libsuil-0.so:audio/suil \
		libyaml.so:textproc/libyaml \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		kf5-breeze-icons>0:x11-themes/kf5-breeze-icons

USES=		compiler:c11 desktop-file-utils gettext-tools gettext-runtime gnome libtool \
		meson pkgconfig python:3.5+,build shared-mime-info shebangfix xorg
USE_GITHUB=	yes
SHEBANG_FILES=	scripts/collect_translatables.sh
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 gtksourceview3 libxml2 pango
USE_XORG=	x11
GLIB_SCHEMAS=	org.zrythm.Zrythm.gschema.xml
INSTALLS_ICONS=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-patch: # https://git.zrythm.org/zrythm/zrythm/issues/299
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/ext/midilib/src/*.c

.include <bsd.port.mk>
