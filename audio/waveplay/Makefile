# New ports collection makefile for:    waveplay
# Version required:     1.0
# Date created:         23 Jan 1999
# Whom:                 ysonoda@dontaku.csce.kyushu-u.ac.jp
#
# $FreeBSD$
#

DISTNAME=		waveplay-19990123
PKGNAME=		waveplay-1.0
CATEGORIES=		audio
MASTER_SITES=		http://dontaku.csce.kyushu-u.ac.jp/~ysonoda/archives/program/FreeBSD/

MAINTAINER=		ysonoda@dontaku.csce.kyushu-u.ac.jp

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/waveplay ${PREFIX}/bin/waveplay

post-install:
	strip ${PREFIX}/bin/waveplay
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/waveplay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/waveplay/
	${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/waveplay/
.endif

.include <bsd.port.mk>
