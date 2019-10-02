# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.32
PORTREVISION=	1
PORTEPOCH?=	1
CATEGORIES?=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases

MAINTAINER?=	bapt@FreeBSD.org
COMMENT?=	GNU binary tools

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

.if defined(PREFIX) && ${PREFIX} != "/usr"
BUILD_DEPENDS=	${LOCALBASE}/lib/libgmp.so:math/gmp \
		${LOCALBASE}/lib/libmpfr.so:math/mpfr

CONFLICTS=	libbfd-[0-9]*
.endif

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

.if defined(PKGNAMEPREFIX)
.if ${PKGNAMEPREFIX:M*-*-}
BUTARGET?=	${PKGNAMEPREFIX}${OPSYS:tl}${OSREL}
.else
BUTARGET?=	${PKGNAMEPREFIX}unknown-${OPSYS:tl}${OSREL}
.endif
PLIST_SUB=	BUTARGET=${BUTARGET}
OPTIONS_EXCLUDE=	NLS
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/share/info
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
RELRO_CONFIGURE_ON=	--enable-relro
RELRO_CONFIGURE_OFF=	--enable-relro=no

MAKE_ENV+=	ac_cv_func_sbrk=0
MAKE_ARGS+=	LIBDL=""

OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

STATIC_LDFLAGS+=	-all-static

.include <bsd.port.pre.mk>

# Actual earliest version may differ slightly
.if ${ARCH} != sparc64 && ${ARCH} != mips && ${ARCH} != mips64 && ${ARCH} != powerpc && ${ARCH} != powerpc64 && ${ARCH} != powerpcspe && !defined(PKGNAMEPREFIX)
CONFIGURE_ARGS+=	--enable-gold --enable-plugins
CXXFLAGS+=	-Wno-c++11-narrowing
PLIST_SUB+=	GOLD=""
.else
PLIST_SUB+=	GOLD="@comment "
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.elif ${ARCH} == "powerpcspe"
CONFIGURE_TARGET=	powerpc-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

post-patch:
	${REINPLACE_CMD} -e "s/-ldl//g" ${WRKSRC}/gold/testsuite/Makefile.in

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
	${RM} ${STAGEDIR}${PREFIX}/${BUTARGET}/lib/ldscripts/i386bsd.*
	@if [ -d ${STAGEDIR}${PREFIX}/${INFO_PATH:H} ] ; then rm -rf ${STAGEDIR}${PREFIX}/${INFO_PATH:H}; fi
	${LN} -fs ../../bin/${BUTARGET}-size ${STAGEDIR}${PREFIX}/${BUTARGET}/bin/size
.if ${PREFIX} == "/usr"
.if defined(CROSS_TOOLCHAIN)
	${MV} ${STAGEDIR}/usr/bin/as ${STAGEDIR}/usr/bin/${BUTARGET}-as
	${MV} ${STAGEDIR}/usr/bin/ld ${STAGEDIR}/usr/bin/${BUTARGET}-ld
	${MV} ${STAGEDIR}/usr/bin/ld.bfd ${STAGEDIR}/usr/bin/${BUTARGET}-ld.bfd
	${MV} ${STAGEDIR}/usr/bin/objcopy ${STAGEDIR}/usr/bin/${BUTARGET}-objcopy
	${MV} ${STAGEDIR}/usr/bin/objdump ${STAGEDIR}/usr/bin/${BUTARGET}-objdump
	${MV} ${STAGEDIR}/${MANDIR}1/as.1 ${STAGEDIR}/${MANDIR}1/${BUTARGET}-as.1
	${GZIP_CMD} ${STAGEDIR}/${MANDIR}1/${BUTARGET}-as.1
	${MV} ${STAGEDIR}/${MANDIR}1/ld.1 ${STAGEDIR}/${MANDIR}1/${BUTARGET}-ld.1
	${GZIP_CMD} ${STAGEDIR}/${MANDIR}1/${BUTARGET}-ld.1
	${MV} ${STAGEDIR}/${MANDIR}1/objcopy.1 ${STAGEDIR}/${MANDIR}1/${BUTARGET}-objcopy.1
	${GZIP_CMD} ${STAGEDIR}/${MANDIR}1/${BUTARGET}-objcopy.1
	${MV} ${STAGEDIR}/${MANDIR}1/objdump.1 ${STAGEDIR}/${MANDIR}1/${BUTARGET}-objdump.1
	${GZIP_CMD} ${STAGEDIR}/${MANDIR}1/${BUTARGET}-objdump.1
.endif
	${LN} -fs /usr/bin/${BUTARGET}-as ${STAGEDIR}/usr/bin/as
	${LN} -fs /usr/bin/${BUTARGET}-ld ${STAGEDIR}/usr/bin/ld
	${LN} -fs /usr/bin/${BUTARGET}-ld.bfd ${STAGEDIR}/usr/bin/ld.bfd
	${LN} -fs /usr/bin/${BUTARGET}-objcopy ${STAGEDIR}/usr/bin/objcopy
	${LN} -fs /usr/bin/${BUTARGET}-objdump ${STAGEDIR}/usr/bin/objdump
	${LN} -fs ${BUTARGET}-as.1.gz ${STAGEDIR}/${MANDIR}1/as.1.gz
	${LN} -fs ${BUTARGET}-ld.1.gz ${STAGEDIR}/${MANDIR}1/ld.1.gz
	${LN} -fs ${BUTARGET}-objcopy.1.gz ${STAGEDIR}/${MANDIR}1/objcopy.1.gz
	${LN} -fs ${BUTARGET}-objdump.1.gz ${STAGEDIR}/${MANDIR}1/objdump.1.gz
	@${RM} -r ${STAGEDIR}${PREFIX}/include
	@${RM} -r ${STAGEDIR}${PREFIX}/lib
.endif
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
