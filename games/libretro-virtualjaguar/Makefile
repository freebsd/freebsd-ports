PORTNAME=	libretro-virtualjaguar
DISTVERSION=	0.20230601
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of Virtual Jaguar to Libretro
WWW=		https://github.com/libretro/virtualjaguar-libretro

LICENSE=	GPLv3

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	virtualjaguar-libretro
GH_TAGNAME=	8126e5c504ac7217a638f38e4cd9190822c8abdd

PLIST_FILES=	lib/libretro/virtualjaguar_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/virtualjaguar_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
