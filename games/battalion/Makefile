# New ports collection makefile for:	battalion
# Version required:			1.4
# Date created:				17 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/07/20 16:34:57 asami Exp $
#

DISTNAME=	battalion-1.4
CATEGORIES=	games
MASTER_SITES=	http://www.evl.uic.edu/aej/
DISTFILES=	battalionSource1.4.tar.Z battalionSUN4.tar.gz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	MesaGL\\.13\\.:${PORTSDIR}/graphics/Mesa2 \
		MesaGLU\\.13\\.:${PORTSDIR}/graphics/Mesa2

ALL_TARGET=
USE_X11=	yes
WRKSRC=		${WRKDIR}/battalionSource

MAN6=		battalion.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/battalion ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKDIR}/battalionSUN4/battalion.man ${PREFIX}/man/man6/battalion.6
	@ ${MKDIR} ${PREFIX}/share/battalion
	@ ${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/battalion.sho ${PREFIX}/share/battalion
	@ ${MKDIR} ${PREFIX}/share/battalion/DATA
.for file in road tank tree
	@ ${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/DATA/${file}.data ${PREFIX}/share/battalion/DATA
.endfor
	@ ${MKDIR} ${PREFIX}/share/battalion/MUSIC
.for file in 1 2 3 4 5 d1 d2 d3 d4 d5
	@ ${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/MUSIC/${file}.au ${PREFIX}/share/battalion/MUSIC
.endfor
	@ ${MKDIR} ${PREFIX}/share/battalion/SOUNDS
.for file in beam boom crash monsterbeam rocket slag tank tech
	@ ${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/SOUNDS/${file}.au ${PREFIX}/share/battalion/SOUNDS
.endfor
	@ ${MKDIR} ${PREFIX}/share/battalion/TEXTURES
.for file in road screenleft screenright treewood
	@ ${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/TEXTURES/${file}.tex ${PREFIX}/share/battalion/TEXTURES
.endfor

.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/battalion
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/battalion
.for file in 01 02 03 04 05 06 07 08 09 10 11
	@ ${INSTALL_DATA} ${WRKDIR}/battalionSUN4/HELP/bathelp${file}.gif ${PREFIX}/share/doc/battalion
.endfor
.endif

.include <bsd.port.mk>
