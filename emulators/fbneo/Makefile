PORTNAME=	fbneo
DISTVERSION=	1.0.0.3.20260816
CATEGORIES=	emulators

MAINTAINER=	acm@FreeBSD.org
COMMENT=	An emulator for arcade games and select consoles
WWW=		https://github.com/finalburnneo/FBNeo

LICENSE=	FBNeo
LICENSE_NAME=	FBNeo
LICENSE_FILE=	${WRKSRC}/src/license.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	nasm>0:devel/nasm

USES=		compiler:c11 gl gmake perl5 sdl shebangfix

USE_GITHUB=     yes
GH_ACCOUNT=     libretro
GH_PROJECT=     FBNeo
GH_TAGNAME=     0332bb983c8f8a3e9b61cb79ade30f97a5032535

USE_GL=		gl
USE_SDL=	sdl2 image2

SHEBANG_GLOB=	*.pl
PLIST_FILES=	bin/fbneo \
		share/fbneo/gamelist.txt
PLIST_DIRS=	share/fbneo

MAKEFILE=	makefile
ALL_TARGET=	sdl2
MAKE_ENV=	RELEASEBUILD=1
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/fbneo ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/gamelist.txt ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
