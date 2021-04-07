PORTNAME=	cascade
PORTVERSION=	g20200105.1
CATEGORIES=	cad
PKGNAMESUFFIX=	-compiler

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Just-In-Time Compiler for Verilog from VMware Research

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	flex>0:textproc/flex
RUN_DEPENDS=	verilator:cad/verilator
TEST_DEPENDS=	benchmark>0:devel/benchmark \
		googletest>0:devel/googletest

USES=		bison cmake compiler:c++17-lang localbase:ldflags ncurses perl5
USE_GITHUB=	yes
GH_ACCOUNT=	vmware
GH_TAGNAME=	f4f7ae8bd1dd379790c0e58c286df90b8d1cdcde

MAKE_ENV=	FREEBSD_WRKSRC=${WRKSRC} FREEBSD_LOCALBASE=${LOCALBASE}

CMAKE_OFF=	BUILD_TESTING

BINARY_ALIAS=	flex=${FILESDIR}/flex flex.real=${LOCALBASE}/bin/flex bison=${LOCALBASE}/bin/bison

post-patch:
	# cascade needs the latest flex, not one from the base system
	@${FIND} ${WRKSRC} -name "*.h" | ${XARGS} ${REINPLACE_CMD} -i '' 's|#include <FlexLexer.h>|#include <${LOCALBASE}/include/flex/FlexLexer.h>|'
	# don't need bash: https://github.com/vmware/cascade/issues/207
	@${FIND} ${WRKSRC} -name "*.sh" | ${XARGS} ${REINPLACE_CMD} -i '' 's|#!/bin/bash|#!/bin/sh|'

do-test:
	cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
