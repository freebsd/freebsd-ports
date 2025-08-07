PORTNAME=	tinygo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.0
PORTREVISION=	28
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Go compiler for small places
WWW=		https://tinygo.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	qemu-system-arm:emulators/qemu

USES=		cmake:indirect gmake go:modules,run ninja:build python:build

USE_GITHUB=	yes
GH_ACCOUNT=	tinygo-org
GH_TUPLE=	\
		blakesmith:ar:8bd4349a67f2:blakesmith_ar/vendor/github.com/blakesmith/ar \
		bugst:go-serial:v1.1.2:bugst_go_serial/vendor/go.bug.st/serial \
		chromedp:cdproto:dabd2f2e7693:chromedp_cdproto/vendor/github.com/chromedp/cdproto \
		chromedp:chromedp:v0.6.4:chromedp_chromedp/vendor/github.com/chromedp/chromedp \
		chromedp:sysutil:v1.0.0:chromedp_sysutil/vendor/github.com/chromedp/sysutil \
		creack:goselect:v0.1.1:creack_goselect/vendor/github.com/creack/goselect \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		gobwas:httphead:v0.1.0:gobwas_httphead/vendor/github.com/gobwas/httphead \
		gobwas:pool:v0.2.1:gobwas_pool/vendor/github.com/gobwas/pool \
		gobwas:ws:v1.0.4:gobwas_ws/vendor/github.com/gobwas/ws \
		golang:sys:4bcb84eeeb78:golang_sys/vendor/golang.org/x/sys \
		golang:tools:b320d3a0f5a2:golang_tools/vendor/golang.org/x/tools \
		google:shlex:c34317bd91bf:google_shlex/vendor/github.com/google/shlex \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		mailru:easyjson:v0.7.6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		marcinbor85:gohex:343a4b548892:marcinbor85_gohex/vendor/github.com/marcinbor85/gohex \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		tinygo-org:go-llvm:e7b85195e81c:tinygo_org_go_llvm/vendor/tinygo.org/x/go-llvm

# Device files and runtime are distributed as submodules
GH_TUPLE+=	ARM-software:CMSIS:9fe411cef1ce:cmsis/lib/CMSIS \
		NordicSemiconductor:nrfx:b5399066bd7f:nrfx/lib/nrfx \
		WebAssembly:wasi-libc:c7465d22096f:wasi_libc/lib/wasi-libc \
		avr-rust:avr-mcu:40d15c1c56c3:avr/lib/avr \
		llvm-mirror:compiler-rt:df52202e77b1:compiler_rt/lib/compiler-rt \
		picolibc:picolibc:3bf0a107362b:picolibc/lib/picolibc \
		tinygo-org:cmsis-svd:9c35b6d9df1f:cmsis_svd/lib/cmsis-svd \
		tinygo-org:stm32-svd:3a0b0829b70b:stm32_svd/lib/stm32-svd

# Bundled LLVM
GH_TUPLE+=	llvm:llvm-project:llvmorg-11.1.0:llvm/llvm-project

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
		${GMAKE} build/release

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
