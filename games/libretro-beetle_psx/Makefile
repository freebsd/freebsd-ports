PORTNAME=	libretro-beetle_psx
PORTVERSION=	0.20220211
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone port/fork of Mednafen PSX to the Libretro API
WWW=		https://github.com/libretro/beetle-psx-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-psx-libretro
GH_TAGNAME=	88929ae

PLIST_FILES=	lib/libretro/mednafen_psx_libretro.so

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
USE_GCC=	yes:build
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mednafen_psx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.post.mk>
