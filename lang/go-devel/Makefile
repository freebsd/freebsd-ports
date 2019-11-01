# Created by: Devon H. O'Dell <devon.odell@gmail.com>
# $FreeBSD$

PORTNAME=	go
PORTVERSION=	g20191031
CATEGORIES=	lang
PKGNAMESUFFIX=	-devel

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Go programming language (development version)

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

BUILD_DEPENDS=	go14>=1.4:lang/go14

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_TAGNAME=	3f995c3f3b

SHEBANG_FILES=	misc/benchcmp \
		misc/nacl/go_nacl_*_exec \
		misc/wasm/go_js_wasm_exec \
		src/net/http/cgi/testdata/test.cgi
SHEBANG_GLOB=	*.bash *.pl *.sh
SHEBANG_LANG=	sh
sh_OLD_CMD=	/bin/bash "/usr/bin/env bash"
sh_CMD=		${SH}

CONFLICTS_INSTALL=	go

OPTIONS_DEFINE_i386=	GO387
GO387_DESC=	Do not generate code with SSE2 (for old x86 CPU)

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
GOARCH=386
.elif ${ARCH} == "amd64"
GOARCH=amd64
.elif ${ARCH} == armv6 || ${ARCH} == armv7
GOARCH=arm
.else
IGNORE=		unknown arch ${ARCH}
.endif

.if ${PORT_OPTIONS:MGO387}
GO386=387
.endif

BINARIES=	go gofmt

post-patch:
	@cd ${WRKSRC} && ${FIND} . -name '*.orig' -delete
	@${REINPLACE_CMD} -e 's|^if ulimit -T|false \&\& &|' ${WRKSRC}/src/run.bash

do-build:
	cd ${WRKSRC}/src && \
		GOROOT=${WRKSRC} GOROOT_FINAL=${PREFIX}/go \
		GOROOT_BOOTSTRAP=${LOCALBASE}/go14 \
		GOBIN= GOARCH=${GOARCH} GOOS=${OPSYS:tl} \
		GO386=${GO386} \
		${SH} make.bash -v
	${RM} -r ${WRKSRC}/pkg/obj \
	    ${WRKSRC}/pkg/bootstrap \
	    ${WRKSRC}/pkg/${OPSYS:tl}_${GOARCH}/cmd

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/go
	@${CP} -a ${WRKSRC}/* ${STAGEDIR}${PREFIX}/go
.for f in ${BINARIES}
	@${LN} -sf ../go/bin/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install:
.for f in ${BINARIES}
	@${ECHO_CMD} bin/${f} >> ${TMPPLIST}
.endfor
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} go -type f >> ${TMPPLIST}

do-test:
	cd ${WRKSRC}/src && \
		GOROOT=${WRKSRC} PATH=${WRKSRC}/bin:${PATH} \
		${SH} run.bash -no-rebuild -banner ""

.include <bsd.port.post.mk>
