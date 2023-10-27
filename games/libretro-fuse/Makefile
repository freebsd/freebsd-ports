PORTNAME=	libretro-fuse
DISTVERSION=	0.20230623
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of the Fuse Unix Spectrum Emulator to libretro
WWW=		https://github.com/libretro/fuse-libretro

LICENSE=	GPLv3

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	fuse-libretro
GH_TAGNAME=	847dbbd6f787823ac9a5dfacdd68ab181063374e

PLIST_FILES=	lib/libretro/fuse_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/fuse_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
