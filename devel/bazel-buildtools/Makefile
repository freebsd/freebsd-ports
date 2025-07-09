PORTNAME=	bazel-buildtools
DISTVERSION=	3.2.1
PORTREVISION=	27
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bazel BUILD file formatter and editor
WWW=		https://github.com/bazelbuild/buildtools

LICENSE=	APACHE20

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	bazelbuild
GH_PROJECT=	buildtools
GH_TUPLE=	\
		golang:protobuf:v1.3.1:protobuf/vendor/github.com/golang/protobuf \
		google:skylark:a5f7082:skylark/vendor/github.com/google/skylark \
		google:starlark-go:aaf7be0:starlark_go/vendor/go.starlark.net

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./buildifier \
		./buildifier2 \
		./buildozer \
		./unused_deps

PLIST_FILES=	${GO_TARGET:S/^./bin/}

.include <bsd.port.mk>
