# $FreeBSD$

PORTNAME=	verilator
DISTVERSION=	4.040
CATEGORIES=	cad
MASTER_SITES=	https://www.veripool.org/ftp/

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES+=	39f16fb155b9e909f919a9d4ae06890395987b16.patch:-p1 # https://github.com/verilator/verilator/pull/2353

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Synthesizable Verilog to C++ compiler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison compiler:c++14-lang gmake pathfix perl5 python:test tar:tgz

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_SCRIPT}"

TEST_TARGET=	test

BINARY_ALIAS=	make=${GMAKE} python3=${PYTHON_CMD} # aliasas are only for tests

post-patch:
	${REINPLACE_CMD} -e 's|@pkgconfigdir@|${PREFIX}/libdata/pkgconfig|' \
	    ${WRKSRC}/Makefile.in

post-build:
	@${STRIP_CMD} ${WRKSRC}/bin/verilator_bin

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/verilator_bin_dbg ${STAGEDIR}${PREFIX}/bin/verilator_coverage_bin_dbg

.include <bsd.port.mk>
