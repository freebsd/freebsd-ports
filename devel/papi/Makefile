PORTNAME=	papi
PORTVERSION=	7.2.0
CATEGORIES=	devel
MASTER_SITES=	https://icl.utk.edu/projects/papi/downloads/

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	API to access the performance counter hw in the microprocessor
WWW=		https://icl.utk.edu/papi/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/LICENSE.txt

TEST_TARGET=	fulltest

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	HWPMC kernel module is only available for I386 and \
			AMD64 machines
NO_PACKAGE=	Needs to be compiled for specific CPU

STRIP=		# empty
USE_LDCONFIG=	yes
BUILD_DEPENDS=	bash:shells/bash
USES=		gmake pathfix pkgconfig python:env shebangfix
PATHFIX_MAKEFILEIN=	Makefile.inc
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
WRKMAN=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/man
INSTALL_TARGET=	install-all
CONFIGURE_ARGS+=	--with-tests=no --enable-fortran=no
SHEBANG_FILES=	high-level/scripts/papi_hl_output_writer.py
#SHEBANG_FILES=	bin/papi_hl_output_writer.py

OPTIONS_DEFINE=	CORETEMP DEBUGINFO
CORETEMP_DESC=	Add Intel Core thermal sensor (need coretemp.ko)
DEBUGINFO_DESC=	Add debug information (increased verbosity)

CORETEMP_CONFIGURE_ON=	--with-components=coretemp_freebsd
DEBUGINFO_CONFIGURE_WITH=	debug

BINARY_ALIAS=	sh=bash

.include <bsd.port.options.mk>

HAS_HWPMC!=	${SYSCTL} kern.hwpmc.nsamples >/dev/null 2>&1 && ${ECHO_CMD} yes || ${ECHO_CMD}

.if ${HAS_HWPMC} != yes
IGNORE=		needs hwpmc module loaded or compiled into the kernel. \
		Please consult hwpmc(4) on how to do it (or read pkg-message)
.endif

post-patch:
	${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/ctests/omptough.c \
		${WRKSRC}/ctests/pernode.c \
		${WRKSRC}/ctests/zero_shmem.c \
		${WRKSRC}/components/appio/tests/appio_test_pthreads.c \
		${WRKSRC}/libperfnec/lib/pfmlib_sicortex.c \
		${WRKSRC}/libpfm4/lib/pfmlib_sicortex.c

.include <bsd.port.mk>
