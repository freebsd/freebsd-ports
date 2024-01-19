PORTNAME=	go
DISTVERSION?=	g20230808
PORTREVISION?=	0
CATEGORIES=	lang
MASTER_SITES?=	https://github.com/dmgk/go-bootstrap/releases/download/${BOOTSTRAP_TAG}/:bootstrap \
		LOCAL/dmgk:bootstrap
PKGNAMESUFFIX=	${DISTVERSION:C/^g[0-9]+/-devel/:C/^([0-9]+)\.([0-9]+).*/\1\2/}
DISTFILES?=	go-${OPSYS:tl}-${GOARCH_${ARCH}}${GOARM_${ARCH}}-${BOOTSTRAP_TAG}.tar.xz:bootstrap

MAINTAINER=	go@FreeBSD.org
COMMENT?=	Go programming language (development version)
WWW=		https://golang.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

.ifdef QEMU_EMULATING
IGNORE=		fails to build with qemu-user-static
.endif

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 riscv64

RUN_DEPENDS=	${RUN_DEPENDS_${ARCH}}
# ld.bfd from devel/binutils is needed for working cgo on aarch64
RUN_DEPENDS_aarch64=	binutils>0:devel/binutils

TEST_DEPENDS=	${TEST_DEPENDS_${ARCH}}
# ld.bfd from devel/binutils is needed for working cgo on aarch64
TEST_DEPENDS_aarch64=	binutils>0:devel/binutils

USES=		cpe shebangfix

CPE_VENDOR=	golang

.ifndef MASTERDIR
USE_GITHUB=	yes
GH_ACCOUNT=	golang
# go1.21.0
GH_TAGNAME=	c19c4c566c63818dfd059b352e52c4710eecf14d
.endif

SHEBANG_FILES=	misc/wasm/go_js_wasm_exec \
		src/net/http/cgi/testdata/test.cgi
SHEBANG_GLOB=	*.bash *.pl *.sh

# Upstream archive contains files with UTF-8 names
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 ${TAR}

OPTIONS_DEFINE_i386=	SOFTFLOAT
OPTIONS_DEFAULT_amd64=	V1
OPTIONS_SINGLE=	${OPTIONS_SINGLE_${ARCH}}
OPTIONS_SINGLE_amd64=	GOAMD64
OPTIONS_SINGLE_GOAMD64=	V1 V2 V3 V4

SOFTFLOAT_DESC=	Use soft float on non-SSE2 processors (Pentium 4 and older)
SOFTFLOAT_VARS=	GO386=softfloat
V1_DESC=	Use baseline x86-64 instruction set
V1_VARS=	GOAMD64=v1
V2_DESC=	V1 instructions plus CMPXCHG16B, LAHF, SAHF, POPCNT, SSE*
V2_VARS=	GOAMD64=v2
V3_DESC=	V2 instructions plus AVX*, BMI*, F16C, FMA, LZCNT, MOVBE, OSXSAVE
V3_VARS=	GOAMD64=v3
V4_DESC=	V3 instructions plus AVX512*
V4_VARS=	GOAMD64=v4

BOOTSTRAP_TAG=	go1.20
GO_SUFFIX=	${PKGNAMESUFFIX}

GOARCH_aarch64=	arm64
GOARCH_amd64=	amd64
GOARCH_armv6=	arm
GOARCH_armv7=	arm
GOARCH_i386=	386
GOARCH_riscv64=	riscv64
GOARM_armv6=	6
GOARM_armv7=	7

.include <bsd.port.pre.mk>

post-extract:
	@[ -z "${GH_TAGNAME}" ] || \
		${ECHO_CMD} "devel ${DISTVERSION}-${GH_TAGNAME} ${OPSYS:tl}/${GOARCH_${ARCH}}" > ${WRKSRC}/VERSION

