# $FreeBSD$

PORTNAME=	go14
PORTVERSION=	1.4.3
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://golang.org/dl/
DISTNAME=	go${PORTVERSION}.src

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Go programming language

LICENSE=	BSD3CLAUSE

USES=		compiler shebangfix
SHEBANG_LANG=	sh perl
SHEBANG_FILES=	src/*.bash \
		src/cmd/go/*.bash \
		doc/progs/run \
		doc/articles/wiki/*.bash \
		test/bench/shootout/timing.sh \
		misc/nacl/*_exec misc/benchcmp \
		src/net/http/cgi/testdata/*.cgi \
		src/regexp/syntax/*.pl \
		lib/codereview/*.sh

sh_OLD_CMD=	"/usr/bin/env bash"
sh_CMD=		${SH}

WRKSRC=		${WRKDIR}/go

ONLY_FOR_ARCHS=		amd64 armv6 i386

.include <bsd.port.pre.mk>

# If cc is clang, change it to clang to help Go identify the compiler
.if ${COMPILER_TYPE} == "clang" && ${CC} == "cc"
CC=clang
.endif

.if ${ARCH} == "i386"
GOARCH=386
GOOBJ=8
.elif ${ARCH} == "amd64"
GOARCH=amd64
GOOBJ=6
.elif ${ARCH} == "armv6"
GOARCH=arm
GOOBJ=5
.else
IGNORE=		unknown arch ${ARCH}
.endif

PLIST_SUB+=	ARCH=${GOARCH} \
		GOOBJ=${GOOBJ}

post-patch:
	@cd ${WRKSRC} && ${FIND} . -name '*.orig' -delete

do-build:
	cd ${WRKSRC}/src && \
		CC=${CC} \
		GOROOT=${WRKSRC} GOROOT_FINAL=${PREFIX}/go14 \
		GOBIN= GOARCH=${GOARCH} GOOS=${OPSYS:tl} \
		CGO_ENABLED=0 \
		${SH} make.bash

do-install:
	@${CP} -a ${WRKSRC} ${STAGEDIR}${PREFIX}/go14

regression-test: build
	cd ${WRKSRC}/src && GOROOT=${WRKSRC} PATH=${WRKSRC}/bin:${PATH} ${SH} run.bash --no-rebuild --banner

.include <bsd.port.post.mk>
