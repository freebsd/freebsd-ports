# $FreeBSD$

PORTNAME=	cascade
PORTVERSION=	g20200104
CATEGORIES=	cad
PKGNAMESUFFIX=	-compiler

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	efe9940dcb93a6db6347ffd99225d52449e27c4d.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Just-In-Time Compiler for Verilog from VMware Research

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	flex>0:textproc/flex
RUN_DEPENDS=	verilator:cad/verilator
TEST_DEPENDS=	benchmark>0:devel/benchmark \
		googletest>0:devel/googletest

USES=		bison cmake localbase:ldflags ncurses perl5
USE_GITHUB=	yes
GH_ACCOUNT=	vmware
GH_TAGNAME=	25e1050ab41c242c77014d7436998611e0b3fb82

MAKE_ENV=	FREEBSD_WRKSRC=${WRKSRC} FREEBSD_LOCALBASE=${LOCALBASE}

CMAKE_OFF=	BUILD_TESTING

BINARY_ALIAS=	flex=${FILESDIR}/flex flex.real=${LOCALBASE}/bin/flex bison=${LOCALBASE}/bin/bison

post-patch:
	# cascade needs the latest flex, not one from the base system
	@${FIND} ${WRKSRC} -name "*.h" | ${XARGS} ${REINPLACE_CMD} -i '' 's|#include <FlexLexer.h>|#include <${LOCALBASE}/include/flex/FlexLexer.h>|'
	# no need in bash: https://github.com/vmware/cascade/issues/207
	@${FIND} ${WRKSRC} -name "*.sh" | ${XARGS} ${REINPLACE_CMD} -i '' 's|#!/bin/bash|#!/bin/sh|'
	# replace with CXX C++ compiler: https://github.com/vmware/cascade/issues/208
	@${FIND} ${WRKSRC} -name "*.sh" | ${XARGS} ${REINPLACE_CMD} -i '' 's|g++ |${CXX} |'

do-test: # the below command fails, but 'run_regression' passes 100%, something minor is wrong
	cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
