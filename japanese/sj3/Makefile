# New ports collection makefile for:	SJ3
# Version required:	2.0.1.13
# Date created:		10 Aug 1996
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $Id: Makefile,v 1.5 1997/09/14 21:35:56 max Exp $
#

DISTNAME=	sj3-2.0.1.13
PKGNAME=	ja-sj3-2.0.1.13
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/ \
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	hidekazu@cs.titech.ac.jp

MAN1=		sj3.1 sj3dic.1 sj3mkdic.1 sj3serv.1
MANLANG=	ja

# This port requires xmkmf but installs in /usr/local
#
# NOTE : You must not use 'xmkmf -a', because the running 'make depend' caused a error.

do-configure:
	( cd $(WRKDIR)/sj3-2.0.1.13 ; xmkmf ; make Makefiles )

.include <bsd.port.mk>
