# New ports collection makefile for: libFIRM
# Date created:         22 Nov 2008
# Whom:                 Christoph Mallon <christoph.mallon@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	cparser
PORTVERSION=	0.9.11
CATEGORIES=	lang devel
MASTER_SITES=	SF

MAINTAINER=	armin@frozen-zone.org
COMMENT=	A C99 compiler using libFIRM as backend

LIB_DEPENDS=	firm.0:${PORTSDIR}/devel/libfirm

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/cparser

.include <bsd.port.pre.mk>

MAN1=	cparser.1

do-install:
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/cparser ${PREFIX}/bin
	@${INSTALL_MAN} ${INSTALL_WRKSRC}/cparser.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
