# $FreeBSD$

PORTNAME=	zrythm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.029
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern music production system, also known as DAW

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	kf5-breeze-icons>0:x11-themes/kf5-breeze-icons
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcyaml.so:textproc/libcyaml \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
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
GL_COMMIT=	07e862579c31120b093ad8618e06a218e9161efd
GNU_CONFIGURE=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 libxml2 pango
USE_XORG=	x11
GLIB_SCHEMAS=	org.zrythm.gschema.xml
INSTALLS_ICONS=	yes

LDFLAGS+=	-lexecinfo

BINARY_ALIAS=	python3=${PYTHON_CMD} make=${GMAKE}

.include <bsd.port.mk>
