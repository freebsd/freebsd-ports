# $FreeBSD$

PORTNAME=	tinygo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	devel

# https://github.com/tinygo-org/tinygo/pull/810
PATCH_SITES=	https://github.com/dmgk/tinygo/commit/
PATCHFILES=	88c85403cc01650ca8a2b9a69ee8c68231ec0e54.patch:-p1

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Go compiler for small places

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake \
		ninja:devel/ninja
TEST_DEPENDS=	qemu-system-arm:emulators/qemu

USES=		gmake go:modules,run

USE_GITHUB=	yes
GH_ACCOUNT=	tinygo-org
GH_TUPLE=	\
		blakesmith:ar:8bd4349a67f2:blakesmith_ar/vendor/github.com/blakesmith/ar \
		creack:goselect:v0.1.0:creack_goselect/vendor/github.com/creack/goselect \
		golang:sys:b09406accb47:golang_sys/vendor/golang.org/x/sys \
		golang:tools:8dcc6e70cdef:golang_tools/vendor/golang.org/x/tools \
		google:shlex:c34317bd91bf:google_shlex/vendor/github.com/google/shlex \
		marcinbor85:gohex:7a43cd876e46:marcinbor85_gohex/vendor/github.com/marcinbor85/gohex \
		bugst:go-serial:5f7892a7bb45:bugst_go_serial/vendor/go.bug.st/serial.v1 \
		tinygo-org:go-llvm:b2db3df3f257:tinygo_go_llvm/vendor/tinygo.org/x/go-llvm

# Device files and runtime are distributed as submodules
GH_TUPLE+=	NordicSemiconductor:nrfx:3ab39a9d457b:nrfx/lib/nrfx \
		ARM-software:CMSIS:9fe411cef1ce:cmsis/lib/CMSIS \
		avr-rust:avr-mcu:6624554c02b2:avr/lib/avr \
		tinygo-org:cmsis-svd:7d9b4167010f:cmsis_svd/lib/cmsis-svd \
		llvm-mirror:compiler-rt:5bc79797e1f9:compiler_rt/lib/compiler-rt

# Bundled LLVM
GH_TUPLE+=	llvm:llvm-project:llvmorg-9.0.1:llvm/llvm-project

OPTIONS_DEFINE=	AVR QEMU

AVR_DESC=	AVR based processors support
QEMU_DESC=	Install emulators/qemu for Cortex-M targets

AVR_RUN_DEPENDS=	avr-gcc:devel/avr-gcc \
			${LOCALBASE}/avr/include/stdint.h:devel/avr-libc \
			avrdude:devel/avrdude
AVR_VARS_OFF=	AVR=0

QEMU_RUN_DEPENDS=	qemu-system-arm:emulators/qemu

do-build:
	(cd ${WRKSRC} && \
		unset CDPATH && \
		${GMAKE} llvm-build)
	(cd ${WRKSRC} && ${SETENV} \
		GO=${GO_CMD} \
		GOCACHE=${WRKDIR}/.gocache \
		PATH=${WRKSRC}/llvm-build/bin:$$PATH \
		${GMAKE} release)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/tinygo
	(cd ${WRKSRC}/build/release/tinygo && \
		${MKDIR} ${STAGEDIR}${PREFIX}/tinygo/bin && \
		${INSTALL_PROGRAM} bin/tinygo ${STAGEDIR}${PREFIX}/tinygo/bin && \
		${COPYTREE_SHARE} "lib pkg src targets" ${STAGEDIR}${PREFIX}/tinygo)
	${RLN} ${STAGEDIR}${PREFIX}/tinygo/bin/tinygo ${STAGEDIR}${PREFIX}/bin

do-test:
	(cd ${WRKSRC} && ${SETENV} \
		AVR=${AVR} \
		GOCACHE=${WRKDIR}/.gocache \
		PATH=${WRKSRC}/llvm-build/bin:$$PATH \
		RISCV=0 \
		TINYGO=${WRKSRC}/build/tinygo \
		${GMAKE} test smoketest)

.include <bsd.port.mk>
