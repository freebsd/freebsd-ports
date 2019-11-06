# $FreeBSD$

PORTNAME=	zrythm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.097
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern music production system, also known as DAW

BROKEN=		unfetchable

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	kf5-breeze-icons>0:x11-themes/kf5-breeze-icons
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
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

USES=		gettext-tools meson python:3.5+,build gettext-runtime gnome \
		libtool pkgconfig shebangfix xorg
USE_GITLAB=	yes
GL_SITE=	https://git.zrythm.org
GL_COMMIT=	5b1f4efa53ca33090ef7795204dfc387072f58f5
SHEBANG_FILES=	resources/gen-gtk-gresources-xml.py scripts/collect_translatables.sh scripts/meson_post_install.py
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 libxml2 pango
USE_XORG=	x11
GLIB_SCHEMAS=	org.zrythm.gschema.xml
INSTALLS_ICONS=	yes

post-patch: # https://git.zrythm.org/zrythm/zrythm/issues/299
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/ext/midilib/src/*.c

.include <bsd.port.mk>
