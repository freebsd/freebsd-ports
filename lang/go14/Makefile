# $FreeBSD$

PORTNAME=	go14
PORTVERSION=	1.4.3
CATEGORIES=	lang
MASTER_SITES=	http://golang.org/dl/
DISTNAME=	go${PORTVERSION}.src

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Go programming language

LICENSE=	BSD3CLAUSE

USES=		compiler shebangfix
SHEBANG_LANG=	sh
SHEBANG_FILES=	${WRKSRC}/src/*.bash \
		${WRKSRC}/doc/progs/run \
		${WRKSRC}/doc/articles/wiki/*.bash \
		${WRKSRC}/test/bench/shootout/timing.sh

sh_OLD_CMD=	"/usr/bin/env bash"
sh_CMD=		${SH}

WRKSRC=		${WRKDIR}/go
ONLY_FOR_ARCHS=	i386 amd64 armv6

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
