# $FreeBSD$
#
# bsd.ghc.mk -- Common code for various versions of GHC ports.
#
# Maintained by: haskell@FreeBSD.org
#

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386

GHC_VERSION_MAJOR=	${GHC_VERSION:S/./ /g:[1]}
GHC_VERSION_MINOR=	${GHC_VERSION:S/./ /g:[2]}

.if ${GHC_VERSION_MAJOR} >= 8 && ${GHC_VERSION_MINOR} >= 6
ONLY_FOR_ARCHS+=	powerpc64
.endif

DATADIR=	${PREFIX}/share/ghc-${GHC_VERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/ghc-${GHC_VERSION}

USES=		autoreconf gmake iconv:translit localbase:ldflags ncurses perl5 tar:xz
USE_LOCALE=	en_US.UTF-8
USE_PERL5=	build
NO_CCACHE=	ccache: error: Failed to create directory /nonexistent/.ccache/tmp: Permission denied

# The configure process accepts,filters and canonicalises
# the CONFIGURE_TARGET variable. You can read the files
# ${WRKSRC}/configure and ${WRKSRC}/config.sub.
# This is better fixed in files/build.mk.in
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=		--with-iconv-includes=${LOCALBASE}/include \
			--with-iconv-libraries=${LOCALBASE}/lib
# Turn off for a while, see PR 228727
CONFIGURE_ARGS+=	--enable-dtrace=0

SUB_FILES=		build.mk
SUB_LIST=		GHC_VERSION=${GHC_VERSION} \
			NCURSESINC="${NCURSESBASE}/include" NCURSESLIB="${NCURSESLIB}" \
			CFLAGS="${CFLAGS}"

OPTIONS_GROUP=		BOOTSTRAP
BOOTSTRAP_DESC=		Bootsrap using installed ghc
OPTIONS_GROUP_BOOTSTRAP=BOOT
OPTIONS_DEFINE=		DYNAMIC GMP PROFILE DOCS
OPTIONS_SUB=		yes

OPTIONS_DEFAULT=	DYNAMIC PROFILE GMP

BOOT_DESC=		Use installed GHC for bootstrapping
DOCS_DESC=		Install HTML documentation
DYNAMIC_DESC=		Add support for dynamic linking
GMP_DESC=		Use GNU Multi-precision Library for big integers support
PROFILE_DESC=		Add support for performance profiling

DOCS_BUILD_DEPENDS+=	sphinx-build:textproc/py-sphinx

DYNAMIC_CONFIGURE_WITH=	system-libffi \
			ffi-includes=${LOCALBASE}/include \
			ffi-libraries=${LOCALBASE}/lib
# The version number is needed as lang/gcc installs a different version
DYNAMIC_LIB_DEPENDS=	libffi.so.6:devel/libffi

GMP_CONFIGURE_WITH=	gmp-includes=${LOCALBASE}/include \
			gmp-libraries=${LOCALBASE}/lib
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

# Append substitutions for build.mk
BOOT_SUB_LIST=		HSC2HS=${LOCALBASE}/bin/hsc2hs
BOOT_SUB_LIST_OFF=	HSC2HS=${BOOT_HSC2HS}

DOCS_SUB_LIST=		WITH_DOCS="YES"
DOCS_SUB_LIST_OFF=	WITH_DOCS="NO"

DYNAMIC_SUB_LIST=	WITH_DYNAMIC="YES"
DYNAMIC_SUB_LIST_OFF=	WITH_DYNAMIC="NO"

GMP_SUB_LIST=		INTEGER_LIBRARY="integer-gmp"
GMP_SUB_LIST_OFF=	INTEGER_LIBRARY="integer-simple"

PROFILE_SUB_LIST=	WITH_PROFILE="YES"
PROFILE_SUB_LIST_OFF=	WITH_PROFILE="NO"

LOCALBASE?=	/usr/local
PLIST?=		${.CURDIR}/../../lang/ghc/pkg-plist

GHC_ARCH=		${ARCH:S/amd64/x86_64/:C/armv.*/arm/}

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MBOOT)
.  if ${ARCH} == armv6 || ${ARCH} == armv7
BOOT_GHC_VERSION=	8.4.2
.  elif ${ARCH} == powerpc64
BOOT_GHC_VERSION=	8.6.3
.  else
BOOT_GHC_VERSION=	8.4.3
.  endif

