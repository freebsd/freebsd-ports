# New ports collection makefile for:    scheme48
# Date created:         25 Aug 1997
# Whom:                 jmacd
#
# $FreeBSD$
#

PORTNAME=	scheme48
PORTVERSION=	1.3
CATEGORIES=	lang scheme
MASTER_SITES=	http://s48.org/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Scheme Underground's implementation of R5RS

CONFLICTS=	scsh-*

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"fails to install on ${ARCH}"
.endif

GNU_CONFIGURE=	yes
ALL_TARGET=	enough
STRIP=
MAN1=		scheme48.1

test:
	cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.post.mk>
