# New ports collection makefile for:	rocksndiamonds
# Date created:		27 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rocksndiamonds
PORTVERSION=	2.0.1
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/rocksndiamonds/ \
		http://homepages.compuserve.de/rocksndiamonds/

MAINTAINER=	mwest@uct.ac.za

.if defined(WITH_SDL)
LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer
MAKE_ARGS+=	sdl
.endif

USE_XLIB=	yes
USE_GMAKE=	yes
MAKE_ENV+=	RO_GAME_DIR=${GAME_DIR} RW_GAME_DIR=${GAME_DIR}/scores \
		X11_PATH=${X11BASE} OPTIONS="${CFLAGS}"
.if ${MACHINE_ARCH} == "alpha"
MAKE_ENV+=	JOYSTICK="-DNO_JOYSTICK"
.endif

GAME_DIR=${PREFIX}/share/rocksndiamonds
DOC_DIR=${PREFIX}/share/doc/rocksndiamonds

.if defined(WITH_SDL)
pre-patch:
	@${PERL} -pi.orig -e 's:sdl-config:sdl11-config:g' ${WRKSRC}/src/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rocksndiamonds ${PREFIX}/bin
	@${MKDIR} ${GAME_DIR}
	@cd ${WRKSRC}; tar cpf - graphics levels scores sounds | \
		(cd ${GAME_DIR}; tar xpf -)
	@${CHMOD} 777 ${GAME_DIR}/scores
.if !defined(NOPPORTDOCS)
	@${MKDIR} ${DOC_DIR}
.for docfile in CHANGES CREDITS HARDWARE README TODO
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOC_DIR}
.endfor
.endif

.include <bsd.port.mk>
