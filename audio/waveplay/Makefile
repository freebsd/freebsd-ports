# New ports collection makefile for:    waveplay
# Date created:         23 Jan 1999
# Whom:                 Yoshihide SONODA <ysonoda@dontaku.csce.kyushu-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=		waveplay
PORTVERSION=		2001.09.24
CATEGORIES=		audio
MASTER_SITES=		http://sore.totto.to/~ysonoda/FreeBSD/ports/
DISTNAME=		waveplay-20010924

MAINTAINER=		yshd@na.rim.or.jp
COMMENT=	A simple wav file player

MAN1=			waveplay.1
MANLANG=		"" ja
ONLY_FOR_ARCHS=		i386
PLIST_FILES=		bin/waveplay

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/waveplay ${PREFIX}/bin/waveplay
	${INSTALL_MAN} ${WRKSRC}/waveplay.1 ${PREFIX}/man/man1/waveplay.1
	${INSTALL_MAN} ${WRKSRC}/waveplay.ja.1 ${PREFIX}/man/ja/man1/waveplay.1

.include <bsd.port.mk>
