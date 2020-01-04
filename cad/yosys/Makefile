# Created by: Johnny Sorocil <jsorocil@gmail.com>
# $FreeBSD$

PORTNAME=	yosys
DISTVERSIONPREFIX=	yosys-
DISTVERSION=	0.9
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Yosys Open SYnthesis Suite

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	abc:cad/abc \
		bash:shells/bash \
		gawk:lang/gawk
LIB_DEPENDS=	libffi.so:devel/libffi

USES=		bison compiler:c++11-lang gmake pkgconfig python:3.6+ readline \
		shebangfix tcl

SHEBANG_FILES=	backends/smt2/smtbmc.py \
		misc/yosys-config.in

USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH}
MAKE_ARGS=	ABCEXTERNAL=abc

post-patch:
	${REINPLACE_CMD} -e '/^CXX =/d; s/^LD = .*/LD = $$(CXX)/' \
		-e '/^CONFIG/s/clang/${CHOSEN_COMPILER_TYPE}/' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/yosys

.include <bsd.port.mk>
