# Created by: Masanori Kiriake <seiken@nbs.co.jp>

PORTNAME=	ack
PORTVERSION=	1.39
PORTREVISION=	1
CATEGORIES=	japanese converters
MASTER_SITES=	http://ftp.vector.co.jp/06/43/1369/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	Kanji code converter

CONFLICTS_INSTALL=	p5-ack ack

ALL_TARGET=	ack
CFLAGS+=	-Wno-error=return-type

PLIST_FILES=	bin/ack man/ja/man1/ack.1.gz

post-patch:
	@${REINPLACE_CMD} -E 's,(BINARY|MANUAL)),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
