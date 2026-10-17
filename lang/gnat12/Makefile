PORTNAME=	gnat12
DISTVERSION=	12.4.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC:C|%SUBDIR%|${MASTER_SITE_SUBDIR}|}:gcc \
		LOCAL/thierry:gnat
MASTER_SITE_SUBDIR=	releases/gcc-${DISTVERSION}
DISTFILES=	gcc-${DISTVERSION}.tar.xz:gcc

MAINTAINER=	ada@FreeBSD.org
COMMENT=	GNAT (GNU Ada) compiler
WWW=		https://www.gnu.org/software/gnat/

LICENSE=	GPLv2 GPLv3+ GPLv3RLE+ LGPL21 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING3
LICENSE_FILE_GPLv3RLE+ =	${WRKSRC}/COPYING.RUNTIME
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING3.LIB

BUILD_DEPENDS=	gcc${_GCC_VER}>0:lang/gcc${_GCC_VER}
LIB_DEPENDS=	libgmp.so:math/gmp \
		libisl.so:devel/isl \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	${LOCALBASE}/bin/as:devel/binutils \
		gcc${_GCC_VER}>0:lang/gcc${_GCC_VER}

USES=		bison gettext-runtime gmake iconv libtool localbase tar:xz
USE_BINUTILS=	yes
USE_LDCONFIG=	${_TARGLIB}

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=	${_PKG_PREFIX}/share
GNU_CONFIGURE_PREFIX=	${_PKG_PREFIX}
CONFIGURE_ARGS=		--disable-bootstrap \
			--disable-libmudflap \
			--disable-libquadmath \
			--disable-libssp \
			--enable-gnu-indirect-function \
			--enable-host-shared \
			--enable-languages="ada,c,c++" \
			--enable-libada \
			--enable-threads=posix \
			--with-as=${LOCALBASE}/bin/as \
			--with-ld=${LOCALBASE}/bin/ld \
			--with-pkgversion="${OPSYS} Ports Collection" \
			--with-system-zlib \
			--without-zstd
CONFIGURE_ENV+=		CC=${_GCC6AUX_PATH}/gcc \
			CXX=${_GCC6AUX_PATH}/g++ \
			PATH=${_TOOLCHAIN_PATHS}
CONFIGURE_OUTSOURCE=	yes

MAKE_ENV+=	PATH=${_TOOLCHAIN_PATHS}
INSTALL_TARGET=	install-strip

PIE_UNSAFE=	yes

MANDIRS=	${_PKG_PREFIX}/share/man
BINARY_ALIAS=	make=${GMAKE}

WRKSRC=		${WRKDIR}/gcc-${DISTVERSION}

PLIST_SUB=	ASSET_FILE=${_ASSET_FILE} \
		CONFTRGT=${CONFIGURE_TARGET} \
		GNAT=${PORTNAME} \
		GNAT_SO_VERSION=${_GCC_VER:R} \
		VER=${DISTVERSION}

OPTIONS_DEFINE=			ASSETS NLS
.if exists(/usr/lib32/libc.so)
OPTIONS_DEFINE_amd64+=	MULTILIB
OPTIONS_DEFINE_powerpc64+=	MULTILIB
.endif
OPTIONS_RADIO=			BOOTSTRAP
OPTIONS_RADIO_BOOTSTRAP=	GCC6AUX PREVASSET
OPTIONS_DEFAULT=		PREVASSET
.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=		ASSETS
.endif
.if exists(/usr/lib32/libc.so)
OPTIONS_DEFAULT_amd64+=	MULTILIB
#OPTIONS_DEFAULT_powerpc64+=	MULTILIB # https://gcc.gnu.org/bugzilla/show_bug.cgi?id=105010
.endif
OPTIONS_SUB=			yes

ASSETS_DESC=	Build an asset for future bootstrap on the target platform
GCC6AUX_DESC=	Bootstrap from lang/gcc6-aux
.if exists(/usr/lib32/libc.so)
MULTILIB_DESC=	Build support for 32-bit and 64-bit targets
.endif
PREVASSET_DESC=	Bootstrap from the previous asset (if available)

ASSETS_VARS=			PKGMESSAGE=${WRKDIR}/pkg-message
GCC6AUX_BUILD_DEPENDS=		gcc6-aux>0:lang/gcc6-aux
GCC6AUX_VARS=			_GCC6AUX_PATH=${LOCALBASE}/gcc6-aux/bin
.if exists(/usr/lib32/libc.so)
MULTILIB_CONFIGURE_ENABLE=	multilib
.else
CONFIGURE_ARGS+=		--disable-multilib
.endif
NLS_CONFIGURE_ON=		--enable-nls
NLS_CONFIGURE_OFF=		--disable-nls
PREVASSET_DISTFILES+=		${_PREV_ASSET_FILE}.tar.xz:gnat
PREVASSET_VARS=			_GCC6AUX_PATH=${WRKDIR}/${_PREV_ASSET_FILE}/bin

