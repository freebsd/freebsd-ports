# New ports collection makefile for:	qkcc
# Version required:		1.0
# Date created:			03 May 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.6 1996/11/13 12:41:10 asami Exp $
#

DISTNAME=	qkcc100
PKGNAME=	ja-qkc-1.0
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
MAN1=		qkc.1

do-install:
	install -cs -o bin -g bin -m 755 ${WRKSRC}/qkc ${PREFIX}/bin
	install -c -m 644 -o bin -g bin ${WRKSRC}/qkc.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
