# $FreeBSD$
#
# Handles common items for kernel module ports.
#
# Feature:	kmod
# Usage:	USES=kmod
# Valid ARGS:	none
#
# MAINTAINER: rene@FreeBSD.org

.if !defined(_INCLUDE_USES_KMOD_MK)
_INCLUDE_USES_KMOD_MK=	yes

_USES_POST=	kmod

.if defined(kmod_ARGS)
IGNORE=	USES=kmod takes no arguments
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files in ${SRC_BASE}
.endif

CATEGORIES+=	kld

SSP_UNSAFE=	kernel module supports SSP natively

KMODDIR?=	/boot/modules
.if ${KMODDIR} == /boot/kernel
KMODDIR=	/boot/modules
.endif
PLIST_SUB+=	KMODDIR="${KMODDIR:C,^/,,}"
MAKE_ENV+=	KMODDIR="${KMODDIR}" SYSDIR="${SRC_BASE}/sys" NO_XREF=yes

.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_KMOD_POST_MK)
_INCLUDE_USES_KMOD_POST_MK=	yes

pre-install: ${STAGEDIR}${KMODDIR}
${STAGEDIR}${KMODDIR}:
	@${MKDIR} ${.TARGET}

kmod-post-install:
	@${ECHO_CMD} "@exec /usr/sbin/kldxref ${KMODDIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec /usr/sbin/kldxref ${KMODDIR}" >> ${TMPPLIST}
.if ${KMODDIR} != /boot/modules
	@${ECHO_CMD} "@unexec rmdir -p ${KMODDIR} 2>/dev/null || true" \
		>> ${TMPPLIST}
.endif

.endif
