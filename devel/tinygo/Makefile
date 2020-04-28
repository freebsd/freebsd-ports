# $FreeBSD$

PORTNAME=	tinygo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.1
CATEGORIES=	devel

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
GH_TUPLE=	blakesmith:ar:8bd4349a67f2:blakesmith_ar/vendor/github.com/blakesmith/ar \
		bugst:go-serial:v1.0.0:bugst_go_serial/vendor/go.bug.st/serial \
		creack:goselect:v0.1.1:creack_goselect/vendor/github.com/creack/goselect \
		golang:sys:6d18c012aee9:golang_sys/vendor/golang.org/x/sys \
		golang:tools:b320d3a0f5a2:golang_tools/vendor/golang.org/x/tools \
		google:shlex:c34317bd91bf:google_shlex/vendor/github.com/google/shlex \
		marcinbor85:gohex:7a43cd876e46:marcinbor85_gohex/vendor/github.com/marcinbor85/gohex \
		tinygo-org:go-llvm:8d120882fc7a:tinygo_org_go_llvm/vendor/tinygo.org/x/go-llvm

# Device files and runtime are distributed as submodules
GH_TUPLE+=	ARM-software:CMSIS:9fe411cef1ce:cmsis/lib/CMSIS \
		CraneStation:wasi-libc:a280fead2ae7:wasi_libc/lib/wasi-libc \
		NordicSemiconductor:nrfx:3ab39a9d457b:nrfx/lib/nrfx \
		avr-rust:avr-mcu:6624554c02b2:avr/lib/avr \
		keith-packard:picolibc:80528c684b10:picolibc/lib/picolibc \
		llvm-mirror:compiler-rt:5bc79797e1f9:compiler_rt/lib/compiler-rt \
		tinygo-org:cmsis-svd:15b462f152af:cmsis_svd/lib/cmsis-svd

# Bundled LLVM
GH_TUPLE+=	llvm:llvm-project:llvmorg-10.0.0:llvm/llvm-project

OPTIONS_DEFINE=	AVR QEMU SIMAVR

AVR_DESC=	AVR based processors support
QEMU_DESC=	Install emulators/qemu for Cortex-M targets
SIMAVR_DESC=	Install devel/simavr for AVR targets

AVR_RUN_DEPENDS=	${LOCALBASE}/avr/include/stdint.h:devel/avr-libc \
			avr-gcc:devel/avr-gcc \
			avrdude:devel/avrdude
AVR_VARS_OFF=		AVR=0

QEMU_RUN_DEPENDS=	qemu-system-arm:emulators/qemu
SIMAVR_RUN_DEPENDS=	simavr:devel/simavr

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		HOME=${WRKDIR} \
		${GMAKE} llvm-build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		GO=${GO_CMD} \
		HOME=${WRKDIR} \
		PATH=${WRKSRC}/llvm-build/bin:$$PATH \
		${GMAKE} release

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/tinygo
	cd ${WRKSRC}/build/release/tinygo && \
		${MKDIR} ${STAGEDIR}${PREFIX}/tinygo/bin && \
		${INSTALL_PROGRAM} bin/tinygo ${STAGEDIR}${PREFIX}/tinygo/bin && \
		${COPYTREE_SHARE} "lib pkg src targets" ${STAGEDIR}${PREFIX}/tinygo
	${RLN} ${STAGEDIR}${PREFIX}/tinygo/bin/tinygo ${STAGEDIR}${PREFIX}/bin

do-test:
	cd ${WRKSRC} && ${SETENV} \
		AVR=${AVR} \
		GOCACHE=${WRKDIR}/.gocache \
		PATH=${WRKSRC}/llvm-build/bin:$$PATH \
		RISCV=0 \
		TINYGO=${WRKSRC}/build/tinygo \
		${GMAKE} test smoketest

.include <bsd.port.mk>
