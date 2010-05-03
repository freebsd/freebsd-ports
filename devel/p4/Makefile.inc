# Figure out what to install
.if ${ARCH} == amd64
. if ${OSVERSION} >= 700043
PLATFORM=	freebsd70x86_64
. elif ${OSVERSION} >= 600033
PLATFORM=	freebsd60x86_64
. elif ${OSVERSION} >= 504000
PLATFORM=	freebsd54x86_64
. else
IGNORE=		unsupported OS release, sorry
. endif

.elif ${ARCH} == i386
. if ${OSVERSION} >= 700043
PLATFORM=	freebsd70x86
. elif ${OSVERSION} >= 600033
PLATFORM=	freebsd60x86
. elif ${OSVERSION} >= 504000
PLATFORM=	freebsd54x86
. else
IGNORE=		unsupported OS release, sorry
. endif

.elif ${ARCH} == sparc64
. if ${OSVERSION} >= 700043
LIB_DEPENDS+=	c.6:${PORTSDIR}/misc/compat6x
. endif
PLATFORM=	freebsd61sparc64

.else
IGNORE=		unsupported OS release, sorry
.endif
