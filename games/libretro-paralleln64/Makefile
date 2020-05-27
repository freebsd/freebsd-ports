# $FreeBSD$

PORTNAME=	libretro-paralleln64
PORTVERSION=	0.20200520
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Improved Nintendo 64 core for libretro

LICENSE=	BITSTREAM_VERA BSD CC0-1.0 GFDL GPLv2 GPLv3 LGPLv3 MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BITSTREAM_VERA=	${WORKSRC}/mupen64plus-core/doc/font-license

USES=		compiler:gcc-c++11-lib gmake gl localbase
USE_GL=		gl
USE_LDCONFIG=	yes

DYNAREC=	${ARCH:S/amd64/x86_64/:C/armv.*/arm/:S/i386/x86/}

MAKE_ARGS=	WITH_DYNAREC=${DYNAREC}

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	parallel-n64
GH_TAGNAME=	43f8930

PLIST_FILES=	lib/libretro/parallel_n64_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/parallel_n64_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
