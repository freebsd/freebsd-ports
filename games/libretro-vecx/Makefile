PORTNAME=	libretro-vecx
DISTVERSION=	0.20230601
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vectrex emulator for libretro
WWW=		https://github.com/libretro/libretro-vecx

LICENSE=	GPLv3

USES=		compiler:c++11-lib gmake localbase gl
USE_GL+=	gl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	a401c268e425dc8ae6a301e7fdb9a9e96f39b8ea

PLIST_FILES=	lib/libretro/vecx_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/vecx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
