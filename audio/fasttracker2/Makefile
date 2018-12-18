# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fasttracker2
DISTVERSION=	0.1-b124
CATEGORIES=	audio
MASTER_SITES=	https://16-bits.org/ \
		LOCAL/ehaupt
DISTNAME=	ft2clone-${PORTVERSION:C/.*b/b/}-code

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Fasttracker II clone

LICENSE=	BSD3CLAUSE CC-BY-NC-SA-4.0
LICENSE_COMB=	multi

LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/src/LICENSE.txt
LICENSE_FILE_CC-BY-NC-SA-4.0=	${WRKSRC}/src/gfxdata/bmp/LICENSE.txt

USES=		dos2unix localbase:ldflags zip iconv:wchar_t
USE_SDL=	sdl2

WRKSRC=		${WRKDIR}/ft2-clone-code

DESKTOP_ENTRIES="FastTracker II" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/ft2-clone.ico" \
		"fasttracker2" \
		"" \
		false

PLIST_FILES=	bin/fasttracker2 share/pixmaps/ft2-clone.ico

OPTIONS_DEFINE=	ALSA
OPTIONS_DEFAULT=ALSA

LDFLAGS+=	-lSDL2 -lpthread -lstdc++ -lm -liconv

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CFLAGS+=	-D__LINUX_ALSA__
ALSA_LDFLAGS+=	-lasound

CFLAGS_i386+=	-msse2

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} \
		${WRKSRC}/src/rtmidi/*.cpp ${WRKSRC}/src/gfxdata/*.c ${WRKSRC}/src/*.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/gfxdata/icon/ft2-clone.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
