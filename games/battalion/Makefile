# New ports collection makefile for:	battalion
# Date created:				17 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	battalion
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.evl.uic.edu/aej/BATTALION/
DISTFILES=	battalionSource1.4.tar.Z battalionSUN4.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monsters, explosions, destruction game for X Window System

WRKSRC=		${WRKDIR}/battalionSource

ALL_TARGET=	# empty
USE_X_PREFIX=	yes
USE_GL=		yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

MAN6=		battalion.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/battalion ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/battalionSUN4/battalion.man \
		${PREFIX}/man/man6/battalion.6
	@${MKDIR} ${PREFIX}/share/battalion
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/battalion.sho \
		${PREFIX}/share/battalion
	@${MKDIR} ${PREFIX}/share/battalion/DATA
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/DATA/*.data \
		${PREFIX}/share/battalion/DATA
	@${MKDIR} ${PREFIX}/share/battalion/MUSIC
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/MUSIC/*.au \
		${PREFIX}/share/battalion/MUSIC
	@${MKDIR} ${PREFIX}/share/battalion/SOUNDS
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/SOUNDS/*.au \
		${PREFIX}/share/battalion/SOUNDS
	@${MKDIR} ${PREFIX}/share/battalion/TEXTURES
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/TEXTURES/*.tex \
		${PREFIX}/share/battalion/TEXTURES
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/battalion
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/battalion
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/HELP/*.gif \
		${PREFIX}/share/doc/battalion
.endif

.include <bsd.port.mk>
