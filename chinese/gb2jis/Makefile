# New ports collection makefile for:        gb2jis
# Date created:     16 September 2000
# Whom:             Zhang Shu
#
# $FreeBSD$
#

PORTNAME=	gb2jis
PORTVERSION=	1.5
CATEGORIES=	chinese
MASTER_SITES=	http://kanji.zinbun.kyoto-u.ac.jp/~yasuoka/ftp/program/
DISTFILES=	gb2jis.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert GuoBiao Hanzi to JIS Kanji

WRKSRC=		${WRKDIR}/gb2jis
ALL_TARGET=

MAN1=		gb2jis.1
MANCOMPRESSED=	yes

post-install:
# install manual
	@${GZIP_CMD} ${PREFIX}/man/man1/gb2jis.1

.include <bsd.port.mk>
