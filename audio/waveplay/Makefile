PORTNAME=	waveplay
PORTVERSION=	2001.09.24
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.sokohiki.org/~yoshi/FreeBSD/ports/
DISTNAME=	waveplay-20010924

MAINTAINER=	yshd@na.rim.or.jp
COMMENT=	Simple wav file player

ONLY_FOR_ARCHS=	i386 amd64 armv7 powerpc powerpc64 powerpc64le
PLIST_FILES=	bin/waveplay \
		man/ja/man1/waveplay.1.gz \
		man/man1/waveplay.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/waveplay ${STAGEDIR}${PREFIX}/bin/waveplay
	${INSTALL_MAN} ${WRKSRC}/waveplay.1 ${STAGEDIR}${PREFIX}/man/man1/waveplay.1
	${INSTALL_MAN} ${WRKSRC}/waveplay.ja.1 ${STAGEDIR}${PREFIX}/man/ja/man1/waveplay.1

.include <bsd.port.mk>
