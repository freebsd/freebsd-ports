# New ports collection makefile for:	yamsweeper
# Date created:		14 Sep 1996
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	yamsweeper
PORTVERSION=	1.9
CATEGORIES=	games
MASTER_SITES=	ftp://stardust.sfc.wide.ad.jp/pub/JG/JG-0.9.1/sources/ \
	 	ftp://ftp.riken.go.jp/pub/Linux/jg/JG-0.9.1/sources/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/Linux/JG/JG-0.9.1/sources/ \
		ftp://mirror.nucba.ac.jp/mirror/JG/JG-0.9.1/sources/
EXTRACT_SUFX=	.taz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Mine Sweeper

USE_IMAKE=	yes
MAN1=		yamsweeper.1

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.old
	@${CP} ${FILESDIR}/Imakefile ${WRKSRC}

.include <bsd.port.mk>
