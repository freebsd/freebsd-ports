PORTNAME=	tools
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.11
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	fuz@fuz.su
COMMENT=	Go Tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	golang.org/x/tools
GO_TARGET=	./cmd/auth/cookieauth \
		./cmd/auth/gitauth \
		./cmd/auth/netrcauth \
		./cmd/bundle \
		./cmd/callgraph \
		./cmd/compilebench \
		./cmd/cover \
		./cmd/digraph \
		./cmd/eg \
		./cmd/file2fuzz \
		./cmd/fiximports \
		./cmd/go-contrib-init \
		./cmd/godex \
		./cmd/godoc \
		./cmd/goimports \
		./cmd/gomvpkg \
		./cmd/gorename \
		./cmd/gotype \
		./cmd/goyacc \
		./cmd/guru \
		./cmd/html2article \
		./cmd/present \
		./cmd/present2md \
		./cmd/signature-fuzzer/fuzz-driver \
		./cmd/signature-fuzzer/fuzz-runner \
		./cmd/ssadump \
		./cmd/stress \
		./cmd/stringer \
		./cmd/toolstash

CONFLICTS_INSTALL=	easygit p5-Devel-Cover rubygem-bundler

PLIST_FILES=	${GO_TARGET:T:S,^,bin/,}

OPTIONS_DEFINE=	RARE
RARE_DESC=	install rarely used tools
RARE_VARS=	GO_TARGET+=" \
		./cmd/auth/authtest \
		./cmd/benchcmp \
		./cmd/getgo \
		./cmd/getgo/server \
		./cmd/splitdwarf"

.include <bsd.port.mk>
