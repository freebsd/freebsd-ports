# New ports collection makefile for:   c2man
# Date created:        2001-08-15
# Whom:                bdluevel@heitec.net
#
# $FreeBSD$
#

PORTNAME=	c2man
PORTVERSION=	2.0.42
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.heitec.net/pub/distfiles/ \
		ftp://ftp.ntua.gr/pub/linux/openpkg/sources/DST/c2man/
DISTNAME=	$(PORTNAME)-$(PORTVERSION:C/\.([0-9]*)$/@\1/)

MAINTAINER=	bdluevel@heitec.net
COMMENT=	Generates man pages from C sources

NO_WRKSUBDIR=	yes

MAN1=	c2man.1
PLIST_FILES=	bin/c2man

.include <bsd.port.mk>
