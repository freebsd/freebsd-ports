# New ports collection makefile for:    mtools
# Version required:     2.0.7
# Date created:         5 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.5 1995/07/13 01:13:14 asami Exp $
#

DISTNAME=	mtools-2.0.7
CATEGORIES+=	emulators
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

MAINTAINER=	jmz@FreeBSD.org

MAKE_FLAGS=	PREFIX=${PREFIX}
MAKEFILE=

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
