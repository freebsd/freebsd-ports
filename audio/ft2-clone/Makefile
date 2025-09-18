PORTNAME=	ft2-clone
DISTVERSIONPREFIX=	v
DISTVERSION=	1.99
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Fasttracker II clone
WWW=		https://github.com/8bitbubsy/ft2-clone

LICENSE=	BSD3CLAUSE CC-BY-NC-SA-4.0
LICENSE_COMB=	multi

LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/src/LICENSE.txt
LICENSE_FILE_CC-BY-NC-SA-4.0=	${WRKSRC}/src/gfxdata/bmp/LICENSE.txt

USES=		cmake compiler dos2unix iconv:wchar_t localbase:ldflags sdl
USE_GITHUB=	yes
GH_ACCOUNT=	8bitbubsy
USE_SDL=	sdl2

CFLAGS_i386+=	-msse2
LDFLAGS+=	-lSDL2 -lpthread -lstdc++ -lm -liconv

DESKTOP_ENTRIES=	"FastTracker II Clone" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/ft2-clone.ico" \
			"ft2-clone" \
			"" \
			false

PLIST_FILES=	bin/ft2-clone \
		share/pixmaps/ft2-clone.ico

OPTIONS_DEFINE=		ALSA PULSEAUDIO
OPTIONS_DEFAULT=	ALSA

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CFLAGS+=		-D__LINUX_ALSA__
ALSA_LDFLAGS+=		-lasound

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_LDFLAGS+=	-lpulse

.include <bsd.port.pre.mk>

# clang reports:
# error: invalid argument '-std=c99' not allowed with 'C++'
.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_CSTD=	c99
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/gfxdata/icon/ft2-clone.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.post.mk>
