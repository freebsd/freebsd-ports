PORTNAME=	verilator
DISTVERSION=	4.202
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	https://www.veripool.org/ftp/

PATCH_SITES=	https://github.com/verilator/verilator/commit/
PATCHFILES=	0f7ec6c9ba52160573df8a7ee90bcc38c837eee7.patch:-p1 # fix for missing #include <array>

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Synthesizable Verilog to C++ compiler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsystemc.so:devel/systemc
RUN_DEPENDS=	gmake:devel/gmake # verilator runs gmake for the --hierarchical option when the 'gmake' method is chosen

USES=		bison compiler:c++14-lang gmake localbase:ldflags pathfix perl5 python:build,test tar:tgz

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_SCRIPT}"

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

post-build:
	@${STRIP_CMD} ${WRKSRC}/bin/verilator_bin

post-install-INSTALL_DBG_EXECUTABLES-off:
	@${RM} ${STAGEDIR}${PREFIX}/bin/verilator_bin_dbg ${STAGEDIR}${PREFIX}/bin/verilator_coverage_bin_dbg

.include <bsd.port.mk>
