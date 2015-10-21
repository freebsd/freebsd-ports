# Created by: Nishika <nishika@cheerful.com>
# $FreeBSD$

PORTNAME=	quasi88
PORTVERSION=	0.6.3
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	http://www.117.ne.jp/~show/pc8801/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PC-8801 emulator for X

USE_XORG=	x11 xext
USES=		gmake tar:tgz
MAKE_ENV=	DATADIR="${DATADIR}" _CC="${CC}" _CFLAGS="${CFLAGS}" \
		_CXX="${CXX}" LD="${CXX}" PROGRAM="${PORTNAME}"
MAKE_ARGS=	ARCH="freebsd"

PORTDOCS=	FAQ.TXT FORMAT.TXT GET-IMAGE.TXT HISTORY.TXT MANUAL.TXT \
		QUASI88.TXT
PORTEXAMPLES=	*
PLIST_FILES=	bin/quasi88

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES SDL

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
MAKE_ENV+=	LSB_FIRST=1
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
MAKE_ENV+=	SDL_VERSION=1 JOYSTICK="joy_sdl"
.else
MAKE_ENV+=	X11_VERSION=1 JOYSTICK="joy_bsd_usb"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^X11_|# X11_|g ; \
		 s|~/quasi88|$${DATADIR}|g ; \
		 s|^LSB_|# LSB_|g ; \
		 s|^JOY|# JOY|g ; \
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
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.rc ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/document && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
