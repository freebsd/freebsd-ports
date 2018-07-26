# $FreeBSD$

PORTEPOCH=	0
CATEGORIES=	base
PKGNAMEPREFIX=	${OPSYS:tl}-
VALID_CATEGORIES=	base

COMMENT=	GNU binary tools for base

MASTERDIR=	${.CURDIR}/../../devel/binutils
PLIST=		${.CURDIR}/pkg-plist

.if !defined(CROSS_TOOLCHAIN)
.error Please define CROSS_TOOLCHAIN before building
.endif

.if !defined(CROSS_SYSROOT)
.error Please define CROSS_SYSROOT before building
.endif

TARGETARCH=	${ARCH:S/amd64/x86_64/}
BUTARGET=	${TARGETARCH}-unknown-${OPSYS:tl}${OSREL}

CONFIGURE_ARGS+=	--disable-host-shared
PREFIX=	/usr

.include "${MASTERDIR}/Makefile"

.if ${OSVERSION} >= 1100100
PLIST_SUB+=	OBJCOPY="@comment "
.else
PLIST_SUB+=	OBJCOPY=""
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif
.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64=""
.else
PLIST_SUB+=	AMD64="@comment "
.endif
.if ${ARCH:Mmips*}
PLIST_SUB+=	MIPS=""
.else
PLIST_SUB+=	MIPS="@comment "
.endif
.if ${ARCH:Mpowerpc*}
PLIST_SUB+=	POWERPC=""
.else
PLIST_SUB+=	POWERPC="@comment "
.endif
.if ${ARCH:Msparc*}
PLIST_SUB+=	SPARC=""
.else
PLIST_SUB+=	SPARC="@comment "
.endif
