# New ports collection makefile for:	hiredis
# Date created:	   29 December 2010
# Whom:		   Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	hiredis
DISTVERSION=	0.10.1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/antirez/hiredis/tarball/v${DISTVERSION}/
DISTNAME=	antirez-${PORTNAME}-v${DISTVERSION}-0-g${GITVERSION}

MAINTAINER=	magik@roorback.net
COMMENT=	Minimalistic C client library for the Redis database

LICENSE=	BSD

GITVERSION=	3cc6a7f
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/antirez-${PORTNAME}-${GITVERSION}

USE_GMAKE=	yes
CFLAGS+=	-fPIC
USE_LDCONFIG=	yes

.include <bsd.port.mk>
