# New ports collection makefile for:    sxsame
# Date created:         11 December 1999
# Whom:                 Yuichi Narahara
#
# $FreeBSD$
#

PORTNAME=	sxsame
PORTVERSION=	3.02
CATEGORIES=	games
MASTER_SITES=	ftp://stardust.sfc.wide.ad.jp/pub/JG/JG-0.9.1/sources/ \
		ftp://ftp.riken.go.jp/pub/Linux/jg/JG-0.9.1/sources/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/Linux/JG/JG-0.9.1/sources/ \
		ftp://mirror.nucba.ac.jp/mirror/JG/JG-0.9.1/sources/

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
	@${MKDIR} ${PREFIX}/share/doc/sxsame
.for i in INSTALL.jp README.jp
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/sxsame
.endfor
.endif

.include <bsd.port.mk>
