PORTNAME=	gnat12
PORTVERSION=	12.2.0
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

IGNORE=	does not run without gcc12 built from this port

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
FULLPATH=	/sbin:/bin:/usr/sbin:/usr/bin:${PATHAUX}:${PREFIX}/bin:${LOCALBASE}/bin
TARGLIB=	${PREFIX}/lib/gcc${GCCVER}
TARGLIB32=	${PREFIX}/lib32
LIBEXEC=	${PREFIX}/libexec/gcc${GCCVER}
CONFIGURE_ENV+=	PATH=${FULLPATH}	\
		CC=${PATHAUX}/gcc	\
		CXX=${PATHAUX}/g++
CONFIGURE_ARGS=	--enable-languages="c,ada"	\
		--with-pkgversion="${OPSYS} Ports Collection"	\
		--with-gxx-include-dir=${TARGLIB}/include/c++/	\
		--with-gxx-libcxx-include-dir=/usr/include/c++/v1 \
		--enable-gnu-indirect-function	\
		--with-as=${LOCALBASE}/bin/as	\
		--with-ld=${LOCALBASE}/bin/ld	\
		--program-suffix=${GCCVER}	\
		--libexecdir=${LIBEXEC}	\
		--libdir=${TARGLIB}	\
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
PREV_ASSET_OSREL?=	${OSREL:R}
PREV_ASSET_FILE=gnat-${GARCH}-${OPSYS:tl}.${PREV_ASSET_OSREL}-${PREV_ASSET_VER}

PLIST_SUB=	CONFTRGT=${CONFIGURE_TARGET} VER=${PORTVERSION}	\
		ASSET_FILE=${ASSET_FILE}
INFO=		gnat-style	\
		gnat_rm		\
		gnat_ugn

pre-configure:
	${ECHO} "-=> GNAT ${OS_LABEL4VERS}" > ${REVFILE}
	${ECHO} "release" > ${PHASEFILE}

pre-configure-PREVASSET-on:
	cd ${PATHAUX} ; for f in *${PREV_ASSET_VER} ; do	\
	${LN} -sf $${f} $${f%${PREV_ASSET_VER}} ;			\
	done

post-install-ASSETS-on:
	${MKDIR} ${WRKDIR}/${ASSET_FILE} ${STAGEDIR}${DATADIR}/assets
	${CP} -Rp ${STAGEDIR}${PREFIX}/* ${WRKDIR}/${ASSET_FILE}
	(cd ${WRKDIR} &&	\
		${TAR} cfJ ${STAGEDIR}${DATADIR}/assets/${ASSET_FILE}.tar.xz ${ASSET_FILE})

post-stage:
.for d in "" 32
.  for l in libgnarl-${GCCVER} libgnat-${GCCVER}
	${STRIP_CMD}	\
		${STAGEDIR}${PREFIX}/lib/gcc${GCCVER}/gcc/${CONFIGURE_TARGET}/${PORTVERSION}/${d}/adalib/${l}.so
.  endfor
.endfor
	${CP} -p ${STAGEDIR}${PREFIX}/libexec/gcc${GCCVER}/gcc/${CONFIGURE_TARGET}/${PORTVERSION}/gnat1	\
		${WRKDIR}
	# avoid conflict with lang/gcc${GCCVER}
	${ECHO} "${RM} -rf " > ${WRKDIR}/avoid_conflict.sh
	${CAT} ${FILESDIR}/avoid_conflict >> ${WRKDIR}/avoid_conflict.sh
	${SED} -i"" -e 's|$$| \\|;s|%%CONFTRGT%%|${CONFIGURE_TARGET}|;	\
		s|%%VER%%|${PORTVERSION}|' ${WRKDIR}/avoid_conflict.sh
	(cd ${STAGEDIR}${PREFIX} && ${SH} ${WRKDIR}/avoid_conflict.sh)
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gcc${GCCVER}/gcc/${CONFIGURE_TARGET}/${PORTVERSION}
	${MV} ${WRKDIR}/gnat1	\
		${STAGEDIR}${PREFIX}/libexec/gcc${GCCVER}/gcc/${CONFIGURE_TARGET}/${PORTVERSION}

post-stage-ASSETS-on:
	@${ECHO_CMD} "The file ${DATADIR}/assets/${ASSET_FILE}.tar.xz has been created"	\
		> ${PKGMESSAGE}
	@${ECHO_CMD} "You may want to copy it under ${DISTDIR} to use the option PREVASSET next time."	\
		>> ${PKGMESSAGE}

.include <bsd.port.mk>
