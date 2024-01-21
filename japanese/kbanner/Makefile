PORTNAME=	kbanner
PORTVERSION=	2.1
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	http://kanji.zinbun.kyoto-u.ac.jp/~yasuoka/ftp/program/
DISTNAME=	${PORTNAME}2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays large Japanese letters on the standard output
WWW=		http://kanji.zinbun.kyoto-u.ac.jp/~yasuoka/program.html

LICENSE=	NONE

USES=		tar:Z
ALL_TARGET=	kbanner
CFLAGS+=	-Wno-error=return-type
PLIST_FILES=	bin/kbanner share/man/man1/kbanner.1.gz

.include <bsd.port.mk>
