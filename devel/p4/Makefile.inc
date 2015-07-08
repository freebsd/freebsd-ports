# Figure out what to install
.if ${OPSYS} == FreeBSD

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
