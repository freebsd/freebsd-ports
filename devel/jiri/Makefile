PORTNAME=	jiri
PORTVERSION=	g${TIMESTAMP:S/-/./g:C/T.*//g}
PORTREVISION=	27
CATEGORIES=	devel
MASTER_SITES=	LOCAL/swills
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	jiri

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for multi-repo development
WWW=		https://fuchsia.googlesource.com/jiri

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		cmake:indirect go:modules ninja:build

GITHASH=	1eee1043d12d1baabae7f2466cc0b1646395e32c
TIMESTAMP=	2020-08-28T00:00:00.000000
PLIST_FILES=	bin/jiri
USE_GITHUB=	nodefault
GH_TUPLE=	golang:net:a7b16738d86b:golang_net/vendor/golang.org/x/net \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync

GO_TARGET=	./cmd/jiri
GO_BUILDFLAGS=	-ldflags="\
		-s -w \
		-X fuchsia.googlesource.com/jiri/version.GitCommit=${GITHASH} \
		-X fuchsia.googlesource.com/jiri/version.BuildTime=${TIMESTAMP}"

.include <bsd.port.mk>
