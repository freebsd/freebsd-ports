# $FreeBSD$

PORTEPOCH=	0
CATEGORIES=	base
PKGNAMEPREFIX=	${OPSYS:tl}-
VALID_CATEGORIES=	base

COMMENT=	GNU binary tools for base

MASTERDIR=	${.CURDIR}/../../devel/binutils
PLIST=		${.CURDIR}/pkg-plist

TARGETARCH=	${ARCH:S/amd64/x86_64/}
BUTARGET=	${TARGETARCH}-unknown-${OPSYS:tl}${OSREL}

CONFIGURE_ARGS+=	--disable-host-shared
PREFIX=	/usr
BUREMOVE=	addr2line \
		ar \
		c++filt \
		dlltool \
		elfedit \
		gprof \
		nlmconv \
		nm \
		ranlib \
		readelf \
		size \
		strings \
		strip \
		windmc \
		windres

.include "${MASTERDIR}/Makefile"

PLIST_SUB+=	OBJCOPY="@comment "
BUREMOVE+=	objcopy

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
