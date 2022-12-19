PORTNAME=	gnat12
PORTVERSION=	12.2.0
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC}:gcc	\
		LOCAL/thierry:gnat
MASTER_SITE_SUBDIR=releases/gcc-${PORTVERSION}
DISTFILES=	gcc-${PORTVERSION}.tar.xz:gcc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	GNAT Ada compiler
WWW=		https://www.adacore.com/community

LICENSE=	GPLv2 GPLv3 GPLv3RLE
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:math/gmp	\
		libmpc.so:math/mpc	\
		libisl.so:devel/isl	\
		libmpfr.so:math/mpfr

USES=		bison gettext-runtime gmake iconv libtool localbase tar:xz
USE_BINUTILS=	yes
BINARY_ALIAS=	make=${GMAKE}

OPTIONS_DEFINE=	ASSETS
OPTIONS_RADIO=	BOOTSTRAP
OPTIONS_RADIO_BOOTSTRAP=	GCC6AUX	PREVASSET
OPTIONS_DEFAULT=GCC6AUX
.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	ASSETS
.endif
OPTIONS_SUB=	yes
ASSETS_DESC=	Build an asset for future bootstrap on the target platform
GCC6AUX_DESC=	Bootstrap from lang/gcc6-aux
PREVASSET_DESC=	Bootstrap from the previous asset (if available)

GCC6AUX_BUILD_DEPENDS=	gcc6-aux>0:lang/gcc6-aux
PREVASSET_DISTFILES+=	${PREV_ASSET_FILE}.tar.xz:gnat

GCC6AUX_VARS=	PATHAUX=${LOCALBASE}/gcc6-aux/bin
PREVASSET_VARS=	PATHAUX=${WRKDIR}/${PREV_ASSET_FILE}/bin
ASSETS_VARS=	PKGMESSAGE=${WRKDIR}/pkg-message

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
WRKSRC=		${WRKDIR}/gcc-${PORTVERSION}
PKG_PREFIX=	${PREFIX}/${PORTNAME}
FULLPATH=	/sbin:/bin:/usr/sbin:/usr/bin:${PATHAUX}:${PREFIX}/bin:${LOCALBASE}/bin
TARGLIB=	${PKG_PREFIX}/lib/gcc${GCCVER}
GNU_CONFIGURE_PREFIX=	${PKG_PREFIX}
GNU_CONFIGURE_MANPREFIX=${PKG_PREFIX}
MANPREFIX=	${PKG_PREFIX}
CONFIGURE_ENV+=	PATH=${FULLPATH}	\
		CC=${PATHAUX}/gcc	\
		CXX=${PATHAUX}/g++
CONFIGURE_ARGS=	--enable-languages="c,ada"	\
		--with-pkgversion="${OPSYS} Ports Collection"	\
		--enable-gnu-indirect-function	\
		--with-as=${LOCALBASE}/bin/as	\
		--with-ld=${LOCALBASE}/bin/ld	\
		--enable-threads=posix	\
		--disable-libquadmath	\
		--enable-host-shared	\
		--disable-libmudflap	\
		--with-system-zlib	\
		--disable-libgomp	\
		--disable-libssp	\
		--enable-libada		\
		--without-zstd
CONFIGURE_TARGET=	${GARCH}-portbld-${PLATFORM}

MAKE_ENV+=	PATH=${FULLPATH}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	${TARGLIB}

GNATMAKE=	${PATHAUX}/gnatmake
GNATBING=	${PATHAUX}/gnatbind

GCCVER=		${PORTVERSION:R:R}

PLATFORM=	${OPSYS:tl}${OSREL}
GARCH=		${ARCH:S/amd64/x86_64/}
OS_LABEL4VERS=	[${OPSYS}${GARCH:S/amd//:S/x86_//:S/aarch/\/ARM/:S/i386/32/}]
REVFILE=	${WRKSRC}/gcc/REVISION
PHASEFILE=	${WRKSRC}/gcc/DEV-PHASE
ASSET_FILE=	gnat-${GARCH}-${OPSYS:tl}.${OSREL:R}-${PKGVERSION}
PREV_ASSET_VER?=	${PORTVERSION}
PREV_ASSET_REV?=	_2
PREV_ASSET_GCC=	${PREV_ASSET_VER:R:R}
PREV_ASSET_OSREL?=	${OSREL:R}
PREV_ASSET_FILE=gnat-${GARCH}-${OPSYS:tl}.${PREV_ASSET_OSREL}-${PREV_ASSET_VER}${PREV_ASSET_REV}

PLIST_SUB=	CONFTRGT=${CONFIGURE_TARGET} VER=${PORTVERSION}	\
		ASSET_FILE=${ASSET_FILE}
# add-plist-info does not honor GNU_CONFIGURE_PREFIX => remove INFO files
INFOS=		cpp cppinternals gcc gccinstall gccint gnat_rm gnat_ugn	\
		gnat-style libitm

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
LIB_DIR_32=	""
PLIST_SUB+=	64BITS="@comment "
.else
LIB_DIR_32=	"" 32
PLIST_SUB+=	64BITS=""
.endif

pre-configure:
	${ECHO} "-=> GNAT ${OS_LABEL4VERS}" > ${REVFILE}
	${ECHO} "release" > ${PHASEFILE}

post-install-ASSETS-on:
	${MKDIR} ${WRKDIR}/${ASSET_FILE} ${STAGEDIR}${DATADIR}/assets
	${CP} -Rp ${STAGEDIR}${PKG_PREFIX}/* ${WRKDIR}/${ASSET_FILE}
	(cd ${WRKDIR} &&	\
		${TAR} cfJ ${STAGEDIR}${DATADIR}/assets/${ASSET_FILE}.tar.xz ${ASSET_FILE})

post-stage:
	${RM} -rf ${STAGEDIR}${PKG_PREFIX}/share/info
.for d in ${LIB_DIR_32}
.  for l in libgnarl-${GCCVER} libgnat-${GCCVER}
	${STRIP_CMD}	\
		${STAGEDIR}${PKG_PREFIX}/lib/gcc/${CONFIGURE_TARGET}/${PORTVERSION}/${d}/adalib/${l}.so
.  endfor
	${STRIP_CMD} ${STAGEDIR}${PKG_PREFIX}/lib${d}/libgcc_s.so.1
.endfor

post-stage-ASSETS-on:
	@${ECHO_CMD} "The file ${DATADIR}/assets/${ASSET_FILE}.tar.xz has been created"	\
		> ${PKGMESSAGE}
	@${ECHO_CMD} "You may want to copy it under ${DISTDIR} to use the option PREVASSET next time."	\
		>> ${PKGMESSAGE}
	@${ECHO_CMD} "(and adjust distinfo)"	\
		>> ${PKGMESSAGE}

.include <bsd.port.post.mk>
