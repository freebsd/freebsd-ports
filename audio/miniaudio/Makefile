PORTNAME=	miniaudio
DISTVERSION=	0.10.33 # upstream doesn't tag the repository
CATEGORIES=	audio devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C single header audio playback and capture library

LICENSE=	PD MIT
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	mackron
GH_TAGNAME=	fca829edefd8389380f8e3ee26cc4b8c426dd742

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/miniaudio.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/miniaudio.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
