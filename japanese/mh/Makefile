# New ports collection makefile for:	mh (Japanese)
# Version required:	6.8.3-JP.2c
# Date created:		28 March 1995
# Whom:			Akito FUJITA <fujita@zoo.ncl.omron.co.jp>
#
# $Id: Makefile,v 1.3 1995/06/24 11:38:50 asami Exp $
#

DISTNAME=	mh-6.8.3
PKGNAME=	jp-mh-6.8.3
MASTER_SITES=	ftp://omrongw.wg.omron.co.jp/pub/net/mail/
CATEGORIES+=	japanese mail
DISTFILES=	mh-6.8.3-JP.2c.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
