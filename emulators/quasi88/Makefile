# New ports collection makefile for:	QUASI88
# Date created:		22 May 1999
# Whom:				Nishika <nishika@cheerful.com>
#
# $FreeBSD$
#

PORTNAME=	quasi88
PORTVERSION=	0.6.2
CATEGORIES=	emulators
MASTER_SITES=	http://www.117.ne.jp/~show/pc8801/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PC-8801 emulator for X

USE_XLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	DATADIR="${DATADIR}" _CC="${CC}" _CFLAGS="${CFLAGS}" \
		_CXX="${CXX}" LD="${CXX}"

PORTDOCS=	FAQ.TXT FORMAT.TXT GET-IMAGE.TXT HISTORY.TXT MANUAL.TXT \
		QUASI88.TXT
PLIST_FILES=	bin/quasi88 %%EXAMPLESDIR%%/quasi88.rc
PLIST_DIRS=	%%EXAMPLESDIR%%

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
MAKE_ENV+=	LSB_FIRST=1
.endif

.if defined(WITH_SDL)
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
		 s|gcc|$${_CC}|g ; \
		 s|-O2|$${_CFLAGS}|g ; \
		 s|/usr/X11R6|$${X11BASE}|g ; \
		 s|g++|$${_CXX}|g ; \
		 s|-lstdc++||g ; \
		 s|^LD|# LD|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quasi88 ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/quasi88.rc ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/document/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
