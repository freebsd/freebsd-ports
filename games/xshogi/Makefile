# New ports collection makefile for:   xshogi 
# Date created:        20 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xshogi
PORTVERSION=	1.2.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	xshogi
DISTNAME=	xshogi-1.2p03

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Japanese chess-like game for X Window System

RUN_DEPENDS=	${LOCALBASE}/libexec/gnushogix:${PORTSDIR}/games/gnushogi

USE_X_PREFIX=	yes
MAKEFILE=	Makefile.custom
MAN6=		xshogi.6
PLIST_FILES=	bin/xshogi

post-configure:
	@${ECHO_CMD} "DISTDIR=${WRKDIR}" >> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} "LOCALBASE=${LOCALBASE}" >> ${WRKSRC}/${MAKEFILE}

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/xshogi
	@${CHMOD} 755 ${PREFIX}/bin/xshogi
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/bin/xshogi
	${INSTALL_MAN} ${WRKSRC}/xshogi.man ${PREFIX}/man/man6/xshogi.6

.include <bsd.port.mk>
