# New ports collection makefile for: jhd
# Date created:		Feb 5, 1998
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jhd
PORTVERSION=	2.3
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.iamas.ac.jp/UNIX/File/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Hexdecimal Dump

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

MANLANG=	ja
MAN1=		jhd.1
PLIST_FILES=	bin/jhd

post-build:
	cd ${WRKSRC}; \
	${MV} jhd.1 jhd.1.org; \
	nkf -e jhd.1.org > jhd.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jhd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jhd.1 ${PREFIX}/man/ja/man1

.include <bsd.port.mk>
