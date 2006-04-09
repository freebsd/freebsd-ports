# New ports collection makefile for:    sxsame
# Date created:         11 December 1999
# Whom:                 Yuichi Narahara
#
# $FreeBSD$
#

PORTNAME=	sxsame
PORTVERSION=	3.02
CATEGORIES=	games
MASTER_SITES=	http://www.hanzubon.org/mirrors/Vine/VinePlus/1.1/JG-0.9.1/sources/ \
		http://www.asahi-net.or.jp/~fj9y-ynym/ \
		http://ftp.ncnu.edu.tw/FreeBSD/distfiles/ \
		http://mirror.israel.net/pub/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tile-removing puzzle game for the X Window system

USE_IMAKE=	yes
USE_XPM=	yes
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
