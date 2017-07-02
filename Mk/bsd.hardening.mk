# $FreeBSD$
#
# HardenedBSD-related ports options

.if !defined(HARDENINGMKINCLUDED)
HARDENINGMKINCLUDED=	bsd.hardening.mk

# Can pass exceptions from global make.conf,
# or the global HARDENING_OFF flag per feature.

HARDENING_OFF?=

# Can pass exceptions from port Makefile, too.

USE_HARDENING?=		pie:default relro:default
_USE_HARDENING=		# internal flags

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

.if defined(PACKAGE_BUILDING) || defined(BATCH)
_USE_HARDENING+=	batch
.endif

.for h in ${USE_HARDENING}
_h:=		${h:C/\:.*//}
.if ${_h} == "pie" || ${_h} == "relro" || ${_h} == "safestack"
.if !defined(${_h}_ARGS)
USE_HARDENING:=	${USE_HARDENING:N${h}} ${_h}
${_h}_ARGS:=	${h:C/^[^\:]*(\:|\$)//:S/,/ /g}
.endif
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

pie_ARGS?=

.if ${pie_ARGS:Mdefault}
.if ${_USE_HARDENING:Mlib} || ${_USE_HARDENING:Mkmod} || ${_USE_HARDENING:Mfortran} || ${_USE_HARDENING:Mlinux} || ${_USE_HARDENING:Mstatic}
# Do not enable PIE for libraries or kernel module ports.
USE_HARDENING+=		nopie
.endif
.endif

pie_ARGS:=		${PIE_ARGS} ${pie_ARGS} # XXX

PIE_DESC=		Build as PIE
PIE_USES=		pie

.if ${_USE_HARDENING:Mbatch} == ""
OPTIONS_GROUP_HARDENING+=PIE
.endif

.if ${USE_HARDENING:Mpie} && ${USE_HARDENING:Mnopie} == ""
.if !defined(NOPIE_PORTS) # XXX
OPTIONS_DEFAULT+=	PIE
.endif
.if ${_USE_HARDENING:Mbatch} != ""
OPTIONS_GROUP_HARDENING+=PIE
.endif
.endif

.endif
.endif

################################
### RELRO + BIND_NOW support ###
################################

.if ${HARDENING_OFF:Mrelro} == ""

relro_ARGS?=

.if ${relro_ARGS:Mdefault}
.if ${_USE_HARDENING:Mlib} || ${_USE_HARDENING:Mkmod} || ${_USE_HARDENING:Mfortran} || ${_USE_HARDENING:Mx11} || ${_USE_HARDENING:Mlinux} || ${_USE_HARDENING:Mstatic}
USE_HARDENING+=		norelro
.endif
.endif

RELRO_DESC=		Build with RELRO + BIND_NOW
RELRO_USES=		relro

.if ${_USE_HARDENING:Mbatch} == ""
OPTIONS_GROUP_HARDENING+=RELRO
.endif

.if ${USE_HARDENING:Mrelro} && ${USE_HARDENING:Mnorelro} == ""
.if !defined(NORELRO_PORTS) # XXX
OPTIONS_DEFAULT+=	RELRO
.endif
.if ${_USE_HARDENING:Mbatch} != ""
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
USE_HARDENING+=		nosafestack
.endif

safestack_ARGS:=	${SAFESTACK_ARGS} ${safestack_ARGS} # XXX

SAFESTACK_DESC=		Build with SafeStack
SAFESTACK_USES=		safestack

.if ${_USE_HARDENING:Mbatch} == ""
OPTIONS_GROUP_HARDENING+=SAFESTACK
.endif

.if ${USE_HARDENING:Msafestack} && ${USE_HARDENING:Mnosafestack} == ""
OPTIONS_DEFAULT+=	SAFESTACK
.if ${_USE_HARDENING:Mbatch} != ""
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

.if defined(EXPLICIT_CFIHARDEN) # XXX
USE_HARDENING+=		cfi
.elif ${_USE_HARDENING:Mstatic}
USE_HARDENING+=		nocfi
.endif

CFIHARDEN_DESC=		Build with CFI (Requires lld 4.0.0 in base)
CFIHARDEN_USES=		cfi

.if ${_USE_HARDENING:Mbatch} == ""
OPTIONS_GROUP_HARDENING+=CFIHARDEN
.endif

.if ${USE_HARDENING:Mcfi} && ${USE_HARDENING:Mnocfi} == ""
OPTIONS_DEFAULT+=	CFIHARDEN
.if ${_USE_HARDENING:Mbatch} != ""
OPTIONS_GROUP_HARDENING+=CFIHARDEN
.endif
.endif

.endif
.endif

.endif # !HARDENINGMKINCLUDED
