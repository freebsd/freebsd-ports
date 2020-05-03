# $FreeBSD$

PORTNAME=	gcc
PORTVERSION?=	8.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GCC
PKGNAMEPREFIX?=	aarch64-none-elf-

MAINTAINER=	manu@FreeBSD.org
COMMENT=	GNU Compiler Collection for bare metal arm cross-development

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BROKEN_mips=		configure: error: cannot compute suffix of object files: cannot compile
BROKEN_mips64=		configure: error: cannot compute suffix of object files: cannot compile

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
BUILD_DEPENDS=	${GCC_TARGET}-as:devel/binutils@${PKGNAMEPREFIX:C/-$//:C/-/_/g} \
		objdump:devel/binutils@native
RUN_DEPENDS=	${GCC_TARGET}-as:devel/binutils@${PKGNAMEPREFIX:C/-$//:C/-/_/g}

USES=	gmake iconv libtool tar:xz makeinfo compiler:c++11-lang

PLIST_SUB=	TARGETARCH=${PKGNAMEPREFIX:C/-//g} \
		OPSYS=${OPSYS:tl} \
		GCC_TARGET=${GCC_TARGET} \
		GCC_VERSION=${PORTVERSION}

TARGETARCH=	${PKGNAMEPREFIX:C/-//g}

GCC_TARGET?=	aarch64-none-elf

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS+=--target=${GCC_TARGET} --disable-nls --enable-languages=c,c++ \
		--enable-gnu-indirect-function \
		--without-headers \
		--with-gmp=${LOCALBASE} \
		--with-pkgversion="FreeBSD Ports Collection for ${PKGNAMEPREFIX:C/-//g}" \
		--with-system-zlib \
		--with-gxx-include-dir=/usr/include/c++/v1/ \
		--with-sysroot="/" \
		--with-as=${LOCALBASE}/bin/${GCC_TARGET}-as \
		--with-ld=${LOCALBASE}/bin/${GCC_TARGET}-ld

# U-Boot requires libgcc, crossbuild and install it along with the compiler.
ALL_TARGET=	all-gcc all-target-libgcc
INSTALL_TARGET=	install-gcc install-target-libgcc

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

# The following is required for clang to bootstrap gcc.
.if ${COMPILER_TYPE} == clang
MAKE_ARGS+=	CXXFLAGS=-fbracket-depth=512
.endif

post-install:
.for f in cpp gcov gcov-dump gcov-tool
	@if [ -f ${STAGEDIR}${PREFIX}/bin/$f ] ; then \
		${MV} ${STAGEDIR}${PREFIX}/bin/$f  \
		    ${STAGEDIR}${PREFIX}/bin/${GCC_TARGET}-$f ; \
	fi
.endfor
.for f in c++ cpp g++ gcc gcc-ar gcc-nm gcc-ranlib gcov gcov-dump gcov-tool
	@if [ ! -f ${STAGEDIR}${PREFIX}/man/man1/${GCC_TARGET}-$f.1 ] ; then \
		if [ -f ${STAGEDIR}${PREFIX}/man/man1/$f.1 ] ; then \
			${CP} ${STAGEDIR}${PREFIX}/man/man1/$f.1  \
			    ${STAGEDIR}${PREFIX}/man/man1/${GCC_TARGET}-$f.1 ; \
		fi \
	fi
	@${RM} ${STAGEDIR}${PREFIX}/bin/$f
	@${RM} ${STAGEDIR}${PREFIX}/man/man1/$f.1
	@${RM} ${STAGEDIR}${PREFIX}/man/man1/$f.1.gz
.endfor
	@${RM} ${STAGEDIR}${PREFIX}/share/info/*
	@${RM} ${STAGEDIR}${PREFIX}/man/man7/*

.include <bsd.port.post.mk>
