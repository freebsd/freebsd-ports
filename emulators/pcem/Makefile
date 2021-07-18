PORTNAME=	pcem
DISTVERSION=	14
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	https://bitbucket.org/pcem_emulator/pcem/get/
DISTNAME=	faf5d6423060

MAINTAINER=	darkfm@vera.com.uy
COMMENT=	PC/PC-Compatible low-level emulator striving for accuracy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: CGACONST
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: CGACONST

USES=		autoreconf compiler gl gmake localbase:ldflags openal pkgconfig sdl zip
USE_GL=		gl
USE_SDL=	sdl2
USE_WX=		3.0

WRKSRC=		${WRKDIR}/pcem_emulator-pcem-faf5d6423060/
PLIST_FILES=	bin/pcem
CONFIGURE_ARGS=	--enable-release-build --with-wx-config="${WX_CONFIG}"
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	amd64

.include <bsd.port.mk>
