# Created by: Alexey V. Antipovsky <kemm@in-line.ru>
# $FreeBSD$

PORTNAME=	fuse
PORTVERSION=	1.5.7
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Free Unix (Sinclair ZX-)Spectrum Emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgcrypt.so:security/libgcrypt \
		libpng.so:graphics/png \
		libspectrum.so:emulators/libspectrum

USES=		gettext gmake gnome localbase perl5 pkgconfig
USE_PERL5=	build
USE_GNOME=	cairo libxml2 glib20
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-alsa --without-joystick

OPTIONS_DEFINE=		AO ICONS ROMS DOCS
OPTIONS_DEFAULT=	ICONS GTK2
OPTIONS_SINGLE=		UI
UI_DESC=		User Interface
ROMS_DESC=		Extra ROM images (128p, 256s, Gluck, IF1, Opus, TrDOS)
OPTIONS_SINGLE_UI=	GTK2 GTK3 SDL SVGALIB

OPTIONS_SUB=		yes
AO_CONFIGURE_WITH=	libao
AO_LIB_DEPENDS=		libao.so:audio/libao
ICONS_USES=		desktop-file-utils shared-mime-info
ICONS_CONFIGURE_ENABLE=	desktop-integration
GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_ON=	--with-gtk
GTK3_USE=		GNOME=gtk30
GTK3_CONFIGURE_ON=	--with-gtk
GTK3_CONFIGURE_ENABLE=	gtk3
SDL_USE=		SDL=sdl
SDL_CONFIGURE_WITH=	sdl
SDL_CONFIGURE_ON=	--without-gtk
SVGALIB_LIB_DEPENDS=	libvga.so:graphics/svgalib
SVGALIB_CONFIGURE_WITH=	svgalib
SVGALIB_CONFIGURE_ON=	--without-gtk
ROMS_RUN_DEPENDS=	fuse-roms>0:emulators/fuse-roms

PORTDOCS=	AUTHORS ChangeLog README THANKS README.copyright

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONS}
INSTALLS_ICONS=	yes
.endif

post-extract:
	${CP} ${WRKSRC}/roms/README.copyright ${WRKSRC}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
