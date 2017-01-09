# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.27
PORTREVISION=	5
PORTEPOCH?=	1
CATEGORIES?=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases

MAINTAINER?=	bapt@FreeBSD.org
COMMENT?=	GNU binary tools

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

.if !defined(CROSS_TOOLCHAIN)
BUILD_DEPENDS=	${LOCALBASE}/lib/libgmp.so:math/gmp \
		${LOCALBASE}/lib/libmpfr.so:math/mpfr

CONFLICTS=	libbfd-[0-9]*
.endif

OPTIONS_DEFINE=	NLS RELRO

RELRO_DESC=	enable -z relro in ELF linker by default

LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING3.LIB

USES=		bison gmake libtool tar:bzip2 compiler:env
GNU_CONFIGURE=	yes

.if defined(PKGNAMEPREFIX)
BUTARGET?=	${PKGNAMEPREFIX}${OPSYS:tl}
OPTIONS_EXCLUDE=	NLS
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info
CONFIGURE_ARGS+=	--disable-shared \
			--target=${BUTARGET}
.else
BUREMOVE=	coffdump \
		dlltool \
		dllwrap \
		nlmconv \
		srconv \
		sysdump \
		windmc \
		windres
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-system-zlib \
			--with-gmp=${LOCALBASE} \
			--with-mpfr=${LOCALBASE} \
			--enable-targets=all
INFO=		as \
		binutils \
		gprof \
		bfd \
		ld
.endif

CONFIGURE_ARGS+=	--disable-werror \
			--enable-deterministic-archives \
			--with-sysroot=/ \
			--enable-x86-relax-relocations=no
RELRO_CONFIGURE_ON=	--enable-relro
RELRO_CONFIGURE_OFF=	--enable-relro=no

MAKE_ENV+=	ac_cv_func_sbrk=0

OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

# Actual earliest version may differ slightly
.if ${ARCH} != powerpc && ${ARCH} != powerpc64 && ${ARCH} != ia64 && ${ARCH} != i386 && ${ARCH} != mips && ${ARCH} != mips64 && !defined(PKGNAMEPREFIX) && (${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 34 || ${COMPILER_TYPE} == gcc)
CONFIGURE_ARGS+=	--enable-gold --enable-plugins
PLIST_SUB+=	GOLD=""
.else
PLIST_SUB+=	GOLD="@comment "
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

post-install:
.if !defined(PKGNAMEPREFIX)
	${INSTALL_DATA} ${WRKSRC}/include/plugin-api.h ${STAGEDIR}${PREFIX}/include/
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${CONFIGURE_TARGET} ! -type d | \
		${SED} -e 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	${RM} ${STAGEDIR}${PREFIX}/include/ansidecl.h
	${REINPLACE_CMD} '/#include "ansidecl.h"/d' ${STAGEDIR}${PREFIX}/include/bfd.h
.else
.if ${PKGNAMEPREFIX:S/-$//} != ${BUTARGET}
	${RM} -r ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}
.endif
	@if [ -d ${STAGEDIR}${PREFIX}/${INFO_PATH} ] ; then rm -rf ${STAGEDIR}${PREFIX}/${INFO_PATH}; fi
	${LN} -fs ../../bin/${BUTARGET}-size ${STAGEDIR}${PREFIX}/${BUTARGET}/bin/size
.endif
.for tool in ${BUREMOVE}
	@${RM} ${STAGEDIR}${PREFIX}/bin/${BUTARGET}-${tool} \
	    ${STAGEDIR}${PREFIX}/man/man1/${BUTARGET}-${tool}.1 \
	    ${STAGEDIR}${PREFIX}/${BUTARGET}/bin/${tool}
.endfor
.if defined(BUREMOVE) && ${BUREMOVE:Mld}
	@${RM} -r ${STAGEDIR}${PREFIX}/${BUTARGET}/lib/ldscripts
.endif

.include <bsd.port.post.mk>
