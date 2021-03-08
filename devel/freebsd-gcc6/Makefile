# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	6.5.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GCC
PKGNAMEPREFIX=	${TARGETARCH}-
PKGNAMESUFFIX=	${SUFFIX}

MAINTAINER=	jhb@FreeBSD.org
COMMENT=	Cross GNU Compiler Collection for ${TARGETARCH}

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	${BU_PREFIX}-as:devel/binutils@${TARGETARCH} \
		objdump:devel/binutils
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
RUN_DEPENDS=	${BU_PREFIX}-as:devel/binutils@${TARGETARCH}

FLAVORS=	aarch64 amd64 i386 mips mips64 powerpc64 sparc64
TARGETARCH=	${FLAVOR}

USES=		compiler:c++11-lang gmake iconv libtool makeinfo tar:xz

CONFLICTS=	${TARGETARCH}-gcc

PLIST_SUB=	OPSYS=${OPSYS:tl} \
		SUFFIX=${SUFFIX} \
		TARGETARCH=${TARGETARCH} \
		GCC_TARGET=${GCC_TARGET} \
		GCC_VERSION=${PORTVERSION}

SUB_FILES=	xtoolchain.mk
SUB_LIST=	GCC_TARGET=${GCC_TARGET}

GCC_TARGET=	${FLAVOR:S/amd64/x86_64/}-unknown-${OPSYS:tl}${OSREL}
SUFFIX=		${PORTVERSION:C/([0-9]+).*/\1/}
BU_PREFIX=	${GCC_TARGET}

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS+=--target=${GCC_TARGET} --disable-nls --enable-languages=c,c++ \
		--enable-gnu-indirect-function \
		--enable-initfini-array \
		--program-prefix=${GCC_TARGET}- \
		--program-suffix=${SUFFIX} \
		--without-headers \
		--with-gmp=${LOCALBASE} \
		--with-pkgversion="FreeBSD Ports Collection for ${PKGNAMEPREFIX:C/-//g}" \
		--with-system-zlib \
		--with-gxx-include-dir=/usr/include/c++/v1/ \
		--with-sysroot="/" \
		--with-as=${LOCALBASE}/bin/${BU_PREFIX}-as \
		--with-ld=${LOCALBASE}/bin/${BU_PREFIX}-ld

ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/LIBSTDCXX/ s/stdc\+\+/c\+\+/g ' \
		${WRKSRC}//gcc/cp/g++spec.c
	@${REINPLACE_CMD} -e '/LOCAL_INCLUDE_DIR/ d ' \
		${WRKSRC}//gcc/Makefile.in

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-unknown-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-unknown-${OPSYS:tl}${OSREL}
.endif

.if ${TARGETARCH} == "armv6" || ${TARGETARCH} == "aarch64"
. if ${COMPILER_TYPE} == clang
MAKE_ARGS+=CXXFLAGS=-fbracket-depth=512
. endif
.endif

.if ${ARCH} == "aarch64"
PLIST_SUB+=	PLUGINS="@comment plugin does not build"
.else
PLIST_SUB+=	PLUGINS=""
.endif

.if ${TARGETARCH} == "amd64" || ${TARGETARCH} == "i386"
PLIST_SUB+=	FLOAT_H="@comment "
.else
PLIST_SUB+=	FLOAT_H=""
.endif

PLIST=		${.CURDIR}/pkg-plist ${.CURDIR}/pkg-plist.common

.if ${TARGETARCH} == "aarch64"
PLIST+=		${.CURDIR}/pkg-plist.aarch64
.endif
.if ${TARGETARCH} == "aarch64" || ${TARGETARCH:Marm*}
PLIST+=		${.CURDIR}/pkg-plist.arm
.endif
.if ${TARGETARCH} == "amd64"
PLIST+=		${.CURDIR}/pkg-plist.amd64
.endif
.if ${TARGETARCH} == "amd64" || ${TARGETARCH} == "i386"
PLIST+=		${.CURDIR}/pkg-plist.i386
.endif
.if ${TARGETARCH:Mmips*}
PLIST+=		${.CURDIR}/pkg-plist.mips
.endif
.if ${TARGETARCH:Mpowerpc*}
PLIST+=		${.CURDIR}/pkg-plist.powerpc
.endif
.if ${TARGETARCH} == "sparc64"
PLIST+=		${.CURDIR}/pkg-plist.sparc64
.endif

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/${GCC_TARGET}-${GCC_TARGET}-*
	@${RM} ${STAGEDIR}${PREFIX}/share/info/*
	@${RM} ${STAGEDIR}${PREFIX}/man/man7/*
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/gcc/${GCC_TARGET}/${PORTVERSION}/include-fixed
.if ${TARGETARCH} == "amd64" || ${TARGETARCH} == "i386"
	# Conflicts with sys/x86/include/float.h
	${RM} ${STAGEDIR}${PREFIX}/lib/gcc/${GCC_TARGET}/${PORTVERSION}/include/float.h
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/share/toolchains/
	${INSTALL_DATA} ${WRKDIR}/xtoolchain.mk \
		${STAGEDIR}${PREFIX}/share/toolchains/${TARGETARCH}-gcc${SUFFIX}.mk

.include <bsd.port.post.mk>
