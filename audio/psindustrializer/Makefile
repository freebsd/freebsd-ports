PORTNAME=	psindustrializer
DISTVERSION=	0.2.7
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	SF/industrializer/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Percussion sounds synthesizer using physical modelling
WWW=		https://sourceforge.net/projects/industrializer/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libharfbuzz.so:print/harfbuzz

USES=		gettext-runtime gl gmake gnome libtool pkgconfig tar:xz xorg
USE_GNOME=	atk cairo gdkpixbuf gtk20 libxml2 pango pangox-compat
USE_GL=		gl glu
USE_XORG=	x11
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa

INSTALL_TARGET=	install-strip

OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	JACK PULSE
OPTIONS_DEFAULT=	PULSE

BACKEND_DESC=		Audio Backend

JACK_CONFIGURE_ENABLE=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack

PULSE_DESC=		PulseAudio support
PULSE_CONFIGURE_ENABLE=	pulse
PULSE_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
