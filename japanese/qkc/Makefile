# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qkc
PORTVERSION=	1.0
CATEGORIES=	japanese
MASTER_SITES=	http://hp.vector.co.jp/authors/VA000501/
DISTNAME=	${PORTNAME}c100

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Quick Kanji Code Converter (C version)

USES=		zip
NO_WRKSUBDIR=	yes
ALL_TARGET=
PLIST_FILES=	bin/qkc man/ja/man1/qkc.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qkc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qkc.1 ${STAGEDIR}${MAN1PREFIX}/man/ja/man1

.include <bsd.port.mk>
