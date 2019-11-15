# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.33.1
PORTEPOCH?=	1
CATEGORIES?=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases

MAINTAINER?=	bapt@FreeBSD.org
COMMENT?=	GNU binary tools

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

FLAVORS=	native aarch64 aarch64_none_elf amd64 arm_gnueabi arm_none_eabi \
		avr i386 mingw32 mips mips64 powerpc64 riscv64 s390x sparc64
FLAVOR?=	native

RELRO_CONFIGURE_ON=	--enable-relro
BUILD_DEPENDS=	${LOCALBASE}/lib/libgmp.so:math/gmp \
		${LOCALBASE}/lib/libmpfr.so:math/mpfr

CONFLICTS=	libbfd-[0-9]*

#TEST_DEPENDS+=	runtest:misc/dejagnu
TEST_TARGET=	check

OPTIONS_DEFINE=	NLS RELRO STATIC
STATIC_PREVENTS=	NLS

RELRO_DESC=	enable -z relro in ELF linker by default

LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING3.LIB

USES=		bison:alias cpe gmake libtool tar:bzip2 compiler:env
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes

RELRO_CONFIGURE_OFF=	--enable-relro=no
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

STATIC_LDFLAGS+=	-all-static

aarch64_COMMENT=	GNU binutils for ${FLAVOR} development

.if ${FLAVOR} != native
PKGNAMEPREFIX=	${FLAVOR:C/_/-/g}-
PLIST=		${PKGDIR}/pkg-plist-${FLAVOR:C/_/-/g}

.if ${PKGNAMEPREFIX:M*-*-}
BUTARGET?=	${PKGNAMEPREFIX}${OPSYS:tl}${OSREL}
.else
BUTARGET?=	${PKGNAMEPREFIX}unknown-${OPSYS:tl}${OSREL}
.endif
PLIST_SUB=	BUTARGET=${BUTARGET}
OPTIONS_EXCLUDE=	NLS
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/share/info

.if ${FLAVOR} == aarch64
BROKEN_mips=		fails to configure: error: C compiler cannot create executables
BROKEN_mips64=		fails to configure: error: C compiler cannot create executables
BROKEN_powerpc64=	fails to configure: error: C compiler cannot create executables
.elif ${FLAVOR} == aarch64_none_elf || ${FLAVOR} == arm_none_eabi || ${FLAVOR} == mingw32 || ${FLAVOR} == avr
BUTARGET=	${FLAVOR:C/_/-/g}
.elif ${FLAVOR} == amd64
BUTARGET=	x86_64-unknown-${OPSYS:tl}${OSREL}
.endif

CONFIGURE_ARGS+=	--disable-shared \
			--target=${BUTARGET}
.endif

.if ${FLAVOR} == native
BUREMOVE=	coffdump \
		dlltool \
		dllwrap \
		nlmconv \
		srconv \
		sysdump \
		windmc \
		windres
USES+=		localbase
CONFIGURE_ARGS+=	--with-system-zlib \
			--with-gmp=${LOCALBASE} \
			--with-mpfr=${LOCALBASE} \
			--enable-targets=all \
			--enable-threads=yes
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

MAKE_ENV+=	ac_cv_func_sbrk=0
MAKE_ARGS+=	LIBDL=""

.include <bsd.port.pre.mk>

# Actual earliest version may differ slightly
.if ${ARCH} != sparc64 && ${ARCH} != mips && ${ARCH} != mips64 && ${ARCH} != powerpc && ${ARCH} != powerpc64 && ${ARCH} != powerpcspe && !defined(PKGNAMEPREFIX)
CONFIGURE_ARGS+=	--enable-gold --enable-plugins
CXXFLAGS+=	-Wno-c++11-narrowing
PLIST_SUB+=	GOLD=""
.else
PLIST_SUB+=	GOLD="@comment "
.endif

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.elif ${ARCH} == powerpcspe
CONFIGURE_TARGET=	powerpc-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

post-patch:
	${REINPLACE_CMD} -e "s/-ldl//g" ${WRKSRC}/gold/testsuite/Makefile.in

post-install:
.if ${FLAVOR} == native
	${INSTALL_DATA} ${WRKSRC}/include/plugin-api.h ${STAGEDIR}${PREFIX}/include/
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${CONFIGURE_TARGET} ! -type d | \
		${SED} -e 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	${RM} ${STAGEDIR}${PREFIX}/include/ansidecl.h
	${REINPLACE_CMD} '/#include "ansidecl.h"/d' ${STAGEDIR}${PREFIX}/include/bfd.h
.else
.if ${PKGNAMEPREFIX:S/-$//} != ${BUTARGET}
	${RM} -r ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}
.endif
	${RM} ${STAGEDIR}${PREFIX}/${BUTARGET}/lib/ldscripts/i386bsd.*
	@if [ -d ${STAGEDIR}${PREFIX}/${INFO_PATH:H} ] ; then rm -rf ${STAGEDIR}${PREFIX}/${INFO_PATH:H}; fi
	${LN} -fs ../../bin/${BUTARGET}-size ${STAGEDIR}${PREFIX}/${BUTARGET}/bin/size
.endif
.for tool in ${BUREMOVE}
	@${RM} ${STAGEDIR}${PREFIX}/bin/${BUTARGET}-${tool} \
	    ${STAGEDIR}${PREFIX}/bin/${tool} \
	    ${STAGEDIR}${MANPREFIX}/man/man1/${BUTARGET}-${tool}.1 \
	    ${STAGEDIR}${MANPREFIX}/man/man1/${tool}.1 \
	    ${STAGEDIR}${PREFIX}/${BUTARGET}/bin/${tool}
.endfor
.if defined(BUREMOVE) && ${BUREMOVE:Mld}
	@${RM} -r ${STAGEDIR}${PREFIX}/${BUTARGET}/lib/ldscripts
.endif

.include <bsd.port.post.mk>
