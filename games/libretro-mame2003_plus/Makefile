PORTNAME=	libretro-mame2003_plus
PORTVERSION=	0.20220406
CATEGORIES=	games

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Updated MAME 0.78 for libretro with added game support
WWW=		https://github.com/libretro/mame2003-plus-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	mame2003-plus-libretro
GH_TAGNAME=	9ab273f

PLIST_FILES=	lib/libretro/mame2003_plus_libretro.so

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mame2003_plus_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.post.mk>
