PORTNAME=	bazel-buildtools
DISTVERSIONPREFIX=	v
DISTVERSION=	10.1.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bazel BUILD file formatter and editor
WWW=		https://github.com/bazelbuild/buildtools

LICENSE=	APACHE20

USES=		go:1.27+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	bazelbuild
GH_PROJECT=	buildtools

GO_MODULE=	github.com/bazel-contrib/buildtools/v10
GO_TARGET=	./cmd/${PORTNAME}

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./buildifier \
		./buildozer \
		./unused_deps

PLIST_FILES=	${GO_TARGET:S/^./bin/}

.include <bsd.port.mk>
