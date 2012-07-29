# New ports collection makefile for:	xpuzzletama
# Date created:		18 January 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xpuzzletama
PORTVERSION=	1.5b
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://hanzubon.jp/mirrors/Vine/%SUBDIR%/ \
		http://ftp.jaist.ac.jp/pub/Linux/Vine/%SUBDIR%/ \
		http://ftp.riken.go.jp/Linux/vine/%SUBDIR%/ \
		http://ftp.yz.yamagata-u.ac.jp/pub/Linux/Vine/%SUBDIR%/ \
		http://ftp.nara.wide.ad.jp/pub/Linux/vine/%SUBDIR%/ \
		http://ftp.vinelinux.org/pub/Vine/%SUBDIR%/
MASTER_SITE_SUBDIR=	VinePlus/1.1/JG-0.9.1/sources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle tama, a Tetris like game

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
USE_XORG=	xpm
NO_INSTALL_MANPAGES=	yes

PLIST_FILES=	bin/xpuzzletama lib/X11/xpuzzletama/tama_score
PLIST_DIRS=	lib/X11/xpuzzletama

post-install:
	${MKDIR} ${PREFIX}/lib/X11/xpuzzletama
	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m 666 \
		${WRKSRC}/.tama_score ${PREFIX}/lib/X11/xpuzzletama/tama_score

.include <bsd.port.mk>
