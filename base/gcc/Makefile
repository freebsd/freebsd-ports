# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	6.3.0
CATEGORIES=	base
MASTER_SITES=	GCC/releases/gcc-${DISTVERSION} \
		http://www.mpfr.org/mpfr-3.1.6/:mpfr \
		http://www.mpfr.org/mpfr-current/:mpfr \
		GNU/gmp:gmp \
		https://ftp.gnu.org/gnu/mpc/:mpc
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		mpfr-3.1.6.tar.xz:mpfr \
		gmp-6.1.2.tar.xz:gmp \
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
CONFIGURE_ENV=	gcc_gxx_include_dir="/usr/include/c++/v1" \
		NM=/usr/bin/nm \
		AS_FOR_TARGET=/usr/bin/as \
		LD_FOR_TARGET=/usr/bin/ld \
		NM_FOR_TARGET=/usr/bin/nm
GCC_TARGET=	${ARCH}-unknown-${OPSYS:tl}${OSREL}
USES=	gmake libtool tar:bzip2 makeinfo
PLIST_SUB=	TARGETARCH=${ARCH} \
		OPSYS=${OPSYS:tl} \
		GCC_TARGET=${GCC_TARGET} \
		GCC_VERSION=${PORTVERSION}

EXTRA_PATCHES+= ${.CURDIR}/../../devel/powerpc64-gcc/files/freebsd-format-extensions
EXTRA_PATCHES+= ${.CURDIR}/../../devel/powerpc64-gcc/files/patch-gcc-freebsd-mips

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS+=	\
		--target=${GCC_TARGET} \
		--enable-languages=c,c++ \
		--disable-nls \
		--without-headers \
		--with-gxx-include-dir=/usr/include/c++/v1/ \
		--with-build-sysroot=${CROSS_SYSROOT} \
		-with-pkgversion="GNU Collection for FreeBSD"

ALL_TARGET?=	all-gcc
INSTALL_TARGET?=	install-gcc

.include <bsd.port.pre.mk>

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

post-extract:
	cd ${WRKSRC}; ${LN} -sf ../mpfr-3.1.6 mpfr ; \
		${LN} -sf ../gmp-6.1.2 gmp ; \
		${LN} -sf ../mpc-1.0.3 mpc

post-patch:
	@${REINPLACE_CMD} -e '/LIBSTDCXX/ s/stdc\+\+/c\+\+/g ' \
		${WRKSRC}//gcc/cp/g++spec.c
	@${REINPLACE_CMD} -e '/LOCAL_INCLUDE_DIR/ d ' \
		${WRKSRC}//gcc/Makefile.in

post-install:
	${MV} ${STAGEDIR}/usr/bin/gcov-tool ${STAGEDIR}/usr/bin/${GCC_TARGET}-gcov-tool ; \
	for tool in cpp gcc g++ gcov; do \
		${MV} ${STAGEDIR}/usr/bin/$${tool} ${STAGEDIR}/usr/bin/${GCC_TARGET}-$${tool} ; \
		${LN} -sf ${GCC_TARGET}-$${tool}  ${STAGEDIR}/usr/bin/$${tool} ; \
		${MV} ${STAGEDIR}/${MANDIR}1/$${tool}.1 ${STAGEDIR}/${MANDIR}1/${GCC_TARGET}-$${tool}.1 ; \
		${GZIP_CMD} ${STAGEDIR}/${MANDIR}1/${GCC_TARGET}-$${tool}.1 ; \
		${LN} -sf ${GCC_TARGET}-$${tool}.1.gz ${STAGEDIR}/${MANDIR}1/$${tool}.1.gz ; \
	done ; \
	${LN} -sf ${GCC_TARGET}-g++  ${STAGEDIR}/usr/bin/c++ ; \
	${LN} -sf ${GCC_TARGET}-g++.1.gz ${STAGEDIR}/${MANDIR}1/c++.1.gz
	${LN} -sf ${GCC_TARGET}-gcc  ${STAGEDIR}/usr/bin/cc ; \
	${LN} -sf ${GCC_TARGET}-gcc.1.gz ${STAGEDIR}/${MANDIR}1/cc.1.gz
	${RM} -r ${STAGEDIR}/usr/share/info
	${RM} -r ${STAGEDIR}/usr/lib/gcc/${GCC_TARGET}/${PORTVERSION}/include-fixed

.include <bsd.port.mk>
