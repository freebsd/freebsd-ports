# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	6.4.0
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	GCC/releases/gcc-${DISTVERSION}
PKGNAMEPREFIX?=	powerpc64-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross GNU Compiler Collection for ${PKGNAMEPREFIX:C/-//g}

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
BUILD_DEPENDS=	${BU_PREFIX}-as:devel/binutils@${PKGNAMEPREFIX:C/-$//:C/-/_/g}
RUN_DEPENDS=	${BU_PREFIX}-as:devel/binutils@${PKGNAMEPREFIX:C/-$//:C/-/_/g}

USES=	gmake iconv libtool tar:xz makeinfo compiler:c++11-lang
PLIST_SUB=	TARGETARCH=${PKGNAMEPREFIX:C/-//g} \
		OPSYS=${OPSYS:tl} \
		GCC_TARGET=${GCC_TARGET} \
		GCC_VERSION=${PORTVERSION}

TARGETARCH=	${PKGNAMEPREFIX:C/-//g}

GCC_TARGET=	${PKGNAMEPREFIX:S/amd64/x86_64/}unknown-${OPSYS:tl}${OSREL}
BU_PREFIX?=	${GCC_TARGET}

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS+=--target=${GCC_TARGET} --disable-nls --enable-languages=c,c++ \
		--enable-gnu-indirect-function \
		--enable-initfini-array \
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
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/gcc/${GCC_TARGET}/${PORTVERSION}/include-fixed
.if ${TARGETARCH} == "amd64" || ${TARGETARCH} == "i386"
	# Conflicts with sys/x86/include/float.h
	${RM} ${STAGEDIR}${PREFIX}/lib/gcc/${GCC_TARGET}/${PORTVERSION}/include/float.h
.endif

.include <bsd.port.post.mk>
