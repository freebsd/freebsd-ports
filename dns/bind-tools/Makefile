# Define PORTREVISION in ${MASTERDIR}
.ifdef BIND_TOOLS_DEVEL
MASTERDIR=	${.CURDIR}/../../dns/bind9-devel

PLIST=		${.CURDIR}/pkg-plist-devel
.else
MASTERDIR=	${.CURDIR}/../../dns/bind916

PLIST=		${.CURDIR}/pkg-plist
INSTALL_WRKSRC=	${WRKSRC}/bin
.endif
DESCR=		${.CURDIR}/pkg-descr

BIND_TOOLS_SLAVE=	YES

PORTSCOUT=	ignore:1

.include "${MASTERDIR}/Makefile"
