# Created by: Devon H. O'Dell <devon.odell@gmail.com>
# $FreeBSD$

PORTNAME=	go
PORTVERSION=	1.1.2
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	go${PORTVERSION}.src

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Go programming language

LICENSE=	BSD

USES=		shebangfix
SHEBANG_LANG=	sh
SHEBANG_FILES=	${WRKSRC}/src/*.bash \
		${WRKSRC}/doc/progs/run \
		${WRKSRC}/doc/articles/wiki/*.bash \
		${WRKSRC}/test/bench/shootout/timing.sh

sh_OLD_CMD=	${SETENV} bash
sh_CMD=		${SH}

WRKSRC=		${WRKDIR}/go
USE_GCC=	any
ONLY_FOR_ARCHS=	i386 amd64
SUB_FILES=	pkg-message
SUB_LIST+=	GOOBJ=${GOOBJ} \
		ARCH=${GOARCH} \
		GOOS=${OPSYS:L}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
GOARCH=386
GOOBJ=8
PLIST_SUB+=	ENAM="@comment "
.else
GOARCH=amd64
GOOBJ=6
PLIST_SUB+=	ENAM=""
.endif

PLIST_SUB+=	ARCH=${GOARCH} \
		GOOBJ=${GOOBJ}

post-patch:
	@cd ${WRKSRC} && ${FIND} . -name '*.orig' -delete

do-build:
	cd ${WRKSRC}/src && \
		CC=${CC} \
		GOROOT=${WRKSRC} GOROOT_FINAL=${PREFIX}/go \
		GOBIN= GOARCH=${GOARCH} GOOS=${OPSYS:L} \
		${SH} make.bash

post-install:
	@${CAT} ${PKGMESSAGE}

do-install:
	@${CP} -a ${WRKSRC} ${PREFIX}
.for f in go godoc gofmt
	@${LN} -sf ${PREFIX}/go/bin/${f} ${PREFIX}/bin/${f}
.endfor

regression-test: build
	cd ${WRKSRC}/src && GOROOT=${WRKSRC} PATH=${WRKSRC}/bin:${PATH} ${SH} run.bash --no-rebuild --banner

.include <bsd.port.post.mk>
