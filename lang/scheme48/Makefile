# New ports collection makefile for:    scheme48
# Date created:         25 Aug 1997
# Whom:                 jmacd
#
# $FreeBSD$
#

PORTNAME=	scheme48
PORTVERSION=	0.57
CATEGORIES=	lang scheme
MASTER_SITES=	http://s48.org/0.57/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Scheme Underground's implementation of R4RS

.if ${MACHINE_ARCH} != i386
BROKEN=		"fails to install on ${MACHINE_ARCH}"
.endif

GNU_CONFIGURE=	yes
ALL_TARGET=	enough
STRIP=
MAN1=		scheme48.1

.include <bsd.port.mk>
