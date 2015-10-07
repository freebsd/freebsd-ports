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

_USES_POST+=	kmod

.if !empty(kmod_ARGS)
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
PLIST_FILES+=	"@kld ${KMODDIR}"

STRIP_CMD+=	--strip-debug # do not strip kernel symbols
.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_KMOD_POST_MK)
_INCLUDE_USES_KMOD_POST_MK=	yes

_USES_install+=	290:${STAGEDIR}${KMODDIR}
${STAGEDIR}${KMODDIR}:
	@${MKDIR} ${.TARGET}

.endif
