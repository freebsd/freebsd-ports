PORTNAME=	libretro-bluemsx
PORTVERSION=	0.20220213
CATEGORIES=	games

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Port of blueMSX to the libretro API
WWW=		https://github.com/libretro/blueMSX-libretro

LICENSE=	GPLv3

USES=		compiler:c++11-lib gmake
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	blueMSX-libretro
GH_TAGNAME=	92d0c41
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libretro/bluemsx_libretro.so

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/bluemsx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
