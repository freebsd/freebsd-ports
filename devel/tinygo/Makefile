PORTNAME=	tinygo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.42.0
CATEGORIES=	devel

MAINTAINER=	gareev@aydar.me
COMMENT=	Go compiler for small places
WWW=		https://tinygo.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	wasm-opt:devel/binaryen
TEST_DEPENDS=	qemu-system-arm:emulators/qemu

USES=		cmake:indirect gmake go:modules,run ninja:build python:build

USE_GITHUB=	yes
GH_ACCOUNT=	tinygo-org
GH_TUPLE=	BurntSushi:toml:v1.4.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		aykevl:go-wasm:42b86c494139:aykevl_go_wasm/vendor/github.com/aykevl/go-wasm \
		blakesmith:ar:8bd4349a67f2:blakesmith_ar/vendor/github.com/blakesmith/ar \
		bugst:go-serial:v1.8.0:bugst_go_serial/vendor/go.bug.st/serial \
		chavacava:garif:v0.1.0:chavacava_garif/vendor/github.com/chavacava/garif \
		coreos:go-semver:v0.3.1:coreos_go_semver/vendor/github.com/coreos/go-semver \
		docker-archive-public:docker.libtrust:aabc10ec26b7:docker_libtrust/vendor/github.com/docker/libtrust \
		fatih:color:v1.17.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structtag:v1.2.0:fatih_structtag/vendor/github.com/fatih/structtag \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:flock:v0.8.1:gofrs_flock/vendor/github.com/gofrs/flock \
		golang:mod:v0.37.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.56.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.47.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.38.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.47.0:golang_tools/vendor/golang.org/x/tools \
		golangci:misspell:v0.6.0:golangci_misspell/vendor/github.com/golangci/misspell \
		google:shlex:c34317bd91bf:google_shlex/vendor/github.com/google/shlex \
		hashicorp:go-version:v1.7.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		inhies:go-bytesize:4913239db9cf:inhies_go_bytesize/vendor/github.com/inhies/go-bytesize \
		klauspost:compress:v1.17.11:klauspost_compress/vendor/github.com/klauspost/compress \
		marcinbor85:gohex:343a4b548892:marcinbor85_gohex/vendor/github.com/marcinbor85/gohex \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-tty:v0.0.4:mattn_go_tty/vendor/github.com/mattn/go-tty \
		mgechev:dots:e955255bf517:mgechev_dots/vendor/github.com/mgechev/dots \
		mgechev:revive:v1.3.9:mgechev_revive/vendor/github.com/mgechev/revive \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		regclient:regclient:v0.8.2:regclient_regclient/vendor/github.com/regclient/regclient \
		sigurn:crc16:20ab5afb07e3:sigurn_crc16/vendor/github.com/sigurn/crc16 \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		tetratelabs:wazero:v1.9.0:tetratelabs_wazero/vendor/github.com/tetratelabs/wazero \
		tinygo-org:espflasher:v0.8.1:tinygo_org_espflasher/vendor/tinygo.org/x/espflasher \
		tinygo-org:go-llvm:185673ef46a5:tinygo_org_go_llvm/vendor/tinygo.org/x/go-llvm \
		ulikunitz:xz:v0.5.12:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		urfave:cli:v3.0.0-beta1:urfave_cli_v3/vendor/github.com/urfave/cli/v3

# go.bytecodealliance.org and go.bytecodealliance.org/cm are separate modules
# living in the same repository under different tags.  The root tag ships its
# own cm/ directory, so cm/v0.2.2 is extracted aside and put in place by
# post-extract below.
GH_TUPLE+=	bytecodealliance:go-modules:v0.6.2:bytecodealliance_go_modules/vendor/go.bytecodealliance.org \
		bytecodealliance:go-modules:cm/v0.2.2:bytecodealliance_cm/cm-v0.2.2

# Device files, runtime libraries and the network stack are distributed as
# submodules
GH_TUPLE+=	ARM-software:CMSIS_4:9fe411cef1ce:cmsis/lib/CMSIS \
		NordicSemiconductor:nrfx:d779b49fc59c:nrfx/lib/nrfx \
		WebAssembly:WASI:59cbe140561d:wasi/lib/wasi-libc/tools/wasi-headers/WASI \
		WebAssembly:wasi-cli:6ae82617096e:wasi_cli/lib/wasi-cli \
		WebAssembly:wasi-libc:1dfe5c302d1c:wasi_libc/lib/wasi-libc \
		avr-rust:avr-mcu:6624554c02b2:avr/lib/avr \
		aykevl:macos-minimal-sdk:5f57dee4ae50:macos_minimal_sdk/lib/macos-minimal-sdk \
		cmsis-svd:cmsis-svd-data:05a9562ec59b:cmsis_svd/lib/cmsis-svd \
		ivmai:bdwgc:7577ca7c2dc7:bdwgc/lib/bdwgc \
		mingw-w64:mingw-w64:8526cb618269:mingw_w64/lib/mingw-w64 \
		picolibc:picolibc:b92edfda8ac6:picolibc/lib/picolibc \
		stm32-rs:stm32-rs:745ed5103c63:stm32_rs/lib/stm32-svd/stm32-rs \
		tinygo-org:musl-libc:7a43f6fea908:musl/lib/musl \
		tinygo-org:net:70037cf71f1a:tinygo_net/src/net \
		tinygo-org:py32-svd:6aa7396c1d4d:py32_svd/lib/py32-svd \
		tinygo-org:stm32-svd:bfed180b6398:stm32_svd/lib/stm32-svd

# Bundled LLVM: upstream pins a fork carrying the Xtensa backend and other
# patches, see llvm-version.txt
GH_TUPLE+=	tinygo-org:llvm-project:2be7242b6a4d:llvm/llvm-project

# wasm-opt comes from devel/binaryen instead of the bundled copy
MAKE_ENV=	USE_SYSTEM_BINARYEN=1

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

# GH_TUPLE populates vendor/, but does not generate vendor/modules.txt
post-extract:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor
	@${RM} -r ${WRKSRC}/vendor/go.bytecodealliance.org/cm
	@${MV} ${WRKSRC}/cm-v0.2.2/cm ${WRKSRC}/vendor/go.bytecodealliance.org/cm
	@${RM} -r ${WRKSRC}/cm-v0.2.2

# tinygo resolves GOROOT by running the go command from PATH, which the
# package does not provide - point it at the versioned one instead
post-patch:
	@${REINPLACE_CMD} -e 's|exec.Command("go"|exec.Command("${GO_CMD}"|' \
		${WRKSRC}/goenv/goenv.go

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
	cd ${WRKSRC}/build/release/tinygo && \
		${MKDIR} ${STAGEDIR}${PREFIX}/tinygo/bin && \
		${INSTALL_PROGRAM} bin/tinygo ${STAGEDIR}${PREFIX}/tinygo/bin && \
		${COPYTREE_SHARE} "lib src targets" ${STAGEDIR}${PREFIX}/tinygo
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
