# $FreeBSD$

PORTNAME=	xtoolchain
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none
PKGNAMEPREFIX?=	powerpc64-
PKGNAMESUFFIX?=	-gcc

MAINTAINER?=	bapt@FreeBSD.org
COMMENT=	Pre seeded toolchain to cross build FreeBSD base

NO_BUILD=	yes

.if ${PKGNAMEPREFIX} == "amd64-"
TOOLCHAIN_PREFIX=	x86_64-
.else
TOOLCHAIN_PREFIX=	${PKGNAMEPREFIX}
.endif
XCC?=		${TOOLCHAIN_PREFIX}unknown-${OPSYS:tl}${OSREL}-gcc
XCXX?=		${TOOLCHAIN_PREFIX}unknown-${OPSYS:tl}${OSREL}-g++
XCPP?=		${TOOLCHAIN_PREFIX}unknown-${OPSYS:tl}${OSREL}-cpp
X_COMPILER_TYPE?=	${PKGNAMESUFFIX:C/-//g}

RUN_DEPENDS?=	${XCC}:devel/${PKGNAMEPREFIX}${X_COMPILER_TYPE}

SUB_FILES=	xtoolchain.mk
SUB_LIST=	TARGETARCH=${TOOLCHAIN_PREFIX:C/-//g} \
		OPSYS=${OPSYS:tl} \
		XCC=${XCC} \
		XCXX=${XCXX} \
		XCPP=${XCPP} \
		X_COMPILER_TYPE=${X_COMPILER_TYPE}

PLIST_FILES=	share/toolchains/${PKGNAMEPREFIX}${X_COMPILER_TYPE}.mk

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/toolchains/
	@${INSTALL_DATA} ${WRKDIR}/xtoolchain.mk \
		${STAGEDIR}${PREFIX}/share/toolchains/${PKGNAMEPREFIX}${X_COMPILER_TYPE}.mk

.include <bsd.port.mk>
