PORTNAME=	libretro-beetle_psx
DISTVERSION=	0.20260614
CATEGORIES=	games

MAINTAINER=	tilde@ultros.pro
COMMENT=	Standalone port/fork of Mednafen PSX to the Libretro API
WWW=		https://github.com/libretro/beetle-psx-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-psx-libretro
GH_TAGNAME=	d460f8342060526678e7fd8222048324c2a80d86
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libretro/mednafen_psx_libretro.so

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
USE_GCC=	yes:build
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mednafen_psx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.post.mk>
