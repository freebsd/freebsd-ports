# New ports collection makefile for:	qkcc
# Version required:		1.0
# Date created:			03 May 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.9 1998/10/10 05:39:24 steve Exp $
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
EXTRACT_BEFORE_ARGS=	-q
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes
ALL_TARGET=
MAN1=		qkc.1
MANLANG=	ja

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qkc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qkc.1 ${PREFIX}/man/ja/man1

.include <bsd.port.mk>
