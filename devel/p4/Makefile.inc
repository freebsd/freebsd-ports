# Figure out what to install
.if ${OPSYS} == FreeBSD

ONLY_FOR_ARCHS?= amd64 i386

.if ${ARCH} == amd64
. if ${OSVERSION} >= 1000100
PLATFORM=	freebsd100x86_64
. else
PLATFORM=	freebsd70x86_64
. endif

.elif ${ARCH} == i386
. if ${OSVERSION} >= 1000100
PLATFORM=	freebsd100x86
. else
PLATFORM=	freebsd70x86
. endif

.else
IGNORE=		unsupported OS release, sorry
.endif

.else
IGNORE=		${OPSYS} is unsupported, sorry
.endif

P4VERSION?=	r${PORTVERSION:S/^20//:C/\.[0-9]+$//}
DIST_SUBDIR?=	perforce/${PORTVERSION}/bin.${PLATFORM}
DISTINFO_FILE?=	${MASTERDIR}/distinfo.${PLATFORM}
