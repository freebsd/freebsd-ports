PORTNAME=	libretro-freeintv
DISTVERSION=	0.20230417
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libretro emulation core for the Mattel Intellivision
WWW=		https://github.com/libretro/freeintv

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	FreeIntv
GH_TAGNAME=	85bf25a39a34bbc39fe36677175d87c2b597dbe7

PLIST_FILES=	lib/libretro/freeintv_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/freeintv_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
