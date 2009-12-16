# New ports collection makefile for:    scheme48
# Date created:         25 Aug 1997
# Whom:                 jmacd
#
# $FreeBSD$
#

PORTNAME=	scheme48
PORTVERSION=	1.8
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.s48.org/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Scheme Underground's implementation of R5RS

USE_GMAKE=	yes

CONFLICTS=	scsh-*

GNU_CONFIGURE=	yes
ALL_TARGET=	enough
MAN1=		scheme48.1

test:
	cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.mk>
