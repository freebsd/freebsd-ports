# New ports collection makefile for:	xpuyo
# Date created:		12 October 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xpuyo
PORTVERSION=	0.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.meme.hokudai.ac.jp/pub/games/

MAINTAINER=	nakai@FreeBSD.org
COMMENT=	Puyo-puyo, tetris like puzzle game for X11

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_IMAKE=	yes
XMKMF=		xmkmf

RESTRICTED=	"The author\'s ashamed of the quality of this version"

post-install:
	@${CHMOD} 755 ${PREFIX}/bin/xpuyo
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/bin/xpuyo
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
