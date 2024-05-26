PORTNAME=	miniaudio
DISTVERSION=	0.11.21 # upstream sometimes doesn't tag the repository
PORTEPOCH=	1
CATEGORIES=	audio devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C single header audio playback and capture library
WWW=		https://miniaud.io/

LICENSE=	PD MIT
LICENSE_COMB=	dual

USES=		cpe

CPE_VENDOR=	miniaudio_project

USE_GITHUB=	yes
GH_ACCOUNT=	mackron

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/miniaudio/miniaudio.h include/miniaudio/extras/stb_vorbis.c

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/extras
	${INSTALL_DATA} ${WRKSRC}/miniaudio.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/extras/stb_vorbis.c ${STAGEDIR}${PREFIX}/include/${PORTNAME}/extras/stb_vorbis.c

.include <bsd.port.mk>
