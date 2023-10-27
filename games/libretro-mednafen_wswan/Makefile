PORTNAME=	libretro-mednafen_wswan
DISTVERSION=	0.20230526
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone port of Mednafen WonderSwan to libretro
WWW=		https://github.com/libretro/beetle-wswan-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-wswan-libretro
GH_TAGNAME=	a0ddcd3f084f5b4eb06acb6e03b8c4707a2f6123

PLIST_FILES=	lib/libretro/mednafen_wswan_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mednafen_wswan_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
