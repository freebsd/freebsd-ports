PORTNAME=	libretro-fceumm
DISTVERSION=	0.20230916
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unofficial build of FCEU Ultra by CaH4e3
WWW=		https://github.com/libretro/libretro-fceumm

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	7fad08e5522e5396a1196055fc106be9b5d5de77

PLIST_FILES=	lib/libretro/fceumm_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/fceumm_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
