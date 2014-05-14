# Created by: sumikawa
# $FreeBSD$

PORTNAME=	kbanner
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	japanese
MASTER_SITES=	http://kanji.zinbun.kyoto-u.ac.jp/~yasuoka/ftp/program/
DISTNAME=	${PORTNAME}2
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays large Japanese letters on the standard output

ALL_TARGET=	kbanner
CFLAGS+=	-Wno-error=return-type
PLIST_FILES=	bin/kbanner man/man1/kbanner.1.gz

.include <bsd.port.mk>
