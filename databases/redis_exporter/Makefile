PORTNAME=	redis_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.75.0
CATEGORIES=	databases

MAINTAINER=	arcade@b1t.name
COMMENT=	Prometheus exporter for redis stats
WWW=		https://github.com/oliver006/redis_exporter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR=	redis_exporter

GO_MODULE=	github.com/oliver006/redis_exporter
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

PLIST_FILES=	bin/redis_exporter

LD_FLAG_X_PREFIX=	-X main
LD_FLAG_STRING=		${STRIP} ${LD_FLAG_X_PREFIX}.BuildVersion=${DISTVERSION}

.include <bsd.port.mk>
