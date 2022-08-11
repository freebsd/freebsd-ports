PORTNAME=	miniaudio
DISTVERSION=	0.10.43 # newer versions break games/jaggedalliance2, see https://github.com/ja2-stracciatella/ja2-stracciatella/issues/1567
#DISTVERSION=	0.11.9 # upstream doesn't tag the repository
PORTEPOCH=	1
CATEGORIES=	audio devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C single header audio playback and capture library

LICENSE=	PD MIT
LICENSE_COMB=	dual

USES=		cpe

CPE_VENDOR=	miniaudio_project

USE_GITHUB=	yes
GH_ACCOUNT=	mackron
GH_TAGNAME=	8686f52e6625e562f4756b946696692c016324ab
#GH_TAGNAME=	4dfe7c4c31df46e78d9a1cc0d2d6f1aef5a5d58c

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/miniaudio/miniaudio.h include/miniaudio/extras/stb_vorbis.c

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/extras
	${INSTALL_DATA} ${WRKSRC}/miniaudio.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/extras/stb_vorbis.c ${STAGEDIR}${PREFIX}/include/${PORTNAME}/extras/stb_vorbis.c

.include <bsd.port.mk>
