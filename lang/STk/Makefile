# New ports collection makefile for:    STk
# Date created:         17 Sep 96 
# Whom:                 jmacd@cs.berkeley.edu
#
# $FreeBSD$
#

PORTNAME=	STk
PORTVERSION=	3.1.1
CATEGORIES=	lang
MASTER_SITES=	ftp://kaolin.unice.fr/pub/

MAINTAINER=	jmacd@FreeBSD.org

USE_XLIB=	yes
PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
MAKE_FLAGS=	"prefix=${PREFIX}" -f
STK_ARCH!=	echo "$$(uname)-$$(uname -r)-$$(uname -m)"
PLIST_SUB=	STK_VERSION=3.1.1 STK_ARCH=${STK_ARCH}

post-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
