# New ports collection makefile for:    sxsame
# Date created:         11 December 1999
# Whom:                 Yuichi Narahara
#
# $FreeBSD$
#

PORTNAME=	sxsame
PORTVERSION=	3.02
CATEGORIES=	games
MASTER_SITES=	ftp://stardust.sfc.wide.ad.jp/pub/JG/JG-0.9.1/sources/\
		ftp://jg.cc.hit-u.ac.jp/pub/JG/JG-0.9.1/sources/\
		ftp://ftp.jaist.ac.jp/pub/os/linux/JG/JG-0.9.1/sources/\
		ftp://mirror.nucba.ac.jp/mirror/JG/JG-0.9.1/sources/

MAINTAINER=	aconitum@po.teleway.ne.jp

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
INSTALL_TARGET=	install install.dir
BINOWN=		root
BINGRP=		games
BINMODE=	2755
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}

WRKSRC=         ${WRKDIR}/sxsame-3.02

post-install:
	@${MKDIR} ${PREFIX}/share/doc/sxsame
.for i in INSTALL.jp README.jp
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/sxsame
.endfor

.include <bsd.port.mk>
