# $FreeBSD$

PORTNAME=	bazel-buildtools
DISTVERSION=	0.28.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bazel BUILD file formatter and editor

LICENSE=	APACHE20

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	bazelbuild
GH_PROJECT=	buildtools
GH_TUPLE=	\
		golang:protobuf:v1.3.1:protobuf/vendor/github.com/golang/protobuf \
		google:skylark:a5f7082:skylark/vendor/github.com/google/skylark

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./buildifier \
		./buildifier2 \
		./buildozer \
		./unused_deps

PLIST_FILES=	${GO_TARGET:S/^./bin/}

.include <bsd.port.mk>
