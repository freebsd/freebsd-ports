# New ports collection makefile for:    p2c
# Date created:         4 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	p2c
PORTVERSION=	1.21a
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.clara.net/pub/mirrors/gnu/hurd/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/netsw/Pascal/ \
		ftp://ftp.simcb.ru/pub/unix/src/
DISTFILES=	p2c-1.21alpha2.tar.gz

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	Pascal to C translator

WRKSRC=		${WRKDIR}/p2c-1.21alpha-07.Dec.93
MAN1=		p2c.1 p2cc.1

pre-install: build
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/include/p2c
	@${INSTALL_MAN} ${WRKSRC}/src/p2cc.man ${PREFIX}/man/man1/p2cc.1

.include <bsd.port.mk>
