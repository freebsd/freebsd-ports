# Ports collection makefile for:  hztty
# Date created:			  Wed Sep 24, 1997
# Whom:				  Ada T Lim <ada@not-enough.bandwidth.org>
#
# $FreeBSD$
#

PORTNAME=	hztty
PORTVERSION=	2.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.ifcss.org/pub/software/unix/convert/  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/convert/ \
		ftp://ftp.edu.tw/Chinese/ifcss/software/unix/convert/  \
		ftp://ftp.mpi-sb.mpg.de/pub/chinese/mirror/ftp.ifcss.org/software/unix/convert/

MAINTAINER=	ada@bsd.org
COMMENT=	A translator between GuoBiao / Big5 and HZ

ALL_TARGET=	bsd
MAN1=		hztty.1
PLIST_FILES=	bin/hztty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hztty ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hztty.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
