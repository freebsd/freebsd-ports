PORTNAME=	libretro-mu
DISTVERSION=	0.20230527
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PalmOS emulator to the libretro API
WWW=		https://github.com/libretro/Mu

LICENSE=	GPLv3 MIT
LICENSE_COMB=	multi

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	Mu
GH_TAGNAME=	15bb26daa562e2907eb30b6cebba68a7e825b9b9

PLIST_FILES=	lib/libretro/mu_libretro.so

BUILD_WRKSRC=	${WRKSRC}/libretroBuildSystem

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/libretroBuildSystem/mu_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
