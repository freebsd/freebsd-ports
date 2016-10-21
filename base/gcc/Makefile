# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	5.4.0
CATEGORIES=	devel
MASTER_SITES=	GCC/releases/gcc-${DISTVERSION} \
		http://www.mpfr.org/mpfr-current/:mpfr \
		GNU/gmp:gmp \
		http://www.multiprecision.org/mpc/download/:mpc
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		mpfr-3.1.4.tar.xz:mpfr \
		gmp-5.1.3.tar.xz:gmp \
		mpc-1.0.3.tar.gz:mpc
PKGNAMEPREFIX=	${OPSYS:tl}-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	GNU Compiler Collection

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

.if !defined(CROSS_TOOLCHAIN)
.error Please define CROSS_TOOLCHAIN before building
.endif

.if !defined(CROSS_SYSROOT)
.error Please define CROSS_SYSROOT before building
.endif

PREFIX=		/usr
CONFIGURE_ENV=	gcc_gxx_include_dir="/usr/include/c++/v1"
TARGET_ARCH=	${CROSS_TOOLCHAIN:C,-.*$,,}
GCC_TARGET=	${TARGET_ARCH}-portbld-${OPSYS:tl}${OSREL}

USES=	gmake libtool tar:bzip2 makeinfo
PLIST_SUB=	TARGETARCH=${TARGET_ARCH} \
		OPSYS=${OPSYS:tl} \
		GCC_TARGET=${GCC_TARGET} \
		GCC_VERSION=${PORTVERSION}

TARGET_ARCH=	${CROSS_TOOLCHAIN:C,-.*$,,}
EXTRA_PATCHES+= ${.CURDIR}/../../devel/powerpc64-gcc/files/freebsd-format-extensions

CONFIGURE_ENV=	LC_ALL=C
MAKE_ENV=	LC_ALL=C
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS+=--target=${GCC_TARGET} --disable-nls \
		--enable-languages=c,c++ \
		--without-headers \
		--with-build-sysroot=${CROSS_SYSROOT} \
		-with-pkgversion="GNU Collection for FreeBSD"

ALL_TARGET?=	all-gcc
INSTALL_TARGET?=	install-gcc

post-extract:
	cd ${WRKSRC}; ${LN} -sf ../mpfr-3.1.4 mpfr ; \
		${LN} -sf ../gmp-5.1.3 gmp ; \
		${LN} -sf ../mpc-1.0.3 mpc

post-patch:
	@${REINPLACE_CMD} -e '/LIBSTDCXX/ s/stdc\+\+/c\+\+/g ' \
		${WRKSRC}//gcc/cp/g++spec.c

post-install:
	for tool in cpp gcc g++ gcov; do \
		${LN} -sf ${GCC_TARGET}-$${tool}  ${STAGEDIR}/usr/bin/$${tool} ; \
		${LN} -sf ${GCC_TARGET}-$${tool}.1.gz ${STAGEDIR}/${MANDIR}1/$${tool}.1.gz ; \
	done ; \
	${LN} -sf ${GCC_TARGET}-g++  ${STAGEDIR}/usr/bin/c++ ; \
	${LN} -sf ${GCC_TARGET}-g++.1.gz ${STAGEDIR}/${MANDIR}1/c++.1.gz
	${LN} -sf ${GCC_TARGET}-gcc  ${STAGEDIR}/usr/bin/cc ; \
	${LN} -sf ${GCC_TARGET}-gcc.1.gz ${STAGEDIR}/${MANDIR}1/cc.1.gz
	${RM} -r ${STAGEDIR}/usr/share/info

.include <bsd.port.mk>