post-patch:
	@${REINPLACE_CMD} -e 's|type -ap |type |' ${WRKSRC}/src/make.bash
	@${REINPLACE_CMD} -e 's|^if ulimit -T|false \&\& &|' ${WRKSRC}/src/run.bash

.if ${ARCH} != riscv64
pre-build:
	# Check that the running kernel has COMPAT_FREEBSD11 required by lang/go{,-devel} post-ino64
	@${SETENV} CC="${CC}" OPSYS="${OPSYS}" OSVERSION="${OSVERSION}" WRKDIR="${WRKDIR}" \
		${SH} ${SCRIPTSDIR}/rust-compat11-canary.sh
.endif

do-build:
	cd ${WRKSRC}/src ; ${SETENV} \
		XDG_CACHE_HOME=${WRKDIR} \
		GOROOT_BOOTSTRAP=${WRKDIR}/go-${OPSYS:tl}-${GOARCH_${ARCH}}${GOARM_${ARCH}}-bootstrap \
		GOROOT=${WRKSRC} \
		GOROOT_FINAL=${PREFIX}/go${GO_SUFFIX} \
		GOBIN= \
		GOOS=${OPSYS:tl} \
		GOARCH=${GOARCH_${ARCH}} \
		GO386=${GO386} \
		GOARM=${GOARM_${ARCH}} \
		GOAMD64=${GOAMD64} \
		CC=${CC} \
		${SH} make.bash -v

do-install:
	@cd ${WRKSRC} ; \
		${RM} -r .gitattributes .gitignore .github favicon.ico robots.txt \
		pkg/obj pkg/bootstrap pkg/${OPSYS:tl}_${GOARCH_${ARCH}}/cmd
	@${MKDIR} ${STAGEDIR}${PREFIX}/go${GO_SUFFIX}
	@${CP} -a ${WRKSRC}/* ${STAGEDIR}${PREFIX}/go${GO_SUFFIX}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/go${GO_SUFFIX}/bin/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/go${GO_SUFFIX}/pkg/tool/${OPSYS:tl}_${GOARCH_${ARCH}}/*
.for f in go gofmt
	${LN} -sf ../go${GO_SUFFIX}/bin/${f} ${STAGEDIR}${PREFIX}/bin/${f}${GO_SUFFIX}
	@${ECHO_CMD} bin/${f}${GO_SUFFIX} >> ${TMPPLIST}
.endfor
	@cd ${STAGEDIR}${PREFIX} && ${FIND} go${GO_SUFFIX} -type f >> ${TMPPLIST}

do-test:
	cd ${WRKSRC}/src && ${SETENV} \
		GOROOT=${WRKSRC} \
		PATH=${WRKSRC}/bin:${PATH} \
		GOOS=${OPSYS:tl} \
		GOARCH=${GOARCH_${ARCH}} \
		GO386=${GO386} \
		GOARM=${GOARM_${ARCH}} \
		GOAMD64=${GOAMD64} \
		CC=${CC} \
		${SH} run.bash -no-rebuild

.if !defined(_GO_MAKESUM_GUARD)
makesum:
	${MAKE} -D_GO_MAKESUM_GUARD makesum ARCH=${ONLY_FOR_ARCHS:O:[1]} DISTINFO_FILE=${DISTINFO_FILE}.tmp
.for arch in ${ONLY_FOR_ARCHS:O:[2..-1]}
	${MAKE} -D_GO_MAKESUM_GUARD makesum ARCH=${arch} DISTINFO_FILE=${DISTINFO_FILE}.${arch}
	${SED} 1d ${DISTINFO_FILE}.${arch} >> ${DISTINFO_FILE}.tmp
	${RM} ${DISTINFO_FILE}.${arch}
.endfor
	${AWK} '!seen[$$0]++' ${DISTINFO_FILE}.tmp > ${DISTINFO_FILE}
	${RM} ${DISTINFO_FILE}.tmp
.endif

.include <bsd.port.post.mk>
