PORTNAME=	miniaudio
DISTVERSION=	0.10.42 # upstream doesn't tag the repository
CATEGORIES=	audio devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C single header audio playback and capture library

LICENSE=	PD MIT
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	mackron
GH_TAGNAME=	dbca7a3b44594e0226f887472b31f54aa5f14214

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/miniaudio.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/miniaudio.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
