# $FreeBSD$

PORTNAME=	zrythm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.139
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern music production system, also known as DAW

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	kf5-breeze-icons>0:x11-themes/kf5-breeze-icons
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcyaml.so:textproc/libcyaml \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
		libgtop-2.0.so:devel/libgtop \
		libjack.so:audio/jack \
		liblilv-0.so:audio/lilv \
		libportaudio.so:audio/portaudio \
		libsamplerate.so:audio/libsamplerate \
		libserd-0.so:devel/serd \
		libsmf.so:audio/libsmf \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libasound.so:audio/alsa-lib \
		libsratom-0.so:audio/sratom \
		libsuil-0.so:audio/suil \
		libyaml.so:textproc/libyaml
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		kf5-breeze-icons>0:x11-themes/kf5-breeze-icons

USES=		autoreconf gettext-tools gmake python:3.5+,build gettext-runtime gnome libtool pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://git.zrythm.org
GL_COMMIT=	09165828f4aec55f82bf8c5a8d194ede9bccf977
GNU_CONFIGURE=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 libxml2 pango
USE_XORG=	x11
GLIB_SCHEMAS=	org.zrythm.gschema.xml
INSTALLS_ICONS=	yes

LDFLAGS+=	-lexecinfo -lm # https://git.zrythm.org/zrythm/zrythm/issues/256

BINARY_ALIAS=	python3=${PYTHON_CMD} make=${GMAKE}

.include <bsd.port.mk>
