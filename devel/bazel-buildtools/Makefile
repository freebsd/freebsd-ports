PORTNAME=	bazel-buildtools
DISTVERSIONPREFIX=	v
DISTVERSION=	8.5.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bazel BUILD file formatter and editor
WWW=		https://github.com/bazelbuild/buildtools

LICENSE=	APACHE20

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	bazelbuild
GH_PROJECT=	buildtools
GH_TUPLE=	\
		golang:protobuf:v1.5.0:protobuf/vendor/github.com/golang/protobuf \
		protocolbuffers:protobuf-go:v1.33.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		google:skylark:a5f7082:skylark/vendor/github.com/google/skylark \
		google:starlark-go:aaf7be0:starlark_go/vendor/go.starlark.net

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./buildifier \
		./buildozer \
		./unused_deps

PLIST_FILES=	${GO_TARGET:S/^./bin/}

.include <bsd.port.mk>
