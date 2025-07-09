PORTNAME=	buildkite-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.1
PORTREVISION=	3
CATEGORIES=	devel sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	CLI tool for Buildkite
WWW=		https://github.com/buildkite/cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:1.24,modules
USE_GITHUB=	yes
GH_ACCOUNT=	buildkite
GH_PROJECT=	cli

GO_MODULE=	github.com/buildkite/cli/v3
GO_BUILDFLAGS+=	-ldflags="-X github.com/buildkite/cli/v3/internal/version.Version=${PORTVERSION}"
GO_ENV+=	GOTOOLCHAIN=local+path

PLIST_FILES=	bin/bk

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/bk

.include <bsd.port.mk>
