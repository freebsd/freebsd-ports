# New ports collection makefile for:	tpm-emulator
# Date created:				18 Sep 2007
# Whom:					Sebastian Schuetz <sschuetz@fhm.edu>
#
# $FreeBSD$
#

PORTNAME=		tpm-emulator
PORTVERSION=		0.7.1
PORTREVISION=		1
CATEGORIES=		emulators security
MASTER_SITES=		BERLIOS/${PORTNAME}
DISTNAME=		${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
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
CMAKE_ARGS=		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include"
LDFLAGS+=		-L${LOCALBASE}/lib

SUB_LIST=		USERS=${USERS} GROUPS=${GROUPS}

USERS=			_tss
GROUPS=			_tss

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/README

WRKSRC=			${WRKDIR}/${DISTNAME}

post-extract:
	@${MKDIR} ${WRKSRC}/build

post-install:
	@${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 ${PREFIX}/var/lib/tpm
	@${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700          /var/run/tpm

add-plist-post:
	@${ECHO_CMD} "@cwd /"								>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} var/run/tpm 2>/dev/null || true"			>> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 var/run/tpm"	>> ${TMPPLIST}

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