_ASSET_FILE=		gnat-${_GNAT_ARCH}-${OPSYS:tl}.${OSREL:R}-${PKGVERSION}
_GCC_VER=		${DISTVERSION:R:R}
_GNATBIND=		${_GCC6AUX_PATH}/gnatbind
_GNATMAKE=		${_GCC6AUX_PATH}/gnatmake
_GNAT_ARCH=		${ARCH:S/amd64/x86_64/}
_OS_LABEL4VERS=		[${OPSYS}${_GNAT_ARCH:S/amd//:S/x86_//:S/aarch/\/ARM/:S/i386/32/}]
_PHASE_FILE=		${WRKSRC}/gcc/DEV-PHASE
_PKG_PREFIX=		${PREFIX}/${PORTNAME}
_PREV_ASSET_FILE=	gnat-${_GNAT_ARCH}-${OPSYS:tl}.${_PREV_ASSET_OSREL}-${_PREV_ASSET_VER}${_PREV_ASSET_REV}
_PREV_ASSET_GCC=	${PREV_ASSET_VER:R:R}
_PREV_ASSET_OSREL?=	${OSREL:R}
_PREV_ASSET_REV?=	_1
_PREV_ASSET_VER?=	12.3.0
_REV_FILE=		${WRKSRC}/gcc/REVISION
_TARGLIB=		${_PKG_PREFIX}/lib ${_PKG_PREFIX}/lib/gcc${_GCC_VER}
_TOOLCHAIN_PATHS=	/sbin:/bin:/usr/sbin:/usr/bin:${_GCC6AUX_PATH}:${PREFIX}/bin:${LOCALBASE}/bin

.include <bsd.port.pre.mk>

.if ${UID} != 0
BINMODE=	755
.endif

.if ${ARCH} == i386
LIB_DIR_32=	""
PLIST_SUB+=	LIB32="@comment "
.else
.  if empty(PORT_OPTIONS:MMULTILIB)
LIB_DIR_32=	""
PLIST_SUB+=	LIB32="@comment "
.  else
LIB_DIR_32=	"" 32
PLIST_SUB+=	LIB32=" "
.  endif
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	64BIT=" " \
		AARCH64="@comment " \
		AMD64=" " \
		X86=" "
.elif ${ARCH} == i386
PLIST_SUB+=	64BIT="@comment " \
		AARCH64="@comment " \
		AMD64="@comment " \
		X86=" "
.elif ${ARCH} == aarch64
PLIST_SUB+=	64BIT=" " \
		AARCH64=" " \
		AMD64="@comment " \
		X86="@comment "
.endif

pre-configure:
	${FIND} ${WRKSRC}/gcc/config -name "*freebsd.h" -o -name "*freebsd64.h" | \
		${XARGS} ${REINPLACE_CMD} -e 's|!static:[[:blank:]]|!static: --hash-style=gnu -rpath ${PREFIX}/gnat${_GCC_VER}/lib |'
	${ECHO} "-=> GNAT ${_OS_LABEL4VERS}" > ${_REV_FILE}
	${ECHO} "release" > ${_PHASE_FILE}

post-install-ASSETS-on:
	${MKDIR} ${WRKDIR}/${_ASSET_FILE} \
		${STAGEDIR}${DATADIR}/assets
	${CP} -Rp ${STAGEDIR}${_PKG_PREFIX}/* ${WRKDIR}/${_ASSET_FILE}
	(cd ${WRKDIR} && \
		${TAR} cfJ ${STAGEDIR}${DATADIR}/assets/${_ASSET_FILE}.tar.xz \
		--options='xz:threads=${MAKE_JOBS_NUMBER}' ${_ASSET_FILE})

post-stage:
# add-plist-info does not honor GNU_CONFIGURE_PREFIX so remove INFO files
	${RM} -rf ${STAGEDIR}${_PKG_PREFIX}/share/info
.for d in ${LIB_DIR_32}
.  for l in libgnarl-${_GCC_VER} libgnat-${_GCC_VER}
	${STRIP_CMD} ${STAGEDIR}${_PKG_PREFIX}/lib/gcc/${CONFIGURE_TARGET}/${DISTVERSION}/${d}/adalib/${l}.so
.  endfor
	${STRIP_CMD} ${STAGEDIR}${_PKG_PREFIX}/lib${d}/libgcc_s.so.1
.endfor

post-stage-ASSETS-on:
	${ECHO_CMD} "[" > ${PKGMESSAGE}
	${ECHO_CMD} "{" >> ${PKGMESSAGE}
	${ECHO_CMD} "  type: install" >> ${PKGMESSAGE}
	${ECHO_CMD} "  message: <<EOM" >> ${PKGMESSAGE}
	${ECHO_CMD} "The option ASSETS was enabled for the build and the following asset," \
		>> ${PKGMESSAGE}
	${ECHO_CMD} "${DATADIR}/assets/${_ASSET_FILE}.tar.xz was installed." \
		>> ${PKGMESSAGE}
	${ECHO_CMD} "If you would like to use this asset in future you will need to copy" \
		>> ${PKGMESSAGE}
	${ECHO_CMD} "it under ${DISTDIR}, update the Port's distinfo, and make sure the " \
		>> ${PKGMESSAGE}
	${ECHO_CMD} "option PREVASSET is enabled." >> ${PKGMESSAGE}
	${ECHO_CMD} "See ports(7) and make.conf(5) for details on ${DISTDIR} and using" \
		>> ${PKGMESSAGE}
	${ECHO_CMD} "makesum to update distinfo." >> ${PKGMESSAGE}
	${ECHO_CMD} "EOM" >> ${PKGMESSAGE}
	${ECHO_CMD} "}" >> ${PKGMESSAGE}
	${ECHO_CMD} "]" >> ${PKGMESSAGE}

.include <bsd.port.post.mk>
