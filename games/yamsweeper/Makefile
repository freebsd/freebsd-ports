# New ports collection makefile for:    yamsweeper
# Version required:	1.9
# Date created:		14 Sep 1996
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/09/21 16:56:45 max Exp $
#

DISTNAME=       yamsweeper-1.9
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.tut.ac.jp/X11/Contrib/Games/

MAINTAINER=	hidekazu@cs.titech.ac.jp

USE_IMAKE=	yes


pre-configure:
	@mv ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.old
	@cp ${FILESDIR}/Imakefile ${WRKSRC}

post-install:
	@chown bin.bin ${PREFIX}/man/man1/yamsweeper.1.gz
	@chown games.bin ${X11BASE}/lib/X11/app-defaults/Yamsweeper

.include <bsd.port.mk>
