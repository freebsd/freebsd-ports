PORTNAME=	sameboy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
CATEGORIES=	emulators games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Game Boy and Game Boy Color emulator written in C
WWW=		https://sameboy.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rgbds>0:devel/rgbds

USES=		desktop-file-utils gl gmake gnome pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	LIJI32
GH_PROJECT=	SameBoy
USE_GL=		gl
USE_GNOME=	gdkpixbuf
USE_SDL=	sdl2

MAKE_ARGS=	FREEDESKTOP=true \
		WARNINGS="-Wno-error"
ALL_TARGET=	sdl

PORTSCOUT=	limit:^d\.d+\.

OPTIONS_DEFINE=		LIBRETRO
OPTIONS_DEFAULT=	LIBRETRO
OPTIONS_SUB=		yes

LIBRETRO_DESC=	Build libretro core

post-build-LIBRETRO-on:
	@${DO_MAKE_BUILD} -C ${WRKSRC} libretro

post-install-LIBRETRO-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/build/bin/sameboy_libretro.so \
		${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
