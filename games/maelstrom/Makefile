# New ports collection makefile for:	Maelstrom
# Version required:			2.0.6
# Date created:				13 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/05/17 23:09:43 mph Exp $
#

DISTNAME=		Maelstrom-1.4.3-L2.0.6-src
PKGNAME=		maelstrom-2.0.6
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.devolution.com/pub/maelstrom/

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=		yes
WRKSRC=			${WRKDIR}/Maelstrom

do-configure:
	@ ${CP} ${FILESDIR}/Makeflags ${WRKSRC}

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/Maelstrom ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/Maelstrom_sound ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/Maelstrom
.for file in Fonts Sounds Sprites
	@ ${INSTALL_DATA} ${WRKSRC}/Maelstrom\ ${file} ${PREFIX}/share/Maelstrom
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/Maelstrom-Scores ${PREFIX}/share/Maelstrom
	@ chown games:games ${PREFIX}/share/Maelstrom/Maelstrom-Scores
	@ chmod 666 ${PREFIX}/share/Maelstrom/Maelstrom-Scores
	@ ${MKDIR} ${PREFIX}/share/Maelstrom/Images
	@ ${INSTALL_DATA} ${WRKSRC}/Images/*n ${PREFIX}/share/Maelstrom/Images

.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/Maelstrom
.for file in Ambrosia.URL BUGS Changelog Copyright README README.Options README.network
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/Maelstrom
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/Doc/* ${PREFIX}/share/doc/Maelstrom
.endif

.include <bsd.port.mk>
