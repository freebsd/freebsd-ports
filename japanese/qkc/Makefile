# New ports collection makefile for:	qkcc
# Version required:		1.0
# Date created:			03 May 1996
# Whom:				Masafumi NAKANE <max@sfc.wide.ad.jp>
#
# $Id: porting.sgml,v 1.16 1996/03/21 14:15:01 asami Exp $
#

DISTNAME=	qkcc100
PKGNAME=	qkc-1.0
CATEGORIES+=	japanese
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1995/oct/ \
		ftp://ftp.iis.u-tokyo.ac.jp/pub1/unix/Kanji/
EXTRACT_SUFX=	.zip

MAINTAINER=	max@sfc.wide.ad.jp

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=	unzip
EXTRACT_ARGS=	-q
NO_WRKSUBDIR=	yes
ALL_TARGET=

do-install:
	install -cs -o bin -g bin -m 755 ${WRKSRC}/qkc ${PREFIX}/bin
	install -c -m 644 -o bin -g bin ${WRKSRC}/qkc.1 ${PREFIX}/man/man1
.if !defined(NOMANCOMPRESS)
post-install:
	gzip -9nf ${PREFIX}/man/man1/qkc.1
.endif

.include <bsd.port.mk>
