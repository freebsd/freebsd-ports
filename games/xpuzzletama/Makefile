# New ports collection makefile for:	xpuzzletama
# Date created:		18 January 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xpuzzletama
PORTVERSION=	1.5b
CATEGORIES=	games
MASTER_SITES=	ftp://stardust.sfc.wide.ad.jp/pub/JG/JG-0.9.1/sources/ \
		ftp://ftp.riken.go.jp/pub/Linux/jg/JG-0.9.1/sources/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/Linux/JG/JG-0.9.1/sources/ \
		ftp://mirror.nucba.ac.jp/mirror/JG/JG-0.9.1/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle tama, a tetris like game

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
USE_XPM=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	${MKDIR} ${PREFIX}/lib/X11/xpuzzletama
	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m 666 \
		${WRKSRC}/.tama_score ${PREFIX}/lib/X11/xpuzzletama/tama_score

.include <bsd.port.mk>
