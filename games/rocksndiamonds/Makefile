# New ports collection makefile for:	rocksndiamonds
# Version required:	1.2.0
# Date created:		27 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	rocksndiamonds-1.2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
USE_GMAKE=	yes
MAKE_ENV+=	GAME_DIR=${GAME_DIR} X11_PATH=${X11BASE} OPTIONS="${CFLAGS}"
.if ${MACHINE_ARCH} == "alpha"
MAKE_ENV+=	JOYSTICK="-DNO_JOYSTICK"
.endif

GAME_DIR=${PREFIX}/share/rocksndiamonds
DOC_DIR=${PREFIX}/share/doc/rocksndiamonds

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
