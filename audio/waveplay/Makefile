# New ports collection makefile for:    waveplay
# Date created:         23 Jan 1999
# Whom:                 Yoshihide SONODA <ysonoda@dontaku.csce.kyushu-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=		waveplay
PORTVERSION=		2000.12.10
CATEGORIES=		audio
MASTER_SITES=		http://sore.totto.to/~ysonoda/FreeBSD/ports/
DISTNAME=		waveplay-20001210

MAINTAINER=		yshd@na.rim.or.jp

MAN1=			waveplay.1
MANLANG=		"" ja

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/waveplay ${PREFIX}/bin/waveplay
	${INSTALL_MAN} ${WRKSRC}/waveplay.1 ${PREFIX}/man/man1/waveplay.1
	${INSTALL_MAN} ${WRKSRC}/waveplay.ja.1 ${PREFIX}/man/ja/man1/waveplay.1

.include <bsd.port.mk>