# When GHC being compiled and GHC used for bootstrapping support different
# LLVM versions, we have to pull in both. Luckily, this is relatively rare.
.  if ${ARCH} == aarch64 || ${ARCH} == armv6 || ${ARCH} == armv7
# LLVM version that bootstrap compiler uses
BOOT_LLVM_VERSION=	50

.    if ${BOOT_LLVM_VERSION} != ${LLVM_VERSION}
BUILD_DEPENDS+=		llc${BOOT_LLVM_VERSION}:devel/llvm${BOOT_LLVM_VERSION}
RUN_DEPENDS+=		llc${BOOT_LLVM_VERSION}:devel/llvm${BOOT_LLVM_VERSION}
.    endif
.  endif

DISTFILES+=		ghc-${BOOT_GHC_VERSION}-boot-${ARCH}-freebsd${EXTRACT_SUFX}:boot
.endif # MBOOT

.if ${ARCH} == aarch64 || ${ARCH} == armv6 || ${ARCH} == armv7
# CONFIGURE_TARGET must to be the same as the llvm triple
CONFIGURE_TARGET=	${ARCH}-unknown-freebsd${"${ARCH:Maarch64}" != "":?:-gnueabihf}
CONFIGURE_ENV+=		STRIP=${LOCALBASE}/bin/strip
EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-aclocal.m4
BUILD_DEPENDS+=		ld.gold:devel/binutils \
			llc${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
RUN_DEPENDS+=		ld.gold:devel/binutils \
			llc${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
USE_GCC=		yes

.  if ${OSVERSION} < 1200064
IGNORE=	lang/ghc on ARM requires at least __FreeBSD_version 1200064
.  endif

.  ifdef QEMU_EMULATING
IGNORE=	qemu-user-static isn't able to build lang/ghc, but it builds fine on a real hardware
.  endif
.endif

.if ${ARCH} == powerpc64
USE_GCC=	yes
CONFIGURE_ENV+=	STRIP=${LOCALBASE}/bin/strip

.  if ${OSVERSION} < 1200086
IGNORE=	lang/ghc on powerpc64 requires at least __FreeBSD_version 1200086
.  endif
.endif

CONFIGURE_ENV+=		CC=${CC} LD=${LD}

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
GHC_LIBDIR=	${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION}
GHC_LIBDIR_REL=	lib/ghc-${GHC_VERSION}

PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} GHC_LIBDIR=${GHC_LIBDIR_REL}

HACKAGE_SITE?=	http://hackage.haskell.org/package/

.if empty(PORT_OPTIONS:MBOOT)
BOOT_DIR=	${WRKDIR}/ghc-${BOOT_GHC_VERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/ghc-${BOOT_GHC_VERSION}
BOOT_GHC-PKG=	${BOOT_DIR}/bin/ghc-pkg-${BOOT_GHC_VERSION}
BOOT_HSC2HS=	${BOOT_DIR}/bin/hsc2hs

SLAVE_CMD=	${SETENV} PATH=${BOOT_DIR}/bin:${PATH}

CONFIGURE_ARGS_BOOT+=	--prefix=${BOOT_DIR}
CONFIGURE_ARGS+=	--with-ghc=${BOOT_GHC}
.else # MBOOT
SLAVE_CMD=		# empty
CONFIGURE_ARGS+=	--with-ghc=${LOCALBASE}/bin/ghc
.endif # MBOOT

# override TMPDIR because /tmp often doesn't have enough space
# to build some of the larger libraries.
TMPDIR=		${WRKSRC}/tmp

# Defining with documentation:
# An in place installation and registration of hscolour will be
# activated. In this way it's possible to use it directly into
# the build tree, without needing to install it. At the end
# you could view the output of: ${BOOT_GHC} describe hscolour

SLAVES_PREFIX=		${WRKDIR}/slaves_prefix
SLAVES_WRKDIRPREFIX=	${WRKDIR}/slaves_wrkdirprefix

MAKE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}

post-extract:
# Use the "wrap" trick on arches that have to use pre-ino64 bootstrap binaries
.if empty(PORT_OPTIONS:MBOOT) && ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200031 && \
    (${ARCH} == amd64 || ${ARCH} == i386)
	@${REINPLACE_CMD} -e 's|@SettingsCCompilerLinkFlags@|& -Wl,--wrap=readdir_r,--wrap=stat,--wrap=lstat,--wrap=fstat,--wrap=mknod|' ${BOOT_DIR}/settings.in
.endif

# %%PORTDOCS%%%%DOCSDIR%%/html/libraries/doc-index-V.html
post-install-script:
	${FIND} -ds ${GHC_LIBDIR} -type f -print | ${SED} -E \
		-e 's,^${STAGEDIR}${PREFIX}/?,,' \
		-e '/^${GHC_LIBDIR:C/\//\\\//g}\/package.conf.d\/package\.cache/s|^|@comment |g' \
		>> ${TMPPLIST}
	${FIND} -ds ${STAGEDIR}${DOCSDIR} -type f -print | ${SED} -E \
		-e 's,^${STAGEDIR}${PREFIX}/?,,' \
		-e '/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/doc-index-[^.]+\.html/s|^|@comment |g' \
		-e '/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/index[^\/.]*\.html/s|^|@comment|g' \
		-e '/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/[^\/]+\.png/s|^|@comment |g' \
		>> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	# Cleanup the indexen created by gen_contents_index
	${ECHO} "@postunexec ${RM} %D/${DOCSDIR_REL}/html/libraries/doc-index-*.html" >> ${TMPPLIST}
	${ECHO} "@postunexec ${RM} %D/${DOCSDIR_REL}/html/libraries/index*.html" >> ${TMPPLIST}
	${ECHO} "@postunexec ${RM} %D/${DOCSDIR_REL}/html/libraries/*.png" >> ${TMPPLIST}
.endif
	${ECHO} '@postunexec ${RM} %D/${GHC_LIBDIR_REL}/package.conf.d/package.cache' >>${TMPPLIST}
	${ECHO} "@postexec %D/bin/ghc-pkg recache" >>${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	${ECHO} '@postexec ${SH} -c "cd %D/${DOCSDIR_REL}/html/libraries && ./gen_contents_index"' >> ${TMPPLIST}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|; \
		s|%%AR%%|${AR}|; \
		s|%%LD%%|${LD}|' \
		${WRKSRC}/libraries/Cabal/Cabal/Distribution/Simple/Program/Builtin.hs
# we must use binutils:ld on arm
.if ${ARCH} == aarch64 || ${ARCH} == armv6 || ${ARCH} == armv7
	@${REINPLACE_CMD} -e 's|LD_NO_GOLD=ld|LD_NO_GOLD=${LOCALBASE}/bin/ld|' \
		${WRKSRC}/aclocal.m4
.endif

	@${REINPLACE_CMD} -e 's/@SettingsLlcCommand@/llc${LLVM_VERSION}/' ${WRKSRC}/settings.in
	@${REINPLACE_CMD} -e 's/@SettingsOptCommand@/opt${LLVM_VERSION}/' ${WRKSRC}/settings.in

.if empty(PORT_OPTIONS:MBOOT)
	@${REINPLACE_CMD} -e '/^mandir/d' ${BOOT_DIR}/mk/build.mk
	@${REINPLACE_CMD} -e '/^infodir/d' ${BOOT_DIR}/mk/build.mk
	@${REINPLACE_CMD} -e '/^docdir/d' ${BOOT_DIR}/mk/build.mk
	@${REINPLACE_CMD} -e '/^htmldir/d' ${BOOT_DIR}/mk/build.mk
.endif

pre-configure: apply-slist
	# Copy the subbed build.mk to the proper position
	${CP} ${WRKDIR}/build.mk ${WRKSRC}/mk/build.mk

	@${MKDIR} ${TMPDIR}
.if empty(PORT_OPTIONS:MBOOT) && ${OPSYS} == FreeBSD && \
    ${OSVERSION} >= 1200031 && \
    (${ARCH} == amd64 || ${ARCH} == i386)
	${CC} ${CFLAGS} -c -o ${BOOT_DIR}/wrap.o ${PATCHDIR}/wrap.c
	for x in ${BOOT_DIR}/rts/dist/build/libCffi*.a; do \
	    ${AR} q $$x ${BOOT_DIR}/wrap.o; ${RANLIB} $$x; \
	done
	rm ${BOOT_DIR}/wrap.o
.endif # Do not merge, prev condition need to grow OSVER check.
.if empty(PORT_OPTIONS:MBOOT)
	@(cd ${BOOT_DIR} && ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS_BOOT})
	@(cd ${BOOT_DIR} && PACKAGES='' ${MAKE_CMD} install)
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -e "\a"
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} "  WARNING: Now HsColour will be built, the respective port will not   "
	@${ECHO_MSG} "           be installed, but an in-place installation and             "
	@${ECHO_MSG} "           registration of both takes place.                          "
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} ""
.  if !(defined(PACKAGE_BUILDING) || defined(BATCH))
	@sleep 3
