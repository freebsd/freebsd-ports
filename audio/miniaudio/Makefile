PORTNAME=	miniaudio
DISTVERSION=	0.10.35 # upstream doesn't tag the repository
CATEGORIES=	audio devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C single header audio playback and capture library

LICENSE=	PD MIT
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	mackron
GH_TAGNAME=	199d6a7875b4288af6a7b615367c8fdc2019b03c

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/miniaudio.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/miniaudio.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
