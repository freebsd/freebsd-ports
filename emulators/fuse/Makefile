# Created by: Alexey V. Antipovsky <kemm@in-line.ru>
# $FreeBSD$

PORTNAME=	fuse
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Free Unix (Sinclair ZX-)Spectrum Emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libspectrum.so:${PORTSDIR}/emulators/libspectrum \
		libpng15.so:${PORTSDIR}/graphics/png \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

GNU_CONFIGURE=	yes
USES=		pkgconfig gmake
USE_GNOME=	libxml2 glib20

CONFIGURE_ARGS+=--without-alsa --without-joystick
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

OPTIONS_DEFINE=		AO ICONS ROMS
OPTIONS_DEFAULT=	ICONS GTK2
OPTIONS_SINGLE=		UI
UI_DESC=		User Interface
ROMS_DESC=		Extra ROM images (128p, 256s, Gluck, IF1, Opus, TrDOS)
OPTIONS_SINGLE_UI=	GTK2 GTK3 SDL SVGALIB

OPTIONS_SUB=		yes
AO_CONFIGURE_WITH=	libao
AO_LIB_DEPENDS=		libao.so:${PORTSDIR}/audio/libao
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
SVGALIB_LIB_DEPENDS=	libvga.so:${PORTSDIR}/graphics/svgalib
SVGALIB_CONFIGURE_WITH=	svgalib
SVGALIB_CONFIGURE_ON=	--without-gtk
ROMS_RUN_DEPENDS=	fuse-roms>0:${PORTSDIR}/emulators/fuse-roms

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONS}
INSTALLS_ICONS=	yes
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README THANKS \
		roms/README.copyright ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
