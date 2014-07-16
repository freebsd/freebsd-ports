# Figure out what to install
.if ${ARCH} == amd64
. if ${OSVERSION} >= 1000100
PLATFORM=	freebsd100x86_64
. elif ${OSVERSION} >= 700043
PLATFORM=	freebsd70x86_64
. else
IGNORE=		unsupported OS release, sorry
. endif

.elif ${ARCH} == i386
. if ${OSVERSION} >= 1000100
PLATFORM=	freebsd100x86
. elif ${OSVERSION} >= 700043
PLATFORM=	freebsd70x86
. else
IGNORE=		unsupported OS release, sorry
. endif

.else
IGNORE=		unsupported OS release, sorry
.endif
