# New ports collection makefile for:	qkcc
# Version required:		1.0
# Date created:			03 May 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1996/11/05 04:14:37 max Exp $
#

DISTNAME=	qkcc100
PKGNAME=	jp-qkc-1.0
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1995/oct/ \
		ftp://ftp.iis.u-tokyo.ac.jp/pub1/unix/Kanji/
EXTRACT_SUFX=	.zip

MAINTAINER=	max@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=	unzip
EXTRACT_ARGS=	-q
NO_WRKSUBDIR=	yes
ALL_TARGET=

do-install:
	install -cs -o bin -g bin -m 755 ${WRKSRC}/qkc ${PREFIX}/bin
	install -c -m 644 -o bin -g bin ${WRKSRC}/qkc.1 ${PREFIX}/man/man1
post-install:
	${COMPRESS_MAN} ${PREFIX}/man/man1/qkc.1

.include <bsd.port.mk>
