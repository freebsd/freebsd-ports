PORTNAME=	weaviate
DISTVERSIONPREFIX=	v
DISTVERSION=	1.40.2
CATEGORIES=	databases # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vector database that stores both objects and vectors
WWW=		https://weaviate.io/ \
		https://github.com/weaviate/weaviate

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# https://github.com/weaviate/weaviate/issues/9692
NOT_FOR_ARCHS=	armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	port seems to not support 32 bit platforms

USES=		cpe go:modules
USE_GITHUB=	yes

GO_MOD_DIST=	github
GO_MODULE=	github.com/weaviate/weaviate
GO_TARGET=	./cmd/weaviate-server

PLIST_FILES=	bin/${PORTNAME}-server

# The go.mod has a local path replace (grpc/generated/protocol). The framework's
# go-post-fetch hook runs "go mod download all" from the distdir, where only
# the bare go.mod has been fetched, and resolves that local path relative to
# it. Extract the subtree from the main tarball first (this runs before
# go-post-fetch).
post-fetch:
	if [ ! -d "${DISTDIR}/${DIST_SUBDIR}/grpc" ]; then \
		${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
		cd ${DISTDIR}/${DIST_SUBDIR} && \
			${TAR} -xf "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.tar.gz" \
			--strip-components 1 --no-same-owner --no-same-permissions \
			--include "*/grpc/generated/protocol/go.mod" --include "*/grpc/generated/protocol/go.sum"; \
	fi

# how to start: https://docs.weaviate.io/deploy/installation-guides/docker-installation#run-weaviate-with-default-settings

.include <bsd.port.mk>
