# $FreeBSD$
#
# HardenedBSD-related ports options

.if !defined(__BSD_PORT_HARDENING_MK)
__BSD_PORT_HARDENING_MK=1

####################################################
### Position-Idependent Executable (PIE) support ###
####################################################

OPTIONS_DEFINE+=	PIE
PIE_DESC=		Build as PIE
PIE_USES=		pie
PIE_ARGS?=

# Do not enable PIE for libraries or kernel module ports. However,
# provide a way for still enabling PIE if desired by the port's
# maintainer by allowing them to define EXPLICIT_PIE.
#
# It's possible that keying off lib* as the port's name could
# introduce false positives. Hence even more reason to have
# EXPLICIT_PIE.
.if defined(PORTNAME)
.if !defined(EXPLICIT_PIE)
.if ${PORTNAME:Mlib*} || ${PORTNAME:M*kmod*} || \
	(defined(PKGNAMESUFFIX) && (${PKGNAMESUFFIX:Mlib*}))
NOPIE_PORTS=	yes
.endif
.endif

.if ${PORTNAME:Mlib*} || (defined(PKGNAMESUFFIX) && (${PKGNAMESUFFIX:Mlib*}))
CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC
.endif

.endif

.if defined(USES)
.if ${USES:Mkmod} || ${USES:Mfortran}
NOPIE_PORTS=	yes
.endif
.endif

.if defined(CATEGORIES)
.if ${CATEGORIES:Mlinux}
NOPIE_PORTS=	yes
.endif
.endif

.if !defined(NOPIE_PORTS)
OPTIONS_DEFAULT+=	PIE
.endif

################################
### RELRO + BIND_NOW support ###
################################

OPTIONS_DEFINE+=	RELRO
RELRO_DESC=		Build with RELRO + BIND_NOW
RELRO_USES=		relro

# Same reasoning here with RELRO as with PIE.
.if defined(PORTNAME)
.if !defined(EXPLICIT_RELRO)
.if ${PORTNAME:Mlib*} || ${PORTNAME:M*kmod*} || \
	(defined(PKGNAMESUFFIX) && (${PKGNAMESUFFIX:Mlib*}))
NORELRO_PORTS=	yes
.endif
.endif
.endif

.if defined(USES)
.if ${USES:Mkmod} || ${USES:Mfortran}
NORELRO_PORTS=	yes
.endif
.endif

.if defined(CATEGORIES)
.if ${CATEGORIES:Mx11-drivers} || ${CATEGORIES:Mlinux}
NORELRO_PORTS=	yes
.endif
.endif

.if !defined(NORELRO_PORTS)
OPTIONS_DEFAULT+=	RELRO
.endif

#########################
### SafeStack support ###
#########################

OPTIONS_DEFINE+=	SAFESTACK
SAFESTACK_DESC=		Build with SafeStack
SAFESTACK_USES=		safestack
SAFESTACK_ARGS?=

.if defined(EXPLICIT_SAFESTACK)
OPTIONS_DEFAULT+=	SAFESTACK
.endif

###################
### CFI support ###
###################

OPTIONS_DEFINE+=	CFIHARDEN
CFIHARDEN_DESC=		Build with CFI (Requires lld 4.0.0 in base)
CFIHARDEN_USES=		cfi

.if defined(EXPLICIT_CFIHARDEN)
OPTIONS_DEFAULT+=	CFIHARDEN
.endif

.endif # !__BSD_PORT_HARDENING_MK
