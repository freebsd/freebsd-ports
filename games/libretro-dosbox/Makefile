PORTNAME=	libretro-dosbox
PORTVERSION=	0.20220406
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of DOSBox (upstream) to the libretro API
WWW=		https://github.com/libretro/dosbox-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	dosbox-libretro
GH_TAGNAME=	74cd17e
USE_LDCONFIG=	yes


PLIST_FILES=	lib/libretro/dosbox_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/dosbox_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
