PORTNAME=	binutils
DISTVERSION=	2.40
PORTREVISION=	7
PORTEPOCH?=	1
CATEGORIES?=	devel
MASTER_SITES=	GNU \
		SOURCEWARE/binutils/releases

MAINTAINER?=	cy@FreeBSD.org
COMMENT?=	GNU binary tools
WWW=		https://www.gnu.org/software/binutils/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING3.LIB

BUILD_DEPENDS=	${LOCALBASE}/lib/libgmp.so:math/gmp \
		${LOCALBASE}/lib/libmpfr.so:math/mpfr

LIB_DEPENDS=	libzstd.so:archivers/zstd

FLAVORS=	native aarch64 aarch64_none_elf amd64 arm_gnueabi arm_none_eabi \
		avr i386 mingw32 mips mips64 powerpc powerpc64 powerpc64le riscv64 \
		riscv64_none_elf s390x riscv32_unknown_elf
FLAVOR?=	native

USES=		bison:alias compiler:env cpe gmake localbase libtool perl5 pkgconfig tar:lz
CPE_VENDOR=	gnu
USE_PERL5=	build
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-werror \
			--enable-deterministic-archives \
			--with-sysroot=/ \
			--enable-x86-relax-relocations=no \
			--with-zstd \
			--enable-default-compressed-debug-sections-algorithm=zstd
MAKE_ARGS+=	LIBDL="" V=1
MAKE_ENV+=	ac_cv_func_sbrk=0

# Some versioned symbols in libctf are undefined when libctf-nobfd.so is linked.
# Suppress errors with lld >= 17 due to these undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

# Tests will always fail because --compress-debug-sections is always set to
# zlib-gabi regardless of the compression setting by ./configure.
# TEST_TARGET=	check

CONFLICTS=	libbfd

OPTIONS_DEFINE=	INFO NLS RELRO
OPTIONS_DEFAULT=	INFO
OPTIONS_EXCLUDE=	NLS
OPTIONS_SUB=	yes

INFO_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-no-info
INFO_USES=	makeinfo
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
RELRO_CONFIGURE_ON=	--enable-relro
RELRO_CONFIGURE_OFF=	--enable-relro=no
RELRO_DESC=	Enable relocation memory corruption mitigation (-z relro) by default

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
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/share/info

.if ${FLAVOR} == aarch64
BROKEN_mips=		fails to configure: error: C compiler cannot create executables
BROKEN_mips64=		fails to configure: error: C compiler cannot create executables
.elif ${FLAVOR} == aarch64_none_elf || ${FLAVOR} == arm_none_eabi || ${FLAVOR} == riscv64_none_elf || ${FLAVOR} == mingw32 || ${FLAVOR} == avr || ${FLAVOR} == riscv32_unknown_elf
BUTARGET=	${FLAVOR:C/_/-/g}
.elif ${FLAVOR} == amd64
BUTARGET=	x86_64-unknown-${OPSYS:tl}${OSREL}
.endif

.if ${FLAVOR} == mingw32
USES+=		iconv
.endif

CONFIGURE_ARGS+=	--target=${BUTARGET}
.endif

.if ${FLAVOR} == native
CONFIGURE_ARGS+=	--enable-shared
PLIST_SUB+=		SHARED=''
.else
CONFIGURE_ARGS+=	--disable-shared
PLIST_SUB+=		SHARED='@comment'
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
# XXX Needed to support gcc10 and earlier:
CONFIGURE_ARGS+=	--with-isa-spec=2.2
INFO_INFO=	as \
		binutils \
		ctf-spec \
		gprof \
		bfd \
		ld \
		sframe-spec
.endif

.include <bsd.port.pre.mk>

# Actual earliest version may differ slightly
.if (${ARCH} != mips && ${ARCH} != mips64 && ${ARCH} != powerpcspe && ${ARCH} != powerpc && ${ARCH} != powerpc64 && ${ARCH} != riscv64 && !defined(PKGNAMEPREFIX)) || ((${ARCH} == powerpc || ${ARCH} == powerpc64) && ${CHOSEN_COMPILER_TYPE} != gcc && !defined(PKGNAMEPREFIX))
CONFIGURE_ARGS+=	--enable-gold --enable-plugins
CXXFLAGS+=	-Wno-c++11-narrowing
PLIST_SUB+=	GOLD=""
.else
PLIST_SUB+=	GOLD="@comment "
.endif

.if (${FLAVOR} == native && ${OPSYS} == FreeBSD) || \
    (${FLAVOR} != native && ${BUTARGET:M*freebsd*})
CONFIGURE_ARGS+=	--enable-new-dtags
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
# Force the generation of man pages
	${RM} ${WRKSRC}/binutils/doc/*.1
	${RM} ${WRKSRC}/gas/doc/*.1
	${RM} ${WRKSRC}/gprof/*.1
	${RM} ${WRKSRC}/ld/*.1

post-install:
.if ${FLAVOR} == native
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/lib*.so* \
		${STAGEDIR}${PREFIX}/lib/bfd-plugins/libdep.so
	${INSTALL_DATA} ${WRKSRC}/include/plugin-api.h ${STAGEDIR}${PREFIX}/include/
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${CONFIGURE_TARGET} ! -type d | \
		${SED} -e 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
.else
.if ${PKGNAMEPREFIX:S/-$//} != ${BUTARGET}
	${RM} -r ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}
.endif
	${RM} ${STAGEDIR}${PREFIX}/${BUTARGET}/lib/ldscripts/i386bsd.*
	@if [ -d ${STAGEDIR}${PREFIX}/${INFO_PATH:H} ] ; then ${RM} -rf ${STAGEDIR}${PREFIX}/${INFO_PATH:H}; fi
	${LN} -fs ../../bin/${BUTARGET}-size ${STAGEDIR}${PREFIX}/${BUTARGET}/bin/size
	${RM} -r ${STAGEDIR}${PREFIX}/lib/bfd-plugins
.endif
.for tool in ${BUREMOVE}
	@${RM} ${STAGEDIR}${PREFIX}/bin/${BUTARGET}-${tool} \
	    ${STAGEDIR}${PREFIX}/bin/${tool} \
	    ${STAGEDIR}${PREFIX}/share/man/man1/${BUTARGET}-${tool}.1 \
	    ${STAGEDIR}${PREFIX}/share/man/man1/${tool}.1 \
	    ${STAGEDIR}${PREFIX}/${BUTARGET}/bin/${tool}
.endfor
.if defined(BUREMOVE) && ${BUREMOVE:Mld}
	@${RM} -r ${STAGEDIR}${PREFIX}/${BUTARGET}/lib/ldscripts
.endif

.include <bsd.port.post.mk>
