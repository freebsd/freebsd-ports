PORTNAME=	tools
DISTVERSIONPREFIX=	v
DISTVERSION=	0.36.0
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Go Tools
WWW=		https://godoc.org/golang.org/x/tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.23
GO_MODULE=	golang.org/x/tools
GO_TARGET=	./cmd/bisect \
		./cmd/bundle \
		./cmd/callgraph \
		./cmd/compilebench \
		./cmd/deadcode \
		./cmd/digraph \
		./cmd/eg \
		./cmd/file2fuzz \
		./cmd/fiximports \
		./cmd/go-contrib-init \
		./cmd/godex \
		./cmd/godoc \
		./cmd/goimports \
		./cmd/gomvpkg \
		./cmd/gonew \
		./cmd/gotype \
		./cmd/goyacc \
		./cmd/html2article \
		./cmd/present \
		./cmd/present2md \
		./cmd/signature-fuzzer/fuzz-driver \
		./cmd/signature-fuzzer/fuzz-runner \
		./cmd/splitdwarf \
		./cmd/ssadump \
		./cmd/stress \
		./cmd/stringer \
		./cmd/toolstash

CONFLICTS_INSTALL=	easygit rubygem-bundler

PLIST_FILES=	${GO_TARGET:T:S,^,bin/,}

OPTIONS_DEFINE=	RARE
RARE_DESC=	install rarely used tools
RARE_VARS=	GO_TARGET+=" \
		./cmd/benchcmp

.include <bsd.port.mk>
