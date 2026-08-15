PORTNAME=	libretro-virtualjaguar
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.0
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of Virtual Jaguar to Libretro
WWW=		https://github.com/libretro/virtualjaguar-libretro

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lib gmake
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	virtualjaguar-libretro
USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS=	--exclude .github \
			--exclude docs \
			--exclude site \
			--no-same-owner --no-same-permissions

PLIST_FILES=	lib/libretro/virtualjaguar_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/virtualjaguar_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
