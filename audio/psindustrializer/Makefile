PORTNAME=	psindustrializer
DISTVERSION=	0.2.7
DISTVERSIONSUFFIX=	-pre2
CATEGORIES=	audio
MASTER_SITES=	SF/industrializer/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Percussion sounds synthesizer using physical modelling

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libharfbuzz.so:print/harfbuzz \
		libjack.so:audio/jack \
		libpulse.so:audio/pulseaudio

USES=		gettext-runtime gl gmake gnome libtool pkgconfig tar:xz xorg
USE_GNOME=	atk cairo gdkpixbuf2 gtk20 libxml2 pango pangox-compat
USE_GL=		gl glu
USE_XORG=	x11
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa

INSTALL_TARGET=install-strip

.include <bsd.port.mk>
