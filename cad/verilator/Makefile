PORTNAME=	verilator
DISTVERSIONPREFIX=	v
DISTVERSION=	4.220
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Synthesizable Verilog to C++ compiler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	see https://github.com/verilator/verilator/issues/3037

BUILD_DEPENDS=	autoconf>0:devel/autoconf \
		bash:shells/bash \
		${LOCALBASE}/bin/ar:devel/binutils
LIB_DEPENDS=	libsystemc.so:devel/systemc
RUN_DEPENDS=	gmake:devel/gmake # verilator runs gmake for the --hierarchical option when the 'gmake' method is chosen

USES=		bison compiler:c++14-lang gmake localbase:ldflags pathfix perl5 python:build,run,test shebangfix tar:tgz
USE_GITHUB=	yes

SHEBANG_FILES=	bin/verilator_ccache_report bin/verilator_profcfunc bin/verilator_gantt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_SCRIPT}"
CONFIGURE_ARGS=	AR=${LOCALBASE}/bin/ar
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash # see https://github.com/verilator/verilator/issues/3132

TEST_TARGET=	test

BINARY_ALIAS=	make=${GMAKE} python3=${PYTHON_CMD} # aliasas are only for tests

OPTIONS_DEFINE=			INSTALL_DBG_EXECUTABLES LEAK_CHECKS
OPTIONS_SUB=			yes

INSTALL_DBG_EXECUTABLES_DESC=	Install *_dbg executables

LEAK_CHECKS_DESC=		Disable intentional memory leaks
LEAK_CHECKS_CXXFLAGS=		-DVL_LEAK_CHECKS
LEAK_CHECKS_BROKEN=		compilation will be fixed in the next release

post-patch:
	${REINPLACE_CMD} -e 's|@pkgconfigdir@|${PREFIX}/libdata/pkgconfig|' \
	    ${WRKSRC}/Makefile.in

pre-configure:
	cd ${WRKSRC} && \
		autoconf

post-build:
	@${STRIP_CMD} ${WRKSRC}/bin/verilator_bin

post-install-INSTALL_DBG_EXECUTABLES-off:
	@${RM} ${STAGEDIR}${PREFIX}/bin/verilator_bin_dbg ${STAGEDIR}${PREFIX}/bin/verilator_coverage_bin_dbg

.include <bsd.port.mk>
