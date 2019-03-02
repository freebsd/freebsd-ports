# Created by: Igor Pokrovsky <tiamat@telegraph.spb.ru>
# $FreeBSD$

PORTNAME=	exult
PORTVERSION=	1.5.0.20160514
PORTREVISION=	6
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ultima VII engine

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to compile: constant expression evaluates to -1 which cannot be narrowed to type char
BROKEN_armv7=		fails to compile: constant expression evaluates to -1 which cannot be narrowed to type char
BROKEN_aarch64=		fails to compile: constant expression evaluates to -1 which cannot be narrowed to type char

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libpng.so:graphics/png

USE_GITHUB=	yes
GH_TAGNAME=	b15afba

USES=		autoreconf compiler:c++11-lib gmake gnome libtool localbase \
		pkgconfig
USE_CXXSTD=	c++98
USE_XORG=	xext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa \
		--with-icondir=${PREFIX}/share/pixmaps
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS FLUIDSYNTH GIMP STUDIO THUMBNAILER
OPTIONS_SINGLE=		SDL
OPTIONS_SINGLE_SDL=	SDL1 SDL2
OPTIONS_DEFAULT=	SDL1 STUDIO
OPTIONS_SUB=		yes

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ENABLE=\
			fluidsynth
GIMP_DESC=		GIMP plugin support
GIMP_LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app
GIMP_CONFIGURE_ENABLE=	gimp-plugin
SDL1_DESC=		Simple Direct Media Layer 1 support
SDL1_USE=		sdl=mixer
SDL1_CONFIGURE_ARGS=	--with-sdl=sdl12
SDL2_DESC=		Simple Direct Media Layer 2 support
SDL2_USE=		sdl=mixer2
SDL2_CONFIGURE_ARGS=	--with-sdl=sdl2
STUDIO_DESC=		Install Exult Studio
STUDIO_CONFIGURE_ENABLE=\
			exult-studio exult-studio-support
STUDIO_USE=		gnome=libglade2
THUMBNAILER_DESC=	Gnome SHP thumbnailer support
THUMBNAILER_USES=	shared-mime-info
THUMBNAILER_USE=	gnome=libgnomeui
THUMBNAILER_CONFIGURE_ENABLE=\
			gnome-shp-thumbnailer

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
