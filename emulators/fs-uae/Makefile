# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fs-uae
PORTVERSION=	2.8.4
CATEGORIES=	emulators
MASTER_SITES=	http://fs-uae.net/stable/${PORTVERSION}/

MAINTAINER=	tomse@oagd.net
COMMENT=	Amiga emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip

LIB_DEPENDS=	libpng.so:graphics/png \
		libopenal.so:audio/openal-soft \
		libmpeg2.so:multimedia/libmpeg2

USES=		desktop-file-utils gettext gl gmake \
		gnome localbase pkgconfig shared-mime-info

USE_SDL=	sdl2
USE_GL=		gl
USE_GNOME=	glib20
USE_XORG=	x11

LLD_UNSAFE=	yes
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-jit
CFLAGS+=	-Wno-c++11-narrowing

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
