# $FreeBSD$

PORTNAME=	gsequencer
DISTVERSION=	2.1.64
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH/gsequencer/2.1.x

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Advanced Gtk+ sequencer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dssi>0:audio/dssi \
		lv2>0:audio/lv2
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libinstpatch-1.0.so:audio/libinstpatch \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	dssi>0:audio/dssi

USES=		desktop-file-utils gettext-runtime gmake gnome libtool localbase pkgconfig shared-mime-info
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa --enable-oss
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 libxml2 pango
USE_XORG=	x11
USE_GCC=	yes # the project uses gnu99 extensions, clang fails even with USE_CSTD=gnu99. Suggestions how to build with clang are welcome.
USE_CSTD=	gnu99
USE_LDCONFIG=	yes

LDFLAGS+=	-luuid

INSTALLS_ICONS=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=			JACK PULSEAUDIO

JACK_CONFIGURE_ENABLE=		jack
JACK_LIB_DEPENDS=		libjack.so:audio/jack

PULSEAUDIO_CONFIGURE_ENABLE=	pulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc-base

.include <bsd.port.mk>
