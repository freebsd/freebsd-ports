# New ports collection makefile for:    STk
# Version required:     3.1
# Date created:         17 Sep 96 
# Whom:                 jmacd@cs.berkeley.edu
#
# $Id$
#

DISTNAME=       STk-3.1
CATEGORIES+=	lang
MASTER_SITES=	ftp://kaolin.unice.fr/pub/

MAINTAINER=	jmacd@FreeBSD.ORG

PATCH_STRIP=      -p1
IS_INTERACTIVE=	yes
GNU_CONFIGURE=	yes
MAKE_FLAGS=  	"prefix=${PREFIX}" -f

post-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
