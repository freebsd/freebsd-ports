# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	tpm-emulator
PORTVERSION=	0.7.4
CATEGORIES=	emulators security
MASTER_SITES=	SF/${PORTNAME}.berlios
DISTNAME=	${PORTNAME:S,-,_,}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Trusted Platform Module (TPM) emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libgmp.so:math/gmp

CONFLICTS=	trousers-tddl-[0-9]*

USES=		cmake:outsource
USE_RC_SUBR=	tpmd
CONFIGURE_ENV=	PREFIX="${PREFIX}"
CMAKE_ARGS=	-DTPM_INCLUDE_DIRS:STRING="${LOCALBASE}/include" \
		-DTPM_LIBRARY_DIRS:STRING="${LOCALBASE}/lib"
USE_LDCONFIG=	yes
USERS=		_tss
GROUPS=		_tss
SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}"
PLIST_SUB=	USERS="${USERS}" GROUPS="${GROUPS}"

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/tpm
	@${MKDIR} ${STAGEDIR}${PREFIX}/var/db/tpm

.include <bsd.port.mk>
