# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redigo
PORTVERSION=	20140714
CATEGORIES=	databases
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Go client for the Redis database

WRKSRC=		${WRKDIR}/${DISTNAME}/redis
GO_PKGNAME=	github.com/garyburd/${PORTNAME}/redis

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
