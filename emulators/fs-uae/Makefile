# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fs-uae
PORTVERSION=	3.0.2
CATEGORIES=	emulators
MASTER_SITES=	http://fs-uae.net/stable/${PORTVERSION}/

MAINTAINER=	sirdice@gmail.com
COMMENT=	Amiga emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libmpeg2.so:multimedia/libmpeg2 \
		libopenal.so:audio/openal-soft \
		libpng.so:graphics/png

USES=		compiler:c11 desktop-file-utils gettext gl gmake gnome \
		localbase pkgconfig sdl shared-mime-info xorg

USE_SDL=	sdl2
USE_GL=		gl
USE_GNOME=	glib20
USE_XORG=	x11

INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-c++11-narrowing
LDFLAGS_i386=	-Wl,-znotext

OPTIONS_DEFINE=	DOCS DEBUG
OPTIONS_DEFINE_i386=	JIT
OPTIONS_DEFINE_amd64=	JIT

JIT_DESC=	Enable JIT compiler (experimental)
JIT_CONFIGURE_ENABLE=	jit

post-patch:
	@${REINPLACE_CMD} -e 's|= bind|= ::bind|' \
		${WRKSRC}/src/od-fs/bsdsocket_posix.cpp \
		${WRKSRC}/src/support/socket.cpp

.include <bsd.port.mk>
