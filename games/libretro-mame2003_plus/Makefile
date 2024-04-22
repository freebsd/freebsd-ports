PORTNAME=	libretro-mame2003_plus
DISTVERSION=	0.20231023
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Updated MAME 0.78 for libretro with added game support
WWW=		https://github.com/libretro/mame2003-plus-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	mame2003-plus-libretro
GH_TAGNAME=	79aee414b6f5ab70a6eb257f9273550423e11356

PLIST_FILES=	lib/libretro/mame2003_plus_libretro.so

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mame2003_plus_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.post.mk>
