# New ports collection makefile for:	yamsweeper
# Date created:		14 Sep 1996
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	yamsweeper
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.hanzubon.org/mirrors/Vine/VinePlus/1.1/JG-0.9.1/sources/ \
		http://ftp.jaist.ac.jp/pub/Linux/Vine/VinePlus/1.1/JG-0.9.1/sources/ \
		http://ftp.nara.wide.ad.jp/pub/Linux/Vine/VinePlus/1.1/JG-0.9.1/sources/
EXTRACT_SUFX=	.taz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Mine Sweeper

USE_IMAKE=	yes
USE_XORG=	x11 xaw xext xmu xt xpm sm ice
MAN1=		yamsweeper.1

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.old
	@${CP} ${FILESDIR}/Imakefile ${WRKSRC}

.include <bsd.port.mk>
