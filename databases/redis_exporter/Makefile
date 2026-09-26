PORTNAME=	redis_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.92.0
CATEGORIES=	databases

MAINTAINER=	arcade@b1t.name
COMMENT=	Prometheus exporter for redis stats
WWW=		https://github.com/oliver006/redis_exporter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.27+,modules

USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/oliver006/${PORTNAME}
GO_BUILDFLAGS=	-v -ldflags "${GO_LD_FLAGS:S|^|-X main.Build|}"
GO_LD_FLAGS=	Version=${DISTVERSION} \
		Date=${:!date -Iseconds -zUTC!} \
		CommitSha=c796e82

TESTING_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
