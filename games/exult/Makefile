# Created by: Igor Pokrovsky <tiamat@telegraph.spb.ru>

PORTNAME=	exult
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0.20220622
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Engine for Ultima VII (BG, FOV, SI, SS)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis

USES=		autoreconf compiler:c++17-lang gmake libtool localbase \
		pkgconfig sdl xorg

USE_GITHUB=	yes
GH_TAGNAME=	snapshot-${DISTVERSIONPREFIX}${DISTVERSION}
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
USE_SDL=	mixer2 sdl2
USE_XORG=	x11 xext

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-static \
		--enable-shared \
		--with-icondir=${PREFIX}/share/pixmaps

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		ALSA DEBUG DOCS FLUIDSYNTH GIMP STUDIO
OPTIONS_DEFAULT=	STUDIO
OPTIONS_SUB=		yes

GIMP_DESC=	GIMP plugin support
STUDIO_DESC=	Install Exult Studio

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa

DEBUG_CONFIGURE_ON=	--with-debug=full \
			--with-optimization=none
DEBUG_CONFIGURE_OFF=	--with-debug=no

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ENABLE=	fluidsynth

GIMP_LIB_DEPENDS=	libbabl-0.1.so:x11/babl \
			libfontconfig.so:x11-fonts/fontconfig \
			libgegl-0.4.so:graphics/gegl \
			libgegl-npd-0.4.so:graphics/gegl \
			libgimp-2.0.so:graphics/gimp-app \
			libharfbuzz.so:print/harfbuzz \
			libjson-glib-1.0.so:devel/json-glib
GIMP_USES=		gnome
GIMP_USE=		GNOME=gtk20 \
			pango
GIMP_CONFIGURE_ENABLE=	gimp-plugin

STUDIO_LIB_DEPENDS=		libharfbuzz.so:print/harfbuzz
STUDIO_USES=			gnome
STUDIO_USE=			GNOME=libglade2
STUDIO_CONFIGURE_ENABLE=	exult-studio exult-studio-support

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
