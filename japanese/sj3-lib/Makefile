# New ports collection makefile for:	SJ3
# Version required:	2.0.1.13
# Date created:		10 Aug 1996
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/08/19 11:37:27 asami Exp $
#

DISTNAME=	sj3-2.0.1.13
PKGNAME=	jp-sj3-2.0.1.13
CATEGORIES+=	japanese
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/ \
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	hidekazu@cs.titech.ac.jp

# This port requires xmkmf but installs in /usr/local
#
# NOTE : You must not use 'xmkmf -a', because the running 'make depend' caused a error.

do-configure:
	( cd $(WRKDIR)/sj3-2.0.1.13 ; xmkmf ; make Makefiles )

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/ja_JP.EUC/man1/sj3.1
	gzip -9nf ${PREFIX}/man/ja_JP.EUC/man1/sj3dic.1
	gzip -9nf ${PREFIX}/man/ja_JP.EUC/man1/sj3mkdic.1
	gzip -9nf ${PREFIX}/man/ja_JP.EUC/man1/sj3serv.1
.endif

.include <bsd.port.mk>
