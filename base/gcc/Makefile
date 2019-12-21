# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	6.4.0
PORTREVISION=	2
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

TARGETARCH=	${ARCH:S/amd64/x86_64/}
GCC_TARGET=	${TARGETARCH}-unknown-${OPSYS:tl}${OSREL}

PREFIX=		/usr
.for _tool in CC CXX CPP AS AR LD NM OBJCOPY RANLIB SIZE STRINGS
CONFIGURE_ENV+= ${_tool}_FOR_TARGET="${${_tool}}"
.endfor

USES=	gmake libtool tar:xz makeinfo
PLIST_SUB=	OPSYS=${OPSYS:tl} \
		GCC_TARGET=${GCC_TARGET} \
		GCC_VERSION=${PORTVERSION}

EXTRA_PATCHES+= ${.CURDIR}/../../devel/freebsd-gcc6/files

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS+=	\
		--target=${GCC_TARGET} \
		--enable-languages=c,c++ \
		--enable-gnu-indirect-function \
		--disable-nls \
		--without-headers \
		--with-gxx-include-dir=/usr/include/c++/v1/ \
		--with-build-sysroot=${CROSS_SYSROOT} \
		-with-pkgversion="GNU Collection for FreeBSD"

ALL_TARGET?=	all-gcc
INSTALL_TARGET?=	install-gcc

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1200000
CONFIGURE_ARGS+= --enable-initfini-array
.endif

.if ${HOSTARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-unknown-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${HOSTARCH}-unknown-${OPSYS:tl}${OSREL}
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_SUB+=	FLOAT_H="@comment "
.else
PLIST_SUB+=	FLOAT_H=""
.endif

PLIST=		${.CURDIR}/pkg-plist

.if ${ARCH} == "amd64"
PLIST+=		${.CURDIR}/pkg-plist.amd64
.endif
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST+=		${.CURDIR}/pkg-plist.i386
.endif
.if ${ARCH:Mmips*}
PLIST+=		${.CURDIR}/pkg-plist.mips
.endif
.if ${ARCH:Mpowerpc*}
PLIST+=		${.CURDIR}/pkg-plist.powerpc
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
	${LN} -f ${STAGEDIR}/usr/bin/gcc  ${STAGEDIR}/usr/bin/cc ; \
	${LN} -sf gcc.1 ${STAGEDIR}/${MANDIR}1/cc.1
	${LN} -sf g++.1 ${STAGEDIR}/${MANDIR}1/c++.1
	${RM} -r ${STAGEDIR}/usr/share/info
	${RM} -r ${STAGEDIR}/usr/lib/gcc/${GCC_TARGET}/${PORTVERSION}/include-fixed
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
	${RM} ${STAGEDIR}/usr/lib/gcc/${GCC_TARGET}/${PORTVERSION}/include/float.h
.endif

.include <bsd.port.post.mk>
