# New ports collection makefile for:	yamsweeper
# Version required:	1.9
# Date created:		14 Sep 1996
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	yamsweeper-1.9
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/os/linux/JG/JG-0.9.1/sources/
EXTRACT_SUFX=	.taz

MAINTAINER=	hidekazu@cs.titech.ac.jp

USE_IMAKE=	yes
MAN1=		yamsweeper.1

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.old
	@${CP} ${FILESDIR}/Imakefile ${WRKSRC}

.include <bsd.port.mk>
