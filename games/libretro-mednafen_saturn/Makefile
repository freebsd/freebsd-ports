PORTNAME=	libretro-mednafen_saturn
DISTVERSION=	0.20230528
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone port of Mednafen Saturn to libretro
WWW=		https://github.com/libretro/beetle-saturn-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-saturn-libretro
GH_TAGNAME=	cd395e9e3ee407608450ebc565e871b24e7ffed6

CFLAGS+=	-fcommon

PLIST_FILES=	lib/libretro/mednafen_saturn_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mednafen_saturn_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
