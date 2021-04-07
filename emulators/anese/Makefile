PORTNAME=	anese
PORTVERSION=	0.9.1
CATEGORIES=	emulators

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	NES Emulator written for fun and learning

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:insource compiler:c++11-lang sdl

USE_GITHUB=	yes
GH_ACCOUNT=	daniel5151
GH_PROJECT=	ANESE

USE_LDCONFIG=	yes
USE_SDL=	sdl2

PLIST_FILES=	bin/anese

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
