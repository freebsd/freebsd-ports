# New ports collection makefile for:	xnibbles
# Version required:			1.0b3
# Date created:				2 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/03/16 03:19:02 hoek Exp $
#

DISTNAME=	xnibbles-1.0BETA3
PKGNAME=	xnibbles-1.0b3
CATEGORIES=	games
MASTER_SITES=	http://www.tjhsst.edu/xnibbles/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

ALL_TARGET=	linux
USE_GMAKE=	yes
USE_X11=	yes
WRKSRC=		${WRKDIR}/xnibbles

MAN6=		xnibbles.6

CFLAGS+=	-I ${X11BASE}/include -L ${X11BASE}/lib

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xnibbles ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/xnibbles.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/xnibbles/sounds
	@${INSTALL_DATA} ${WRKSRC}/sounds/*.ub ${PREFIX}/share/xnibbles/sounds
	@${MKDIR} ${PREFIX}/share/xnibbles/levels
	@if [ -f ${PREFIX}/share/xnibbles/levels/LEVELS ]; then \
		${RM} ${PREFIX}/share/xnibbles/levels/LEVELS; \
	 fi
	@${TOUCH} ${PREFIX}/share/xnibbles/levels/LEVELS
.for file in 001 002 003 004 005 006 007 008 009 010 011 012
	@${ECHO} ${PREFIX}/share/xnibbles/levels/level${file}.xnl >> ${PREFIX}/share/xnibbles/levels/LEVELS
	@${INSTALL_DATA} ${WRKSRC}/levels/*.xnl ${PREFIX}/share/xnibbles/levels
.endfor
	@${MKDIR} ${PREFIX}/share/doc/xnibbles
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xnibbles
	@${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/xnibbles
	@${INSTALL_DATA} ${WRKSRC}/levels/README ${PREFIX}/share/doc/xnibbles/README.levels

.include <bsd.port.mk>
