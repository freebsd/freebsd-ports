# New ports collection makefile for:    mgetty+sendfax
# Version required:     0.98
# Date created:         21 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.8 1995/04/15 04:58:59 asami Exp $
#

DISTNAME=	mgetty-0.98
CATEGORIES+=	comms
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/networking/communication/modem/mgetty/
DISTFILES=	mgetty+sendfax-0.98.tar.gz

MAINTAINER=	jmz@FreeBSD.org

MAKE_FLAGS=	prefix=${PREFIX} -f 

IS_INTERACTIVE= yes

pre-install:
	@(cd ${WRKSRC}/doc; ${GMAKE} manpages)

post-install:
	@(cd ${PKGDIR}; export PKG_PREFIX=${PREFIX}; /usr/bin/perl INSTALL _ POST-INSTALL)

.include <bsd.port.mk>
