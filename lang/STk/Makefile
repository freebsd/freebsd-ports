# New ports collection makefile for:    STk
# Version required:     3.1
# Date created:         17 Sep 96 
# Whom:                 jmacd@cs.berkeley.edu
#
# $Id: Makefile,v 1.16 1998/11/11 02:03:40 asami Exp $
#

DISTNAME=       STk-3.1.1
CATEGORIES=	lang
MASTER_SITES=	ftp://kaolin.unice.fr/pub/

MAINTAINER=	jmacd@FreeBSD.ORG

BROKEN_ELF=	yes

USE_XLIB=	yes
PATCH_STRIP=      -p1
GNU_CONFIGURE=	yes
MAKE_FLAGS=  	"prefix=${PREFIX}" -f
STK_ARCH!=	echo "$$(uname)-$$(uname -r)-$$(uname -m)"
PLIST_SUB=	STK_VERSION=3.1.1 STK_ARCH=${STK_ARCH}

post-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
