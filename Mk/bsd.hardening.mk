# $FreeBSD$
#
# HardenedBSD-related ports options

.if !defined(HARDENINGMKINCLUDED)
HARDENINGMKINCLUDED=	bsd.hardening.mk

# All the currenty available hardening options
# and defaults to be used with USE_HARDENING or
# HARDENING_OFF.

HARDENING_ALL=		cfi pie relro safestack

# Can pass exceptions from global make.conf,
# or the global HARDENING_OFF flag per feature.

HARDENING_OFF?=

# Can pass exceptions from port Makefile, too.

USE_HARDENING?=		# implicit auto-defaults apply
_USE_HARDENING=		# internal flags for auto mode

OPTIONS_GROUP+=		HARDENING

.if defined(PORTNAME)
.if ${PORTNAME:Mlib*} && ${PORTNAME:Mlibre*} == ""
_USE_HARDENING+=	lib
.endif
.if ${PORTNAME:M*kmod*}
_USE_HARDENING+=	kmod
.endif
.endif

.if defined(PKGNAMEPREFIX)
.if ${PKGNAMEPREFIX:Mlib}
_USE_HARDENING+=	lib
.endif
.endif

.if defined(PKGNAMESUFFIX)
.if ${PKGNAMESUFFIX:M-lib*}
_USE_HARDENING+=	lib
.endif
.endif

.if defined(USES)
.if ${USES:Mkmod}
_USE_HARDENING+=	kmod
.endif
.if ${USES:Mfortran}
_USE_HARDENING+=	fortran
.endif
.endif

.if defined(CATEGORIES)
.if ${CATEGORIES:Mx11-drivers}
_USE_HARDENING+=	x11
.endif
.if ${CATEGORIES:Mlinux}
_USE_HARDENING+=	linux
.endif
.endif

.if defined(NO_BUILD) || defined(NO_ARCH)
_USE_HARDENING+=	static
.endif

.if (defined(PACKAGE_BUILDING) || defined(BATCH)) && defined(HARDENING_LOCK)
# The lock prevents unused hardening options
# from being embedded into the package when
# building in batches and/or package building.
_USE_HARDENING+=	lock
.endif

.for h in ${USE_HARDENING}
_h:=		${h:C/\:.*//}
.if ${HARDENING_ALL:M${_h}} != ""
USE_HARDENING:=	${_h} ${USE_HARDENING:N${h}:N${_h}}
${_h}_ARGS:=	${h:C/^[^\:]*(\:|\$)//:S/,/ /g} ${${_h}_ARGS}
.endif
.endfor

#################################################
### Option-less PIC enforcement for libraries ###
#################################################

.if ${_USE_HARDENING:Mlib}
CFLAGS+=		-fPIC
CXXFLAGS+=		-fPIC
.endif

####################################################
### Position-Idependent Executable (PIE) support ###
####################################################

.if ${HARDENING_OFF:Mpie} == ""
.if ${OSVERSION} > 1100000

pie_ARGS?=		auto

.if ${pie_ARGS:Mauto}
.if ${_USE_HARDENING:Mlib} || ${_USE_HARDENING:Mkmod} || ${_USE_HARDENING:Mfortran} || ${_USE_HARDENING:Mlinux} || ${_USE_HARDENING:Mstatic}
# Do not enable PIE for libraries or kernel module ports.
pie_ARGS+=		off
.else
USE_HARDENING:=		pie ${USE_HARDENING:Npie}
.endif
.endif

PIE_DESC=		Build as PIE
PIE_USES=		pie

.if ${_USE_HARDENING:Mlock} == ""
OPTIONS_GROUP_HARDENING+=PIE
.endif

.if ${USE_HARDENING:Mpie} && ${pie_ARGS:Moff} == ""
.if !defined(NOPIE_PORTS) # XXX
OPTIONS_DEFAULT+=	PIE
.endif
.if ${_USE_HARDENING:Mlock} != ""
OPTIONS_GROUP_HARDENING+=PIE
.endif
.endif

.endif
.endif

################################
### RELRO + BIND_NOW support ###
################################

.if ${HARDENING_OFF:Mrelro} == ""

relro_ARGS?=		auto

.if ${relro_ARGS:Mauto}
.if ${_USE_HARDENING:Mlib} || ${_USE_HARDENING:Mkmod} || ${_USE_HARDENING:Mfortran} || ${_USE_HARDENING:Mx11} || ${_USE_HARDENING:Mlinux} || ${_USE_HARDENING:Mstatic}
relro_ARGS+=		off
.else
USE_HARDENING:=		relro ${USE_HARDENING:Nrelro}
.endif
.endif

RELRO_DESC=		Build with RELRO + BIND_NOW
RELRO_USES=		relro

.if ${_USE_HARDENING:Mlock} == ""
OPTIONS_GROUP_HARDENING+=RELRO
.endif

.if ${USE_HARDENING:Mrelro} && ${relro_ARGS:Moff} == ""
.if !defined(NORELRO_PORTS) # XXX
OPTIONS_DEFAULT+=	RELRO
.endif
.if ${_USE_HARDENING:Mlock} != ""
OPTIONS_GROUP_HARDENING+=RELRO
.endif
.endif

.endif

#########################
### SafeStack support ###
#########################

.if ${HARDENING_OFF:Msafestack} == ""
.if ${OSVERSION} >= 1100122 && ${ARCH} == "amd64"

safestack_ARGS?=

.if defined(EXPLICIT_SAFESTACK) # XXX
USE_HARDENING+=		safestack
.elif ${_USE_HARDENING:Mstatic}
safestack_ARGS+=	off
.endif

SAFESTACK_DESC=		Build with SafeStack
SAFESTACK_USES=		safestack

.if ${_USE_HARDENING:Mlock} == ""
OPTIONS_GROUP_HARDENING+=SAFESTACK
.endif

.if ${USE_HARDENING:Msafestack} && ${safestack_ARGS:Moff} == ""
OPTIONS_DEFAULT+=	SAFESTACK
.if ${_USE_HARDENING:Mlock} != ""
OPTIONS_GROUP_HARDENING+=SAFESTACK
.endif
.endif

.endif
.endif

###################
### CFI support ###
###################

.if ${HARDENING_OFF:Mcfi} == ""
.if ${OSVERSION} >= 1200020 && ${LLD_IS_LD} == "yes" && ${ARCH} == "amd64"

cfi_ARGS?=

.if ${_USE_HARDENING:Mstatic}
cfi_ARGS+=		off
.endif

CFIHARDEN_DESC=		Build with CFI (Requires lld 4.0.0 or later in base)
CFIHARDEN_USES=		cfi

.if ${_USE_HARDENING:Mlock} == ""
OPTIONS_GROUP_HARDENING+=CFIHARDEN
.endif

.if ${USE_HARDENING:Mcfi} && ${cfi_ARGS:Moff} == ""
OPTIONS_DEFAULT+=	CFIHARDEN
.if ${_USE_HARDENING:Mlock} != ""
OPTIONS_GROUP_HARDENING+=CFIHARDEN
.endif
.endif

.endif
.endif

.endif # !HARDENINGMKINCLUDED
