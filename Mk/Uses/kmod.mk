# $FreeBSD$
#
# Handles common items for kernel module ports.
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

.if ${KMODDIR} == "/boot/kernel"
KMODDIR=	/boot/modules
.endif
KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR="${KMODDIR:C,^/,,}"
MAKE_ENV+=	KMODDIR="${KMODDIR}" SYSDIR="${SRC_BASE}/sys"
.if !defined(NO_STAGE)
MAKE_ENV+=	NO_XREF=yes
.endif

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
.if defined(NO_STAGE)
	/usr/sbin/kldxref ${KMODDIR}
.endif
	${ECHO_CMD} "@unexec rmdir ${KMODDIR} 2>/dev/null || true" >> ${TMPPLIST}

.endif
