# New ports collection makefile for:    mgetty+sendfax
# Version required:     0.22
# Date created:         21 September 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	mgetty-0.22
CATEGORIES+=	comms
MASTER_SITES=	ftp://hpsystem2.informatik.tu-muenchen.de/pub/comp/networking/communication/modem/mgetty/
DISTFILES=	mgetty+sendfax-0.22.tar.gz

MAINTAINER=	jmz@FreeBSD.org

MAKE_FLAGS=	CC=cc spool=/var/spool LDFLAGS=-lutil prefix=${PREFIX} -f
USE_GMAKE=	yes
IS_INTERACTIVE= yes

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/info
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/man/man4
	@(cd ${WRKSRC}/doc; ${GMAKE} manpages)

.include <bsd.port.mk>
