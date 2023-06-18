PORTNAME=	yosys-systemverilog
DISTVERSION=	2023-06-14
CATEGORIES=	cad
PKGNAMEPREFIX=

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SystemVerilog support for Yosys
WWW=		https://github.com/antmicro/yosys-systemverilog

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		yosys>0:cad/yosys
LIB_DEPENDS=	libcapnp.so:devel/capnproto \
		libffi.so:devel/libffi \
		libsurelog.so:cad/surelog \
		libuhdm.so:cad/uhdm
RUN_DEPENDS=	yosys>0:cad/yosys

USES=		cabal gmake pkgconfig python:build readline tcl

USE_CABAL=	alex-3.3.0.0 \
		cmdargs-0.10.22 \
		githash-0.1.6.3 \
		happy-1.20.1.1 \
		hashable-1.4.2.0_1 \
		primitive-0.8.0.0 \
		th-compat-0.1.4_2 \
		vector-0.13.0.0_3 \
		vector-stream-0.1.0.0_2
SKIP_CABAL_PLIST=	yes
# in order to update USE_CABAL run 'make local-cabal-configure local-make-use-cabal'

USE_GITHUB=	yes
GH_ACCOUNT=	antmicro
GH_TAGNAME=	49069fb-${DISTVERSION}
GH_TUPLE=	chipsalliance:yosys-f4pga-plugins:56f957c:yosys_f4pga_plugins/yosys-f4pga-plugins \
		zachjs:sv2v:6c4ee8f:sv2v/sv2v \
		YosysHQ:yosys:c5e4eec:yosys/yosys

MAKE_ENV=	DESTDIR=${DESTDIR} \
		HOME=${WRKSRC}
MAKE_ARGS=	YOSYS_PATH=${LOCALBASE} -j${MAKE_JOBS_NUMBER}

BINARY_ALIAS=	python3=${PYTHON_CMD} \
		install=${FILESDIR}/install.sh

OPTIONS_DEFINE=		TCMALLOC
OPTIONS_DEFAULT=	TCMALLOC # should be the same TCMALLOC default as in cad/yosys, cad/surelog, cad/uhdm because surelog's lib is used in the yosys plugin cad/yosys-systemverilog

TCMALLOC_LDFLAGS=	`pkg-config --libs libtcmalloc`
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

PORTSCOUT=	ignore:1 # until https://github.com/antmicro/yosys-systemverilog/issues/1798 is resolved

post-extract:
	@${CP} ${WRKSRC_yosys}/passes/pmgen/pmgen.py ${WRKSRC}/yosys-f4pga-plugins

local-cabal-configure: check-cabal
	@cd ${WRKSRC}/sv2v && \
		${SETENV} ${MAKE_ENV} ${CABAL_HOME_ENV} ${CABAL_CMD} build --dry-run --disable-benchmarks --disable-tests --flags="${CABAL_FLAGS}" ${CABAL_WITH_ARGS} ${CABAL_LTO_ARGS} ${BUILD_ARGS} exe:sv2v

local-make-use-cabal: check-cabal2tuple
	@${_CABAL2TUPLE_CMD} ${CABAL2TUPLE_ARGS} ${WRKSRC}/sv2v || (${ECHO_CMD} "Did you forget to make do-cabal-configure ?" ; exit 1)

do-build:
	# UHDM plugin
	${ECHO} "==> Building the C part (yosys-f4pga-plugins)"
	@cd ${WRKSRC}/yosys-f4pga-plugins && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} ${ALL_TARGET}
	# sv2v
	${ECHO} "==> Building the Haskell part (sv2v)"
	cd ${WRKSRC}/sv2v && \
		${LN} -fs ${CABAL_DEPSDIR} && \
		${LN} -fs ../cabal.project.local && \
		${SETENV} ${MAKE_ENV} ${CABAL_HOME_ENV} ${CABAL_CMD} build --offline --disable-benchmarks --disable-tests ${CABAL_WITH_ARGS} ${CABAL_LTO_ARGS} --flags "${CABAL_FLAGS}" ${BUILD_ARGS} exe:sv2v

do-install:
	# create directories
	@${MKDIR} \
		${STAGEDIR}${PREFIX}/share/yosys/plugins/fasm_extra_modules \
		${STAGEDIR}${PREFIX}/share/yosys/quicklogic/pp3 \
		${STAGEDIR}${PREFIX}/share/yosys/quicklogic/qlf_k6n10 \
		${STAGEDIR}${PREFIX}/share/yosys/quicklogic/qlf_k6n10f \
		${STAGEDIR}${PREFIX}/share/yosys/nexus
	# UHDM plugin
	cd ${WRKSRC}/yosys-f4pga-plugins && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} ${INSTALL_TARGET}
	# sv2v
	${INSTALL_PROGRAM} \
		${WRKSRC}/sv2v/dist-newstyle/build/*-freebsd/ghc-*/sv2v-*/x/sv2v/build/sv2v/sv2v \
		${STAGEDIR}${PREFIX}/bin
	# strip binaries
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/yosys/plugins/*.so

.include <bsd.port.mk>
