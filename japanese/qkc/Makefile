# New ports collection makefile for:	qkcc
# Version required:		1.0
# Date created:			03 May 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	qkcc100
PKGNAME=	ja-qkc-1.0
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1995/oct/ \
		ftp://ftp.iis.u-tokyo.ac.jp/pub1/unix/Kanji/

MAINTAINER=	max@FreeBSD.org

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
ALL_TARGET=
MAN1=		qkc.1
MANLANG=	ja

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qkc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qkc.1 ${PREFIX}/man/ja/man1

.include <bsd.port.mk>
