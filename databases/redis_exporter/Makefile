PORTNAME=	redis_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.83.0
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	arcade@b1t.name
COMMENT=	Prometheus exporter for redis stats
WWW=		https://github.com/oliver006/redis_exporter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR=	redis_exporter

GO_MODULE=	github.com/oliver006/redis_exporter
GO_BUILDFLAGS=	-v -ldflags "${GO_LD_FLAGS:S|^|-X main.Build|}"
GO_LD_FLAGS=	Version=${DISTVERSION} \
		Date=${:!date -Iseconds -zUTC!} \
		CommitSha=1c261b8

PLIST_FILES=	bin/redis_exporter

.include <bsd.port.mk>
