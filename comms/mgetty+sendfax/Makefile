# New ports collection makefile for:    mgetty+sendfax
# Version required:     0.99
# Date created:         21 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.11 1996/09/14 01:59:33 asami Exp $
#

DISTNAME=	mgetty-0.99
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/networking/communication/modem/mgetty/
DISTFILES=	mgetty099-Aug07.tar.gz

MAINTAINER=	jmz@FreeBSD.org

IS_INTERACTIVE= yes
MAKE_FLAGS=	prefix=${PREFIX} -f 

pre-install:
	@(cd ${WRKSRC}/doc; ${GMAKE} manpages)

post-install:
	@(cd ${PKGDIR}; export PKG_PREFIX=${PREFIX}; /usr/bin/perl INSTALL _ POST-INSTALL)

.include <bsd.port.mk>
