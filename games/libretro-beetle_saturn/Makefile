PORTNAME=	libretro-beetle_saturn
PORTVERSION=	0.20210622
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Standalone port of Mednafen Saturn to libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-saturn-libretro
GH_TAGNAME=	ee5b214

CFLAGS+=	-fcommon

PLIST_FILES=	lib/libretro/mednafen_saturn_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mednafen_saturn_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
