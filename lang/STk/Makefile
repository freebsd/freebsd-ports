# New ports collection makefile for:    STk
# Version required:     3.1
# Date created:         17 Sep 96 
# Whom:                 jmacd@cs.berkeley.edu
#
# $Id: Makefile,v 1.13 1997/03/06 10:58:52 asami Exp $
#

DISTNAME=       STk-3.1.1
CATEGORIES=	lang
MASTER_SITES=	ftp://kaolin.unice.fr/pub/

MAINTAINER=	jmacd@FreeBSD.ORG

PATCH_STRIP=      -p1
GNU_CONFIGURE=	yes
MAKE_FLAGS=  	"prefix=${PREFIX}" -f

post-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
