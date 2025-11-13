PORTNAME=	exult
DISTVERSION=	1.12.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/exult/exult-all-versions/${DISTVERSION:R}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Engine for Ultima VII (BG, FOV, SI, SS)
WWW=		http://exult.info

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libogg.so:audio/libogg \
		libpng16.so:graphics/png \
		libvorbis.so:audio/libvorbis

USES=		autoreconf compiler:c++17-lang gmake libtool localbase \
		pkgconfig sdl xorg
USE_GNOME=	cairo gdkpixbuf
USE_SDL=	sdl2
USE_XORG=	x11 xext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-shared \
		--with-icondir=${PREFIX}/share/pixmaps

SUB_FILES=	pkg-message
PORTDOCS=	*

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
			libgegl-0.4.so:graphics/gegl \
			libgegl-npd-0.4.so:graphics/gegl \
			libgexiv2.so:graphics/gexiv2 \
			libgimp-3.0.so:graphics/gimp3-app \
			libharfbuzz.so:print/harfbuzz \
			libjson-glib-1.0.so:devel/json-glib
GIMP_USES=		gnome
GIMP_USE=		GNOME=gtk30,pango

GIMP_CONFIGURE_ENABLE=	gimp-plugin

STUDIO_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz \
			libicuuc.so:devel/icu
STUDIO_USES=			gnome
STUDIO_USE=			GNOME=gtk30
STUDIO_CONFIGURE_ENABLE=	exult-studio exult-studio-support

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
