# New ports collection makefile for:	xpuzzletama
# Date created:		18 January 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xpuzzletama
PORTVERSION=	1.5b
CATEGORIES=	games
MASTER_SITES=	http://www.hanzubon.org/mirrors/Vine/VinePlus/1.1/JG-0.9.1/sources/ \
		http://hanzubon.jp/Vine/VinePlus/1.1/JG-0.9.1/sources/ \
		http://ftp.ussg.iu.edu/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle tama, a tetris like game

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
USE_XPM=	yes
NO_INSTALL_MANPAGES=	yes

PLIST_FILES=	bin/xpuzzletama lib/X11/xpuzzletama/tama_score
PLIST_DIRS=	lib/X11/xpuzzletama

post-install:
	${MKDIR} ${PREFIX}/lib/X11/xpuzzletama
	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m 666 \
		${WRKSRC}/.tama_score ${PREFIX}/lib/X11/xpuzzletama/tama_score

.include <bsd.port.mk>
