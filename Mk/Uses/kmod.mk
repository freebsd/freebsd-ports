# $FreeBSD$
#
# Handles common items for kernel module ports.
#
# Feature:	kmod
# Usage:	USES=kmod
# Valid ARGS:	(none) debug
#
# MAINTAINER: rene@FreeBSD.org

.if !defined(_INCLUDE_USES_KMOD_MK)
_INCLUDE_USES_KMOD_MK=	yes

_USES_POST+=	kmod

.if empty(kmod_ARGS)
_DEBUG_KMOD=
.elif ${kmod_ARGS} == "debug"
_DEBUG_KMOD=	yes
.else
IGNORE=	USES=kmod takes either no arguments or 'debug'
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files in SRC_BASE=${SRC_BASE}
.endif

CATEGORIES+=	kld

SSP_UNSAFE=	kernel module supports SSP natively

KMODDIR?=	/boot/modules
.if ${KMODDIR} == /boot/kernel
KMODDIR=	/boot/modules
.endif

_DEBUG_KMOD_SH= \
${ECHO_CMD} -n "\"@dir /%%KERN_DEBUGDIR%%/%%KMODDIR%%\"" ; \
skd=`${ECHO_CMD} ${KMODDIR} | ${SED} "s,/, ,g"` ; \
l=`${ECHO_CMD} $$skd | wc -w` ; \
while [ $$l -gt 0 ] ; do \
	c=0 ; \
	r="" ; \
	for p in $$skd ; do \
		c=$$(($$c+1)) ; \
		if [ $$c -eq $$l ] ; then \
			break ; \
		fi ; \
		r="$$r/$$p" ; \
	done ; \
	${ECHO_CMD} -n " \"@dir /%%KERN_DEBUGDIR%%$$r\"" ; \
	l=$$(($$l-1)) ; \
done

PLIST_SUB+=	KMODDIR="${KMODDIR:C,^/,,}"
MAKE_ENV+=	KMODDIR="${KMODDIR}" SYSDIR="${SRC_BASE}/sys" NO_XREF=yes
PLIST_FILES+=	"@kld ${KMODDIR}"

STRIP_CMD+=	--strip-debug # do not strip kernel symbols
.if !empty(_DEBUG_KMOD)
KERN_DEBUGDIR?=	${DEBUGDIR}
PLIST_SUB+=	KERN_DEBUGDIR="${KERN_DEBUGDIR:C,^/,,}"
MAKE_ENV+=	KERN_DEBUGDIR="${KERN_DEBUGDIR}"
_KMOD_DIRS!=	${_DEBUG_KMOD_SH}
PLIST_FILES+=	${_KMOD_DIRS}
.endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_KMOD_POST_MK)
_INCLUDE_USES_KMOD_POST_MK=	yes

_USES_install+=	290:${STAGEDIR}${KMODDIR}
${STAGEDIR}${KMODDIR}:
	@${MKDIR} ${.TARGET}

.if !empty(_DEBUG_KMOD)
_USES_install+=	291:${STAGEDIR}${KERN_DEBUGDIR}${KMODDIR}
${STAGEDIR}${KERN_DEBUGDIR}${KMODDIR}:
	@${MKDIR} ${.TARGET}
.endif

.endif
