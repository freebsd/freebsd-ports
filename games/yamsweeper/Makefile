# Created by: Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
# $FreeBSD$

PORTNAME=	yamsweeper
PORTVERSION=	1.9
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://hanzubon.jp/mirrors/Vine/%SUBDIR%/ \
		http://ftp.jaist.ac.jp/pub/Linux/Vine/%SUBDIR%/ \
		http://ftp.riken.go.jp/Linux/vine/%SUBDIR%/ \
		http://ftp.yz.yamagata-u.ac.jp/pub/Linux/Vine/%SUBDIR%/ \
		http://ftp.nara.wide.ad.jp/pub/Linux/vine/%SUBDIR%/ \
		http://ftp.vinelinux.org/pub/Vine/%SUBDIR%/
MASTER_SITE_SUBDIR=	VinePlus/1.1/JG-0.9.1/sources
EXTRACT_SUFX=	.taz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Mine Sweeper

USES=		imake
USE_XORG=	x11 xaw xext xmu xt xpm sm ice
MAN1=		yamsweeper.1

pre-configure:
	@${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.old
	@${CP} ${FILESDIR}/Imakefile ${WRKSRC}

.include <bsd.port.mk>
