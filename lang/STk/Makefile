# New ports collection makefile for:    STk
# Version required:     3.1
# Date created:         17 Sep 96 
# Whom:                 jmacd@cs.berkeley.edu
#
# $Id: Makefile,v 1.14 1998/03/08 01:39:21 jmacd Exp $
#

DISTNAME=       STk-3.1.1
CATEGORIES=	lang
MASTER_SITES=	ftp://kaolin.unice.fr/pub/

MAINTAINER=	jmacd@FreeBSD.ORG

BROKEN_ELF=	yes

PATCH_STRIP=      -p1
GNU_CONFIGURE=	yes
MAKE_FLAGS=  	"prefix=${PREFIX}" -f

post-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
