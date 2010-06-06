# New ports collection makefile for:	QUASI88
# Date created:		22 May 1999
# Whom:				Nishika <nishika@cheerful.com>
#
# $FreeBSD$
#

PORTNAME=	quasi88
PORTVERSION=	0.6.3
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.117.ne.jp/~show/pc8801/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PC-8801 emulator for X

USE_XORG=	x11 xext
USE_GMAKE=	yes
MAKE_ENV=	DATADIR="${DATADIR}" _CC="${CC}" _CFLAGS="${CFLAGS}" \
		_CXX="${CXX}" LD="${CXX}" PROGRAM="${PORTNAME}"
MAKE_ARGS=	ARCH="freebsd"

PORTDOCS=	FAQ.TXT FORMAT.TXT GET-IMAGE.TXT HISTORY.TXT MANUAL.TXT \
		QUASI88.TXT
PLIST_FILES=	bin/quasi88 %%EXAMPLESDIR%%/keyconf.rc \
		%%EXAMPLESDIR%%/quasi88.rc
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
		 s|^SDL_|# SDL_|g ; \
		 s|gcc|$${_CC}|g ; \
		 s|-O2|$${_CFLAGS}|g ; \
		 s|/usr/X11R6|$${LOCALBASE}|g ; \
		 s|g++|$${_CXX}|g ; \
		 s|^CXXLIBS|# CXXLIBS|g ; \
		 s|^LD|# LD|g ; \
		 s|^PROGRAM|# PROGRAM|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quasi88 ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.rc ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/document/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
