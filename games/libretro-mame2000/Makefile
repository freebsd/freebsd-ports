PORTNAME=	libretro-mame2000
DISTVERSION=	0.20230425
CATEGORIES=	games

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MAME (0.37b5) for libretro
WWW=		https://github.com/libretro/mame2000-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib dos2unix gmake
DOS2UNIX_FILES=	src/cpu/tms9900/99xxstat.h
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	mame2000-libretro
GH_TAGNAME=	720b8ad4cbd76abd57b9aeced9ba541dc8476f7f
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libretro/mame2000_libretro.so

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mame2000_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.post.mk>
