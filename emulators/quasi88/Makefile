# Created by: Nishika <nishika@cheerful.com>
# $FreeBSD$

PORTNAME=	quasi88
PORTVERSION=	0.6.4
CATEGORIES=	emulators
MASTER_SITES=	http://www.eonet.ne.jp/~showtime/quasi88/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PC-8801 emulator for X

USES=		gmake tar:tgz xorg
USE_XORG=	x11 xext
MAKE_ENV=	DATADIR="${DATADIR}" _CC="${CC}" _CFLAGS="${CFLAGS}" \
		_CXX="${CXX}" LD="${CXX}" PROGRAM="${PORTNAME}"
MAKE_ARGS=	ARCH="freebsd"

DESKTOP_ENTRIES="Quasi88" "" "" "quasi88" "" ""

PORTDOCS=	FAQ.TXT FORMAT.TXT GET-IMAGE.TXT HISTORY.TXT MANUAL.TXT \
		QUASI88.TXT
PORTEXAMPLES=	keyconf.rc quasi88.rc
PLIST_FILES=	bin/quasi88

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES SDL
OPTIONS_DEFAULT=	SDL

SDL_USES=		sdl
SDL_USE=		sdl=sdl
SDL_MAKE_ENV=		SDL_VERSION=1 X11_JOYSTICK="joy_sdl"
SDL_MAKE_ENV_OFF=	X11_VERSION=1 X11_JOYSTICK="joy_bsd_usb"

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
MAKE_ENV+=	X11_LSB_FIRST=1
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^X11_VERSION|# X11_VERSION|g ; \
		 s|~/quasi88|$${DATADIR}|g ; \
		 s|^X11_LSB|# X11_LSB|g ; \
		 s|^X11_JOY|# X11_JOY|g ; \
		 s|^SDL_|# SDL_|g ; \
		 s|gcc|$${_CC}|g ; \
		 s|-O2|$${_CFLAGS}|g ; \
		 s|/usr/X11R6|$${LOCALBASE}|g ; \
		 s|g++|$${_CXX}|g ; \
		 s|^CXXLIBS|# CXXLIBS|g ; \
		 s|^LD|# LD|g ; \
		 s|^PROGRAM|# PROGRAM|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quasi88 ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/document && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
