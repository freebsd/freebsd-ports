# $FreeBSD$
#
# HardenedBSD-related ports options

.if !defined(HARDENINGMKINCLUDED)
HARDENINGMKINCLUDED=	bsd.hardening.mk

# Can pass exceptions from global make.conf,
# or the global HARDENING_OFF flag per feature.

HARDENING_OFF?=

# Can pass exceptions from port Makefile, too.

USE_HARDENING?=		pie relro

.if defined(PORTNAME)
.if ${PORTNAME:Mlib*} && ${PORTNAME:Mlibre*} == ""
USE_HARDENING+=	lib
.endif
.if ${PORTNAME:M*kmod*}
USE_HARDENING+=	kmod
.endif
.endif

.if defined(PKGNAMEPREFIX)
.if ${PKGNAMEPREFIX:Mlib}
USE_HARDENING+=	lib
.endif
.endif

.if defined(PKGNAMESUFFIX)
.if ${PKGNAMESUFFIX:M-lib*}
USE_HARDENING+=	lib
.endif
.endif

.if defined(USES)
.if ${USES:Mkmod}
USE_HARDENING+=	kmod
.endif
.if ${USES:Mfortran}
USE_HARDENING+=	fortran
.endif
.endif

.if defined(CATEGORIES)
.if ${CATEGORIES:Mx11-drivers}
USE_HARDENING+=	x11
.endif
.if ${CATEGORIES:Mlinux}
USE_HARDENING+=	linux
.endif
.endif

.if defined(NO_BUILD) || defined(NO_ARCH)
USE_HARDENING+=	static
.endif

#################################################
### Option-less PIC enforcement for libraries ###
#################################################

.if ${USE_HARDENING:Mlib}
CFLAGS+=		-fPIC
CXXFLAGS+=		-fPIC
.endif

####################################################
### Position-Idependent Executable (PIE) support ###
####################################################

.if ${USE_HARDENING:Mlib} || ${USE_HARDENING:Mkmod} || ${USE_HARDENING:Mfortran} || ${USE_HARDENING:Mlinux} || ${USE_HARDENING:Mstatic}
# Do not enable PIE for libraries or kernel module ports.
USE_HARDENING+=		nopie
.endif

.if ${HARDENING_OFF:Mpie} == ""
.if ${USE_HARDENING:Mpie} && ${USE_HARDENING:Mnopie} == ""
OPTIONS_DEFINE+=	PIE
PIE_DESC=		Build as PIE
PIE_USES=		pie
PIE_ARGS?=

.if !defined(NOPIE_PORTS)
OPTIONS_DEFAULT+=	PIE
.endif
.endif
.endif

################################
### RELRO + BIND_NOW support ###
################################

.if ${USE_HARDENING:Mlib} || ${USE_HARDENING:Mkmod} || ${USE_HARDENING:Mfortran} || ${USE_HARDENING:Mx11} || ${USE_HARDENING:Mlinux} || ${USE_HARDENING:Mstatic}
# Same reasoning here with RELRO as with PIE.
USE_HARDENING+=		norelro
.endif

.if ${HARDENING_OFF:Mrelro} == ""
.if ${USE_HARDENING:Mrelro} && ${USE_HARDENING:Mnorelro} == ""
OPTIONS_DEFINE+=	RELRO
RELRO_DESC=		Build with RELRO + BIND_NOW
RELRO_USES=		relro

.if !defined(NORELRO_PORTS)
OPTIONS_DEFAULT+=	RELRO
.endif
.endif
.endif

#########################
### SafeStack support ###
#########################

.if ${OSVERSION} >= 1100122

.if ${USE_HARDENING:Mstatic} || ${ARCH} != "amd64"
USE_HARDENING+=		nosafestack
.endif

.if defined(EXPLICIT_SAFESTACK) # XXX
USE_HARDENING+=		safestack
.endif

.if ${HARDENING_OFF:Msafestack} == ""
.if ${USE_HARDENING:Msafestack} && ${USE_HARDENING:Mnosafestack} == ""
OPTIONS_DEFINE+=	SAFESTACK
SAFESTACK_DESC=		Build with SafeStack
SAFESTACK_USES=		safestack
SAFESTACK_ARGS?=

.if defined(EXPLICIT_SAFESTACK) # XXX
OPTIONS_DEFAULT+=	SAFESTACK
.endif
.endif
.endif

.endif

###################
### CFI support ###
###################

.if ${HARDENING_OFF:Mcfi} == ""
OPTIONS_DEFINE+=	CFIHARDEN
CFIHARDEN_DESC=		Build with CFI (Requires lld 4.0.0 in base)
CFIHARDEN_USES=		cfi

.if defined(EXPLICIT_CFIHARDEN)
OPTIONS_DEFAULT+=	CFIHARDEN
.endif
.endif

.endif # !HARDENINGMKINCLUDED
