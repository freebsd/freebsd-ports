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

WRKSRC=		${WRKDIR}/xpuyo
USE_IMAKE=	yes
XMKMF=		xmkmf

RESTRICTED=	"The author\'s ashamed of the quality of this version"

post-install:
	@${CHMOD} 755 ${PREFIX}/bin/xpuyo
	@${CHOWN} ${BINOWN}.${BINGRP} ${PREFIX}/bin/xpuyo
	@${MKDIR} ${PREFIX}/share/doc/xpuyo
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/xpuyo

.include <bsd.port.mk>
