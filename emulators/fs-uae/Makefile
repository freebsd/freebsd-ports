# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fs-uae
PORTVERSION=	2.4.0
CATEGORIES=	emulators
MASTER_SITES=	http://fs-uae.net/stable/${PORTVERSION}/

MAINTAINER=	tomse@oagd.net
COMMENT=	Amiga emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libopenal.so:${PORTSDIR}/audio/openal

USES=		gettext gmake pkgconfig
USE_SDL=	sdl
USE_GL=		gl
USE_GNOME=	glib20
INSTALLS_ICONS=	yes
MAKE_ARGS+=	prefix=${PREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
CFLAGS+=	-DFreeBSD8
.endif

.include <bsd.port.post.mk>
