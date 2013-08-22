# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redigo
PORTVERSION=	20130702
CATEGORIES=	databases
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Go client for the Redis database

WRKSRC=		${WRKDIR}/${DISTNAME}/redis
SUBLIBDIR=	github.com/garyburd/${PORTNAME}
GO_PKGNAME=	${SUBLIBDIR}/redis

do-install:
	${MKDIR} ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${INSTALL_DATA} ${GO_WRKDIR_PKG}/${SUBLIBDIR}/redis.a ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${MKDIR} ${GO_LOCAL_SRCDIR}/${GO_PKGNAME}
.for f in conn.go doc.go log.go pool.go pubsub.go redis.go reply.go scan.go script.go
	${INSTALL_DATA} ${GO_WRKSRC}/${f} ${GO_LOCAL_SRCDIR}/${GO_PKGNAME}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
