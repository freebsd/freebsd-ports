PORTNAME=	libretro-prboom
DISTVERSION=	0.20230528
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of prboom to libretro
WWW=		https://github.com/libretro/libretro-prboom

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	6ec854969fd9dec33bb2cab350f05675d1158969

PLIST_FILES=	lib/libretro/prboom_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/prboom_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
