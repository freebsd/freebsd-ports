PORTNAME=	verilator
DISTVERSIONPREFIX=	v
DISTVERSION=	5.038
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Synthesizable Verilog to C++ compiler
WWW=		https://www.veripool.org/verilator/ \
		https://github.com/verilator/verilator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	see https://github.com/verilator/verilator/issues/3037

BUILD_DEPENDS=	autoconf>0:devel/autoconf \
		bash:shells/bash \
		${LOCALBASE}/bin/ar:devel/binutils \
		help2man:misc/help2man
LIB_DEPENDS=	libsystemc.so:devel/systemc # systemc is only added to share/verilator/include/verilated.mk for use during verilation, verilator's own binaries aren't linked with systemc
RUN_DEPENDS=	${LOCALBASE}/bin/ar:devel/binutils \
		gmake:devel/gmake # verilator runs gmake for the --hierarchical option when the 'gmake' method is chosen

USES=		bison compiler:c++17-lang gmake localbase:ldflags perl5 python:build,run,test shebangfix tar:tgz
USE_CXXSTD=	c++17 # needs to match that of devel/systemc to avoid mismatches like https://github.com/verilator/verilator/issues/4499
USE_GITHUB=	yes

SHEBANG_FILES=	bin/verilator_ccache_report \
		bin/verilator_difftree \
		bin/verilator_gantt \
		bin/verilator_includer \
		bin/verilator_includer \
		bin/verilator_profcfunc

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_SCRIPT}"
CONFIGURE_ARGS=	AR=${LOCALBASE}/bin/ar \
		PYTHON3=${PYTHON_CMD}
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash # see https://github.com/verilator/verilator/issues/3132

TEST_TARGET=	test

BINARY_ALIAS=	make=${GMAKE} \
		python3=${PYTHON_CMD} \
		git=false

MAKE_JOBS_UNSAFE=	yes # build on 1 CPU because many compile jobs are over 10GB and they can likely cause out-of-memory issues

OPTIONS_DEFINE=			INSTALL_DBG_EXECUTABLES LEAK_CHECKS
OPTIONS_SUB=			yes

INSTALL_DBG_EXECUTABLES_DESC=	Install *_dbg executables

LEAK_CHECKS_DESC=		Disable intentional memory leaks
LEAK_CHECKS_CXXFLAGS=		-DVL_LEAK_CHECKS
LEAK_CHECKS_BROKEN=		compilation will be fixed in the next release

post-patch:
	@${REINPLACE_CMD} -e 's|@pkgconfigdir@|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

pre-configure:
	cd ${WRKSRC} && \
		autoconf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/verilator_bin

post-install-INSTALL_DBG_EXECUTABLES-on:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/share/verilator/bin/verilator_bin_dbg \
		${STAGEDIR}${PREFIX}/share/verilator/bin/verilator_coverage_bin_dbg

post-install-INSTALL_DBG_EXECUTABLES-off:
	@${RM} \
		${STAGEDIR}${PREFIX}/bin/verilator_bin_dbg \
		${STAGEDIR}${PREFIX}/bin/verilator_coverage_bin_dbg \
		${STAGEDIR}${PREFIX}/share/verilator/bin/verilator_bin_dbg \
		${STAGEDIR}${PREFIX}/share/verilator/bin/verilator_coverage_bin_dbg

.include <bsd.port.mk>
