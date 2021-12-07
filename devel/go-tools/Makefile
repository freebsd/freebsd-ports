# Created by: Carlo Strub <cs@FreeBSD.org>

PORTNAME=	tools
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.8
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	fuz@fuz.su
COMMENT=	Go Tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	golang.org/x/tools
GO_TARGET=	./cmd/auth/authtest \
		./cmd/auth/cookieauth \
		./cmd/auth/gitauth \
		./cmd/auth/netrcauth \
		./cmd/benchcmp \
		./cmd/bundle \
		./cmd/callgraph \
		./cmd/compilebench \
		./cmd/cover \
		./cmd/digraph \
		./cmd/eg \
		./cmd/file2fuzz \
		./cmd/fiximports \
		./cmd/getgo \
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
		./cmd/splitdwarf \
		./cmd/ssadump \
		./cmd/stress \
		./cmd/stringer \
		./cmd/toolstash

PLIST_FILES=	${GO_TARGET:T:S,^,bin/,}

.include <bsd.port.mk>
