# New ports collection makefile for:        gb2jis
# Date created:     8 November 2001
# Whom:             Zhang Shu
#
# $FreeBSD$
#

PORTNAME=	jis2gb
PORTVERSION=	1.5
CATEGORIES=	chinese
MASTER_SITES=	http://kanji.zinbun.kyoto-u.ac.jp/~yasuoka/ftp/program/
DISTFILES=	jis2gb.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert JIS Kanji to GuoBiao Hanzi

WRKSRC=		${WRKDIR}/jis2gb
ALL_TARGET=

MAN1=		jis2gb.1
MANCOMPRESSED=	yes

post-install:
# install manual
	@${GZIP_CMD} ${PREFIX}/man/man1/jis2gb.1

.include <bsd.port.mk>
