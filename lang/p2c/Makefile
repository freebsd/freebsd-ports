# New ports collection makefile for:    p2c
# Version required:     1.21alpha-07.Dec.93
# Date created:         4 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.5 1995/04/15 05:44:43 asami Exp $
#

DISTNAME=	p2c-1.21alpha-07.Dec.93
PKGNAME=	p2c-1.21a
CATEGORIES+=	languages
MASTER_SITES=	ftp://src.doc.ic.ac.uk/gnu/hurd/
DISTFILES=	p2c-1.21alpha2.tar.gz

MAINTAINER=	jmz@FreeBSD.org

pre-install: build
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/include/p2c
	@cp ${WRKSRC}/src/p2cc.man ${PREFIX}/man/man1/p2cc.1

.include <bsd.port.mk>