.  endif

	@${MKDIR} ${SLAVES_PREFIX}
	@${MKDIR} ${SLAVES_WRKDIRPREFIX}

	@(cd ${SLAVES_WRKDIRPREFIX} && \
		${TAR} xvf ${DISTDIR}/hscolour-${HSCOLOUR_VERSION}.tar.gz && \
		cd hscolour-${HSCOLOUR_VERSION} && \
		${SLAVE_CMD} ghc --make -o Setup Setup.hs -package Cabal && \
		${SLAVE_CMD} ./Setup configure --ghc --prefix=${SLAVES_PREFIX} --with-gcc=${CC} --with-ld=${LD} && \
		${SLAVE_CMD} ./Setup build && \
		${SLAVE_CMD} ./Setup install)
.endif

_EXECUTABLES=	${GHC_LIBDIR}/bin/unlit \
		${GHC_LIBDIR}/bin/hpc \
		${GHC_LIBDIR}/bin/ghc-iserv \
		${GHC_LIBDIR}/bin/ghc-pkg \
		${GHC_LIBDIR}/bin/hsc2hs \
		${GHC_LIBDIR}/bin/runghc \
		${GHC_LIBDIR}/bin/ghc \
		${GHC_LIBDIR}/bin/hp2ps

.if ${PORT_OPTIONS:MPROFILE}
_EXECUTABLES+=	${GHC_LIBDIR}/bin/ghc-iserv-prof
.endif
.if ${PORT_OPTIONS:MDYNAMIC}
_EXECUTABLES+=	${GHC_LIBDIR}/bin/ghc-iserv-dyn
.endif
.if ${PORT_OPTIONS:MDOCS}
_EXECUTABLES+=	${GHC_LIBDIR}/bin/haddock
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/haddock
.if ${PORT_OPTIONS:MDOCS}
	${LN} -sf haddock-ghc-${GHC_VERSION} ${STAGEDIR}${PREFIX}/bin/haddock
