# New ports collection makefile for:    yamsweeper
# Version required:	1.9
# Date created:		14 Sep 1996
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $Id$
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
	@chmod 4755 ${PREFIX}/bin/yamsweeper
	@chown games.bin ${PREFIX}/bin/yamsweeper
	@chown bin.bin ${PREFIX}/man/man1/yamsweeper.1.gz
	@chmod 755 ${PREFIX}/lib/X11/yamsweeper
	@chown games.bin ${PREFIX}/lib/X11/yamsweeper
	@chown games.bin ${PREFIX}/lib/X11/yamsweeper/yams.log
	@chown games.bin ${X11BASE}/lib/X11/app-defaults/Yamsweeper

.include <bsd.port.mk>
