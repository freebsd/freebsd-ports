# New ports collection makefile for:	fargoal
# Date Created:				13 December 2003
# Whom:				 	chris_pressey@yahoo.ca
#
# $FreeBSD$
#

PORTNAME=	fargoal
PORTVERSION=	20030731b
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	squidfighter
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	chris_pressey@yahoo.ca
COMMENT=	Remake of classic roguelike game "Sword of Fargoal"

LIB_DEPENDS=	alleg.41:${PORTSDIR}/devel/allegro

WRKSRC=		${WRKDIR}/fargoal/src
USE_X_PREFIX=	yes
USE_ZIP=	yes
USE_GMAKE=	yes

do-install:
	${MKDIR} ${PREFIX}/share/fargoal
	${MKDIR} ${PREFIX}/share/fargoal/data
	@${INSTALL_DATA} ${WRKSRC}/../data/sof.cfg ${PREFIX}/share/fargoal/data/sof.cfg
	${MKDIR} ${PREFIX}/share/fargoal/gfx
.for i in black.bmp chars.bmp chars_ep.bmp dmz_chars.bmp dmz_layout.bmp \
		dmz_tiles.bmp layout.bmp layout_ep.bmp originalchars.bmp \
		originalset.bmp sword.dat tiles.bmp tiles_ep.bmp
	@${INSTALL_DATA} ${WRKSRC}/../gfx/${i} ${PREFIX}/share/fargoal/gfx/${i}
.endfor
	${MKDIR} ${PREFIX}/share/fargoal/sfx
.for i in attack beacon boom chop clang claw climb clink crash crunch \
		ding down fight gnarl gold intro item levelup move pit potion \
		sacrifice shred shriek slain slash spell step teleport thump \
		ugh up victory
	@${INSTALL_DATA} ${WRKSRC}/../sfx/${i}.wav ${PREFIX}/share/fargoal/sfx/${i}.wav
.endfor
	@${INSTALL_PROGRAM} ${WRKSRC}/../sword ${PREFIX}/bin/sword
	@${SED} s^%%FARGOAL_ROOT%%^${PREFIX}/share/fargoal^g \
		< ${FILESDIR}/fargoal > ${WRKDIR}/fargoal/fargoal
	@${INSTALL_SCRIPT} ${WRKDIR}/fargoal/fargoal ${PREFIX}/bin/fargoal

.include <bsd.port.mk>
