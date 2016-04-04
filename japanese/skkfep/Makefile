# Created by: Yusuke Nawano <azuki@azkey.org>
# $FreeBSD$

PORTNAME=	skkfep
PORTVERSION=	0.87
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://aitoweb.world.coocan.jp/skkfep/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SKK-like Kana-to-Kanji FrontEnd Processor

RUN_DEPENDS=	ja-skk>0:japanese/skk

USES=		ncurses
CFLAGS+=	-Wno-return-type

PLIST_FILES=	bin/skkfep man/man1/skkfep.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skkfep ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/skkfep.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
