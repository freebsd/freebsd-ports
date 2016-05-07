# $FreeBSD$

PORTNAME=	uuid
PORTVERSION=	0.0.0.20141202
CATEGORIES=	devel
MASTER_SITES=	LOCAL/kuriyama
PKGNAMEPREFIX=	go-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${REVISION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Go library to generates and inspects UUIDs based on RFC 4122

LICENSE=	MIT

USES=		go
REVISION=	35bc42037350
PROJECTHOST=	${PKGNAMEPREFIX}${PORTNAME}
WRKSRC=		${WRKDIR}/go-uuid-${REVISION}
GO_PKGNAME=	code.google.com/p/go-uuid/uuid
GO_TARGET=	code.google.com/p/go-uuid/uuid/uuid

.include <bsd.port.mk>
