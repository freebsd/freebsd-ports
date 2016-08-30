# $FreeBSD$

PORTEPOCH=	0
CATEGORIES=	base
PKGNAMEPREFIX=	${OPSYS}-
VALID_CATEGORIES=	base

COMMENT=	GNU binary tools for base

MASTERDIR=	${.CURDIR}/../..//devel/binutils
PLIST=		${.CURDIR}/pkg-plist.${TARGET_ARCH}

.if !defined(CROSS_TOOLCHAIN)
.error Please define CROSS_TOOLCHAIN before building
.endif

.if !defined(CROSS_SYSROOT)
.error Please define CROSS_SYSROOT before building
.endif

TARGET_ARCH=	${CROSS_TOOLCHAIN:C,-.*$,,}
BUTARGET=	${TARGET_ARCH}-${OPSYS:tl}
CONFIGURE_ARGS+=	--host=${BUTARGET} \
			--disable-host-shared
PREFIX=	/usr

.include "${MASTERDIR}/Makefile"
.include "${LOCALBASE}/share/toolchains/${CROSS_TOOLCHAIN}.mk"

PKG_ENV+=	ABI_FILE=${CROSS_SYSROOT}/bin/sh
CFLAGS+=	--sysroot=${CROSS_SYSROOT} -isystem ${CROSS_SYSROOT}/usr/include
CXXFLAGS+=	--sysroot=${CROSS_SYSROOT}
CC=	${XCC}
CXX=	${XCXX}
.for tool in AS AR LD NM OBJCOPY RANLIB SIZE STRINGS
${tool}=	${CROSS_BINUTILS_PREFIX}${tool:tl}
.endfor
STRIP_CMD=	${CROSS_BINUTILS_PREFIX}strip
STRIPBIN=	${STRIP_CMD}
.export.env	STRIPBIN
