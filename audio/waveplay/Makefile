# New ports collection makefile for:    waveplay
# Date created:         23 Jan 1999
# Whom:                 Yoshihide SONODA <ysonoda@dontaku.csce.kyushu-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=		waveplay
PORTVERSION=		1999.01.23
CATEGORIES=		audio
MASTER_SITES=		http://dontaku.csce.kyushu-u.ac.jp/~ysonoda/archives/program/FreeBSD/
DISTNAME=		waveplay-19990123

MAINTAINER=		ysonoda@dontaku.csce.kyushu-u.ac.jp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/waveplay ${PREFIX}/bin/waveplay
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/waveplay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/waveplay/
	${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/waveplay/
.endif

.include <bsd.port.mk>
