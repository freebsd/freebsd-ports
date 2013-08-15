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
MAN1=		kbanner.1
PLIST_FILES=	bin/kbanner

.include <bsd.port.mk>
