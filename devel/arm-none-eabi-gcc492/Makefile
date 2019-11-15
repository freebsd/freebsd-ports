# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.9.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GCC/releases/gcc-${DISTVERSION}
PKGNAMEPREFIX?=	arm-none-eabi-
PKGNAMESUFFIX=	492

MAINTAINER=	ian@FreeBSD.org
COMMENT=	GNU Compiler Collection for bare metal arm cross-development

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
BUILD_DEPENDS=	${BU_PREFIX}-as:devel/binutils@${PKGNAMEPREFIX:C/-$//:C/-/_/g}
RUN_DEPENDS=	${BU_PREFIX}-as:devel/binutils@${PKGNAMEPREFIX:C/-$//:C/-/_/g}

USES=	compiler gmake iconv libtool makeinfo tar:bzip2
PLIST_SUB=	TARGETARCH=${PKGNAMEPREFIX:C/-//g} \
		OPSYS=${OPSYS:tl} \
		GCC_TARGET=${GCC_TARGET}

GCC_TARGET=	arm-none-eabi
BU_PREFIX?=	${GCC_TARGET}

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
# libstdcxx won't build, but we don't need it or multiple float-abi libs.
CONFIGURE_ARGS= --target=${GCC_TARGET} --disable-nls --enable-languages=c,c++ \
		--without-headers \
		--with-gmp=${LOCALBASE} \
		--with-pkgversion="FreeBSD Ports Collection for ${PKGNAMEPREFIX:C/-//g}" \
		--with-system-zlib \
		--with-as=${LOCALBASE}/bin/${BU_PREFIX}-as \
		--with-ld=${LOCALBASE}/bin/${BU_PREFIX}-ld \
		--disable-libstdcxx \
		--disable-multilib

PLIST=	${.CURDIR}/pkg-plist

# U-Boot requires libgcc, crossbuild and install it along with the compiler.
ALL_TARGET=	all-gcc all-target-libgcc
INSTALL_TARGET=	install-gcc install-target-libgcc

.include <bsd.port.pre.mk>

CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}

post-install:
	@if [ -f ${STAGEDIR}${PREFIX}/bin/cpp ] ; then \
		${MV} ${STAGEDIR}${PREFIX}/bin/cpp  \
		    ${STAGEDIR}${PREFIX}/bin/${GCC_TARGET}-cpp ; \
	fi
.for f in c++ cpp g++ gcc gcc-ar gcc-nm gcc-ranlib gcov
	@${RM} ${STAGEDIR}${PREFIX}/bin/$f
	@${RM} ${STAGEDIR}${PREFIX}/man/man1/$f.1.gz
.endfor
	@${RM} ${STAGEDIR}${PREFIX}/info/*
	@${RM} ${STAGEDIR}${PREFIX}/man/man7/*

# The following is required for clang to bootstrap gcc.
.if ${COMPILER_TYPE} == clang
MAKE_ARGS+=	CXXFLAGS=-fbracket-depth=512
.endif

BROKEN_aarch64=		fails to package
BROKEN_mips=		configure: error: cannot compute suffix of object files: cannot compile
BROKEN_mips64=		configure: error: cannot compute suffix of object files: cannot compile

.include <bsd.port.post.mk>
