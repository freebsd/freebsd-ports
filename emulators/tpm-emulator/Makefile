# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	tpm-emulator
PORTVERSION=	0.7.4
CATEGORIES=	emulators security
#MASTER_SITES=	BERLIOS
MASTER_SITES=	SF/${PORTNAME}.berlios
DISTNAME=	${PORTNAME:S,-,_,}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Trusted Platform Module (TPM) emulator

LICENSE=	GPLv2

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

CONFLICTS=	trousers-tddl-[0-9]*

USES=		cmake:outsource
USE_RC_SUBR=	tpmd
CMAKE_ENV=	PREFIX="${PREFIX}"
CMAKE_ARGS=	-DTPM_INCLUDE_DIRS:STRING="${LOCALBASE}/include" \
		-DTPM_LIBRARY_DIRS:STRING="${LOCALBASE}/lib"
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
USERS=		_tss
GROUPS=		_tss
SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

post-install:
	@${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 ${PREFIX}/var/db/tpm
	@${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700          /var/run/tpm

add-plist-post:
	@(${ECHO_CMD} "@cwd /"; \
	  ${ECHO_CMD} "@unexec ${RMDIR} var/run/tpm 2>/dev/null || true"; \
	  ${ECHO_CMD} "@exec ${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 var/run/tpm"; \
	 ) >> ${TMPPLIST}

.include <bsd.port.post.mk>
