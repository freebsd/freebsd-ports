# $FreeBSD$

PORTNAME=	verilator
DISTVERSION=	4.040
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	https://www.veripool.org/ftp/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Synthesizable Verilog to C++ compiler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsystemc.so:devel/systemc

USES=		bison compiler:c++14-lang gmake localbase:ldflags pathfix perl5 python:build,test tar:tgz

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
