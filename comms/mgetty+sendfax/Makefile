# New ports collection makefile for:    mgetty+sendfax
# Version required:     0.98
# Date created:         21 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.9 1996/03/13 00:36:40 jmz Exp $
#

DISTNAME=	mgetty-0.99
CATEGORIES+=	comms
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/networking/communication/modem/mgetty/
DISTFILES=	mgetty099-Aug07.tar.gz

MAINTAINER=	jmz@FreeBSD.org

MAKE_FLAGS=	prefix=${PREFIX} -f 

IS_INTERACTIVE= yes

pre-install:
	@(cd ${WRKSRC}/doc; ${GMAKE} manpages)

post-install:
	@(cd ${PKGDIR}; export PKG_PREFIX=${PREFIX}; /usr/bin/perl INSTALL _ POST-INSTALL)

.include <bsd.port.mk>