.endif
	(for f in ${_EXECUTABLES} $$(${FIND} ${GHC_LIBDIR} -name '*.so*'); do \
		${STRIP_CMD} $$f; done)

# Create a bootstrap compiler tar ball: run this in an interactive poudriere jail
.PHONY: create-bootstrap
create-bootstrap:
	cd ${WRKSRC} \
		&& ${ECHO} "BIN_DIST_NAME=ghc-${GHC_VERSION}-boot" >> mk/build.mk \
		&& ${ECHO} "BIN_DIST_TAR=ghc-${GHC_VERSION}-boot.tar" >> mk/build.mk \
		&& gmake binary-dist TAR_COMP=xz \
		&& ${MV} ${WRKSRC}/ghc-${GHC_VERSION}-boot-${GHC_ARCH}-portbld-freebsd.tar.xz /tmp/ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz

	cd /tmp \
		&& sha256 ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz \
		&& ${ECHO} -n "SIZE (ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz) = " \
		&& ${STAT} -f %z ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz

# Much like create-bootstrap, just different naming and output format
.PHONY: create-stack-bindist
create-stack-bindist:
	${REINPLACE_CMD} -e '/^mandir/d' \
			-e '/^infodir/d' \
			-e '/^docdir/d' \
			-e '/^htmldir/d' \
		${WRKSRC}/mk/build.mk

	cd ${WRKSRC} \
		&& gmake binary-dist TAR_COMP=xz \
		&& ${MV} ${WRKSRC}/ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz /tmp/

	cd /tmp \
		&& ${ECHO} "${GHC_VERSION}:" \
		&& ${ECHO} "url: \"http://distcache.FreeBSD.org/local-distfiles/arrowd/stack-bindists/ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz\"" \
		&& ${ECHO} -n "content-length: " \
		&& ${STAT} -f %z ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz \
		&& ${ECHO} -n "sha1: " \
		&& sha1 -q ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz \
		&& ${ECHO} -n "sha256: " \
		&& sha256 -q ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz
