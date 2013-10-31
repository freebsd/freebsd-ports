# $FreeBSD$
#
# Handles dependency on kernel sources
#
# MAINTAINER: rene@FreeBSD.org
#
# Feature:	kmod
# Usage:	USES=kmod
# Valid ARGS:	none
#
.if !defined(_INCLUDE_USES_KMOD_MK)
_INCLUDE_USES_KMOD_MK=	yes

.if defined(kmod_ARGS)
IGNORE=	USES=kmod takes no arguments
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files in ${SRC_BASE}
.endif

CATEGORIES+=	kld

SSP_UNSAFE=	kernel module does not support SSP

KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR="${KMODDIR:C,^/,,}"
MAKE_ENV+=	KMODDIR="${KMODDIR}" SYSDIR="${SRC_BASE}/sys"

pre-install: kmod-pre-install
kmod-pre-install:
.if defined(NO_STAGE)
	${MKDIR} ${KMODDIR}
.else
	${MKDIR} ${STAGEDIR}${KMODDIR}
.endif

post-install: kmod-post-install
kmod-post-install:
	${ECHO_CMD} "@exec /usr/sbin/kldxref ${KMODDIR}"  >> ${TMPPLIST}
	${ECHO_CMD} "@unexec /usr/sbin/kldxref ${KMODDIR}" >> ${TMPPLIST}
	${ECHO_CMD} "@dirrmtry ${KMODDIR}" >> ${TMPPLIST}
.if defined(NO_STAGE)
	/usr/sbin/kldxref ${KMODDIR}
.endif

.endif
