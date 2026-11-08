PORTNAME=	github-act-runner
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
CATEGORIES=	devel

MAINTAINER=	hayzam@alchemilla.io
COMMENT=	Self-hosted GitHub Actions runner written in Go
WWW=		https://github.com/ChristopherHX/github-act-runner

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24+,modules
GO_MODULE=	github.com/ChristopherHX/github-act-runner
GO_LDFLAGS=	-X main.version=${DISTVERSION}
CGO_ENABLED=	0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
