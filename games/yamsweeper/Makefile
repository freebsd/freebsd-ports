# New ports collection makefile for:    yamsweeper
# Version required:	1.9
# Date created:		14 Sep 1996
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $Id: Makefile,v 1.5 1998/09/28 02:25:34 steve Exp $
#

DISTNAME=       yamsweeper-1.9
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tut.ac.jp/X11/Contrib/Games/

MAINTAINER=	hidekazu@cs.titech.ac.jp

USE_IMAKE=	yes
MAN1=		yamsweeper.1

pre-configure:
	@mv ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.old
	@cp ${FILESDIR}/Imakefile ${WRKSRC}

post-install:
	@${CHOWN} ${BINOWN}.${BINGRP} ${PREFIX}/man/man1/yamsweeper.1.gz
	@${CHOWN} games.${BINGRP} ${X11BASE}/lib/X11/app-defaults/Yamsweeper

.include <bsd.port.mk>
