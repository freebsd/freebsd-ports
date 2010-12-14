# New ports collection makefile for:	tpm-emulator
# Date created:				18 Sep 2007
# Whom:					Sebastian Schuetz <sschuetz@fhm.edu>
#
# $FreeBSD$
#

PORTNAME=		tpm-emulator
PORTVERSION=		0.7.1
CATEGORIES=		emulators security
MASTER_SITES=		BERLIOS/${PORTNAME}
DISTNAME=		${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=		nork@freebsd.org
COMMENT=		Trusted Platform Module (TPM) emulator

LIB_DEPENDS=		gmp.10:${PORTSDIR}/math/gmp

USE_CMAKE=		YES
USE_RC_SUBR=		tpmd
USE_LDCONFIG=		YES
MAKE_JOBS_SAFE=		YES

CONFLICTS=		trousers-tddl-[0-9d]*

WANTLIB=		c
CMAKE_VERBOSE=		YES
CMAKE_SOURCE_PATH=	${WRKSRC}
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}
CONFIGURE_WRKSRC=	${CMAKE_SOURCE_PATH}/build

CMAKE_ENV=		PREFIX=${PREFIX} ${CONFIGURE_ENV}
CMAKE_ARGS=		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
			-DCMAKE_EXE_LINKER_FLAGS="-L${LOCALBASE}/lib"

SUB_LIST=		USERS=${USERS} GROUPS=${GROUPS}

USERS=			_tss
GROUPS=			_tss

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/README

WRKSRC=			${WRKDIR}/${DISTNAME}

post-extract:
	@${MKDIR} ${WRKSRC}/build

.include <bsd.port.mk>
