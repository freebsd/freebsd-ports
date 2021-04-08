# Created by: Igor Pokrovsky <tiamat@telegraph.spb.ru>

PORTNAME=	exult
PORTVERSION=	1.7.0.20210405
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ultima VII engine

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libpng.so:graphics/png \
		libogg.so:audio/libogg \
		libfreetype.so:print/freetype2

USES=		autoreconf compiler:c++11-lib gmake libtool localbase pkgconfig \
		xorg sdl

USE_GITHUB=	yes
GH_TAGNAME=	6150ae4

USE_CXXSTD=	c++17
USE_XORG=	x11 xext
USE_SDL=	mixer2
USE_GNOME=	gtk30 cairo gdkpixbuf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa --with-sdl=sdl2 \
		--with-icondir=${PREFIX}/share/pixmaps
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS FLUIDSYNTH GIMP STUDIO THUMBNAILER
OPTIONS_DEFAULT=	STUDIO
OPTIONS_SUB=		yes

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ENABLE=	fluidsynth
GIMP_DESC=		GIMP plugin support
GIMP_LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app
GIMP_CONFIGURE_ENABLE=	gimp-plugin

STUDIO_DESC=		Install Exult Studio
STUDIO_CONFIGURE_ENABLE=	exult-studio exult-studio-support
STUDIO_USES=		gnome
STUDIO_USE=		gnome=libglade2
THUMBNAILER_DESC=	Gnome SHP thumbnailer support
THUMBNAILER_USES=	gnome shared-mime-info
THUMBNAILER_USE=	gnome=libgnomeui
THUMBNAILER_CONFIGURE_ENABLE=	gnome-shp-thumbnailer

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
