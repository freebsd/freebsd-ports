# New ports collection makefile for:    sxsame
# Date created:         11 December 1999
# Whom:                 Yuichi Narahara
#
# $FreeBSD$
#

PORTNAME=	sxsame
PORTVERSION=	3.02
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://hanzubon.jp/mirrors/Vine/%SUBDIR%/ \
		http://ftp.jaist.ac.jp/pub/Linux/Vine/%SUBDIR%/ \
		http://ftp.riken.go.jp/Linux/vine/%SUBDIR%/ \
		http://ftp.yz.yamagata-u.ac.jp/pub/Linux/Vine/%SUBDIR%/ \
		http://ftp.nara.wide.ad.jp/pub/Linux/vine/%SUBDIR%/ \
		http://ftp.vinelinux.org/pub/Vine/%SUBDIR%/ \
		http://www.asahi-net.or.jp/~fj9y-ynym/
MASTER_SITE_SUBDIR=	VinePlus/1.1/JG-0.9.1/sources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tile-removing puzzle game for the X Window system

USE_IMAKE=	yes
USE_XORG=	xpm
INSTALL_TARGET=	install install.dir
BINOWN=		root
BINGRP=		games
BINMODE=	2755
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in INSTALL.jp README.jp
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
