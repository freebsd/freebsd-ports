# New ports collection makefile for:    p2c
# Version required:     1.21alpha-07.Dec.93
# Date created:         4 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	p2c-1.21alpha-07.Dec.93
PKGNAME=	p2c-1.21a
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.pal.xgw.fi/pub/gnu/alpha/gnu/ \
		ftp://ftp.clara.net/pub/mirrors/gnu/hurd/ \
		ftp://ftp.obspm.fr/pub1/computing/gnu/hurd/
DISTFILES=	p2c-1.21alpha2.tar.gz

MAINTAINER=	jmz@FreeBSD.org

MAN1=		p2c.1 p2cc.1

pre-install: build
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/include/p2c
	@${INSTALL_MAN} ${WRKSRC}/src/p2cc.man ${PREFIX}/man/man1/p2cc.1

.include <bsd.port.mk>
