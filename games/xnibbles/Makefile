# New ports collection makefile for:	xnibbles
# Date created:				2 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xnibbles
PORTVERSION=	1.0.b3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://tinton.braschka.org/Files/pub/games/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/BETA/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple X11 snake game, like one seen in MS-DOS qbasic

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
ALL_TARGET=	linux

MAN6=		xnibbles.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xnibbles ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xnibbles.6 ${MANPREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/xnibbles/sounds
	${INSTALL_DATA} ${WRKSRC}/sounds/*.ub ${PREFIX}/share/xnibbles/sounds
	@${MKDIR} ${PREFIX}/share/xnibbles/levels
.if exists(${PREFIX}/share/xnibbles/levels/LEVELS)
	@${RM} ${PREFIX}/share/xnibbles/levels/LEVELS
.endif
	@${TOUCH} ${PREFIX}/share/xnibbles/levels/LEVELS
.for file in 001 002 003 004 005 006 007 008 009 010 011 012
	@${ECHO_CMD} ${PREFIX}/share/xnibbles/levels/level${file}.xnl >> ${PREFIX}/share/xnibbles/levels/LEVELS
	${INSTALL_DATA} ${WRKSRC}/levels/*.xnl ${PREFIX}/share/xnibbles/levels
.endfor
	@${MKDIR} ${PREFIX}/share/doc/xnibbles
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xnibbles
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/xnibbles
	${INSTALL_DATA} ${WRKSRC}/levels/README ${PREFIX}/share/doc/xnibbles/README.levels

.include <bsd.port.mk>
