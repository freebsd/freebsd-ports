# $FreeBSD$

PORTNAME=	smlnj
PORTVERSION=	110.84
CATEGORIES=	lang
MASTER_SITES=	http://smlnj.cs.uchicago.edu/dist/working/${PORTVERSION}/ \
		ftp://mirror.free.de/http/smlnj.cs.uchicago.edu/dist/working/${PORTVERSION}/
DISTFILES=	config.tgz runtime.tgz
DIST_SUBDIR=	smlnj/${PORTVERSION}
EXTRACT_ONLY=	config.tgz

MAINTAINER=	joemann@beefree.free.de
COMMENT=	Compiler and tools for Standard ML (SML '97)

LICENSE=	SMLNJ
LICENSE_NAME=	Standard ML of New Jersey License
LICENSE_TEXT=	The text of the license can be obtained from the following URL:\
		http://www.smlnj.org/license.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386
LLD_UNSAFE=	yes

NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-install
SUB_LIST=	EXEBINDIR=${MLBINRELATIVE} EXENAMES="${MLEXE}"
PKGDEINSTALL=	${PKGINSTALL}

OPTIONS_DEFINE=		EVERYTHING RECOMPILE POSITION64
RECOMPILE_IMPLIES=	EVERYTHING
POSITION64_IMPLIES=	RECOMPILE
EVERYTHING_DESC=	install everything from the SML/NJ distribution
RECOMPILE_DESC=		recompile the SML compiler - implies EVERYTHING
POSITION64_DESC=	use 64bit file positions - implies RECOMPILE

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
CFLAGS+=	-m32
AS?=		as
ASFLAGS+=	--32
.endif
.if (${ARCH} == "i386" || ${ARCH} == "amd64")
MLARCH=		x86
DISTFILES+=	boot.x86-unix.tgz
.endif
DISTFILES+=	MLRISC.tgz asdl.tgz ckit.tgz cml.tgz doc.tgz heap2asm.tgz \
		ml-burg.tgz ml-lex.tgz ml-lpt.tgz ml-yacc.tgz nlffi.tgz \
		old-basis.tgz smlnj-lib.tgz trace-debug-profile.tgz

PLIST_SUB+=	MLARCH=${MLARCH}

.if ${PORT_OPTIONS:MPOSITION64}
CMB_COMMAND=	'(\#set o CMB.symval) "USE_64_BIT_POSITIONS" (SOME 1);'
.else
CMB_COMMAND=
.endif

.if ${PORT_OPTIONS:MEVERYTHING}
DISTFILES+=	cm.tgz compiler.tgz eXene.tgz \
		pgraph.tgz smlnj-c.tgz system.tgz
PLIST_SUB+=	EVERYTHING=""
.else
PLIST_SUB+=	EVERYTHING="@comment "
.endif

MLROOTRELATIVE=	smlnj
MLROOT=		${PREFIX}/${MLROOTRELATIVE}
MLBINRELATIVE=	${MLROOTRELATIVE}/bin
MLBIN=		${MLROOT}/bin
MLLIB=		${MLROOT}/lib
MLSTDSRCDIRS=	asdl cml doc heap2asm ml-burg ml-lex ml-lpt ml-yacc \
		nlffi smlnj-lib
MLSRCDIRS=	base ${MLSTDSRCDIRS} \
		ckit eXene pgraph smlnj-c
MLSRCS=
.for srcdir in ${MLSRCDIRS}
MLSRCS+=	${MLROOT}/${srcdir}
.endfor
MLTARGETS=	heap2asm
MLEXE=		asdlgen heap2exec ml-antlr ml-build ml-burg ml-lex \
		ml-makedepend ml-nlffigen ml-ulex ml-yacc sml
.if ${PORT_OPTIONS:MEVERYTHING}
MLTARGETS+=	eXene mlrisc-tools nowhere pgraph-util src-smlnj
MLEXE+=		nowhere
PLIST=		${WRKDIR}/.PLIST
MLRUNTIMEPLIST=	${WRKDIR}/.PLIST-runtime
MLSRCPLIST=	${WRKDIR}/.PLIST-src
MLPLISTFILES=	${.CURDIR}/pkg-plist ${MLRUNTIMEPLIST} ${MLSRCPLIST}
.endif

pre-fetch:
	@${ECHO}
.if ! ${PORT_OPTIONS:MEVERYTHING}
	@${ECHO} 'Use port option EVERYTHING to also build/install'
	@${ECHO} ' eXene (X Windows toolkit),'
	@${ECHO} ' nowhere (preprocessor for conditional patterns),'
	@${ECHO} ' various libraries, and all the sources.'
.endif
.if ! ${PORT_OPTIONS:MRECOMPILE}
	@${ECHO} 'Use port option RECOMPILE to recompile the compiler.'
	@${ECHO} ' This implies EVERYTHING.'
.endif
.if ! ${PORT_OPTIONS:MPOSITION64}
	@${ECHO} 'Use port option POSITION64 to use 64bit file positions.'
	@${ECHO} ' This implies RECOMPILE.'
.endif
	@${ECHO}

# make symlinks to the dist files

post-extract:
	cd ${WRKSRC} && ${LN} -sf ${_DISTDIR}/* .

# Configuring is done by uncommenting the appropriate #request
# lines of config/targets. Dependency details are handled by
# base/system/smlnj/installer using config/dependencies and
# config/actions.

do-configure:
.if defined(MLTARGETS)
	${ECHO_CMD} -n > "${WRKDIR}/.tmp.sed"
.for t in ${MLTARGETS}
	${ECHO_CMD} '/^#request[ 	]+${t}$$/s/^#//' >> "${WRKDIR}/.tmp.sed"
.endfor
	${SED} -i .default -E -f "${WRKDIR}/.tmp.sed" "${WRKSRC}/config/targets"
.endif
# Recompilation requires ml-lex and ml-yacc. All requested targets
# will be built later using the recompiled core system after
# removing targets.customized. See "do-build" below.
.if ${PORT_OPTIONS:MRECOMPILE}
	( ${ECHO_CMD} "request	ml-yacc" && \
	  ${ECHO_CMD} "request	ml-lex" && \
	  ${ECHO_CMD} "request	ml-lex-mllex-tool" && \
	  ${ECHO_CMD} "request	src-smlnj" ) \
	> "${WRKSRC}/config/targets.customized"
.endif

# The build target patches, builds, and installs the system within WRKDIR.
# base/runtime is not cleaned afterwards to avoid its recompilation during
# a subsequent make install.
# See base/system/README for information on recompiling the compiler.

.if ${PORT_OPTIONS:MRECOMPILE}
RECOMPILEDIR=	base/system
.else
RECOMPILEDIR=
.endif

MLRUNTIMEPATCHES_CMD=	cd ${FILESDIR} && \
			( ${LS} do-patch-base_runtime_* 2>&- || \
			  ${TRUE} )
MLSTANDARDPATCHES_CMD=	cd ${FILESDIR} && \
			( for srcdir in ${MLSTDSRCDIRS} ; \
			  do ${LS} do-patch-$${srcdir}_* 2>&- ; \
			  done ) || ${TRUE}
MLSTANDARDPATCHDIRS_CMD=	cd ${FILESDIR} && \
			( for srcdir in ${MLSTDSRCDIRS} ; \
			  do if ${LS} do-patch-$${srcdir}_* 1>&- 2>&- ; \
			     then ${ECHO_CMD} -n $${srcdir} " " ; fi ; \
			  done ) || ${TRUE}
.if ${PORT_OPTIONS:MEVERYTHING}
MLSOURCEPATCHES_CMD=	cd ${FILESDIR} && \
			( ${LS} do-patch-* 2>&- || \
			  ${TRUE} )
.else
MLSOURCEPATCHES_CMD=	${TRUE}
.endif

do-build:
	cd ${WRKSRC} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="-d ${PATCH_WRKSRC} ${PATCH_ARGS}" \
	MLNORUNTIMECLEAN=yes \
	MLRUNTIMEPATCHES=`${MLRUNTIMEPATCHES_CMD}` \
	MLSTANDARDPATCHES=`${MLSTANDARDPATCHES_CMD}` \
	MLSTANDARDPATCHDIRS=`${MLSTANDARDPATCHDIRS_CMD}` \
	MLSOURCEPATCHES=`${MLSOURCEPATCHES_CMD}` \
	CFLAGS='${CFLAGS}' LDFLAGS='${LDFLAGS}' \
	AS='${AS}' ASFLAGS='${ASFLAGS}' EXTRA_DEFS='${EXTRA_DEFS}' \
	./config/install.sh
.if ${PORT_OPTIONS:MRECOMPILE}
	-${RM} ${WRKSRC}/config/targets.customized
	@${ECHO} '(* Recompiling the core system: *)'
	cd ${WRKSRC}/${RECOMPILEDIR} && ( \
	${ECHO_CMD} 'CM.autoload "$$smlnj/cmb.cm";' ; \
	${ECHO_CMD} ${CMB_COMMAND} ; \
	${ECHO_CMD} 'CMB.make ();' ) | \
	../../bin/sml
	@${ECHO} '(* Building the recompiled heap: *)'
	cd ${WRKSRC}/${RECOMPILEDIR} && \
	./makeml
	@${ECHO} '(* Removing old libs and heaps: *)'
	cd ${WRKSRC}/${RECOMPILEDIR} && \
	${RM} -r ../../lib && ${MKDIR} ../../lib && \
	${FIND} ../../bin/.heap -name '*.${MLARCH}-bsd' \
	\! -name 'sml.${MLARCH}-bsd' -delete -print
	@${ECHO} '(* Installing the recompiled libs and heap: *)'
	cd ${WRKSRC}/${RECOMPILEDIR} && \
	./installml
	@${ECHO} '(* Building requested targets: *)'
	cd ${WRKSRC} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" \
	PATCH_ARGS="-d ${PATCH_WRKSRC} ${PATCH_ARGS}" \
	MLNORUNTIMECLEAN=yes RECOMPILEDIR="${RECOMPILEDIR}" \
	CFLAGS='${CFLAGS}' LDFLAGS='${LDFLAGS}' \
	AS='${AS}' ASFLAGS='${ASFLAGS}' EXTRA_DEFS='${EXTRA_DEFS}' \
	./config/install.sh
.endif

.if ${PORT_OPTIONS:MEVERYTHING}
post-build:
	${CHMOD} a-x ${WRKSRC}/eXene/examples/basicwin/test.sh \
		${WRKSRC}/smlnj-lib/HTML4/helper.py
	@${ECHO} '(* Cleaning asdl: *)'
	${FIND} ${WRKSRC}/asdl -type f \
		-exec ${GREP} -F -l "${WRKDIR}" {} \; -delete
.endif

# Nowadays PLIST has to be computed before installation. We do it in
# "pre-install" because source extraction happens during "build".

.if ${PORT_OPTIONS:MEVERYTHING}
MLNOINSTALL=	.cm
.if ${PORT_OPTIONS:MRECOMPILE}
MLNOINSTALL+=	sml.bin.${MLARCH}-unix sml.boot.${MLARCH}-unix \
		sml.lib sml.${MLARCH}-bsd
.endif
.for excl in ${MLNOINSTALL}
MLSRCEXCLUDEREGEX+=	-e '/${excl}$$' -e '/${excl}/'
.endfor
MLPATCHPATHREGEX=	-E -e 's%(^|[^_])_([^_]|$$)%\1/\2%g' \
			   -e 's%(^|[^_])__([^_]|$$)%\1_\2%g' \
			   -e 's%(^|[^_])___([^_]|$$)%\1/_\2%g'
.endif

pre-install:
.if ${PORT_OPTIONS:MEVERYTHING}
	@${ECHO} -n '(* Computing package list ...'
	@${TAR} -tzf ${WRKSRC}/runtime.tgz | \
	${SED} -E -n -e 's%^(.*[^/])$$%${MLROOTRELATIVE}/base/\1%p' \
	> ${MLRUNTIMEPLIST}
	@${MLRUNTIMEPATCHES_CMD} | \
	${SED} ${MLPATCHPATHREGEX} | \
	${SED} -E -e 's%^(do|extra)-patch-(base/.*)%${MLROOTRELATIVE}/\2%' \
	> ${MLRUNTIMEPLIST}.patched
	-@${GREP} -F -v -f ${MLRUNTIMEPLIST} ${MLRUNTIMEPLIST}.patched \
	> ${MLRUNTIMEPLIST}.patchednew
	@${CAT} ${MLRUNTIMEPLIST}.patchednew >> ${MLRUNTIMEPLIST}
	@${MLRUNTIMEPATCHES_CMD} | \
	${SED} ${MLPATCHPATHREGEX} | \
	${SED} -E -e 's%^(do|extra)-patch-(base/.*)%${MLROOTRELATIVE}/\2.orig%' \
	>> ${MLRUNTIMEPLIST}
	@cd "${WRKSRC}" && ( \
	( ${FIND} -s -d ${MLSRCDIRS} \! -type d | \
	${AWK} '{ print "${MLROOTRELATIVE}/" $$0 }' ) ; \
	( ${FIND} -s -d ${MLSRCDIRS} -type d -empty | \
	${AWK} '{ print "@dir ${MLROOTRELATIVE}/" $$0 }' ) ) | \
	${EGREP} -v "^${MLROOTRELATIVE}/base/runtime" | \
	${EGREP} -v ${MLSRCEXCLUDEREGEX} > ${MLSRCPLIST}
	@${SED} -e 's/^%%EVERYTHING%%//' ${MLPLISTFILES} | \
	${GREP} -h -v "^@dir" | ${SORT} -u > ${PLIST}
	@${SED} -e 's/^%%EVERYTHING%%//' ${MLPLISTFILES} | \
	${GREP} -h "^@dir" | ${SORT} -r -u >> ${PLIST}
	@${ECHO} ' done. *)'
.endif
# ${PKGINSTALL} contains multiexec-wrapper, which is used to select
# between executables of the same name that have been installed by
# different packages (like smlnj and smlnj-devel). The source of
# multiexec-wrapper is extracted from ${PKGINSTALL}, and inserted
# into ${PKGINSTALL} in compressed and encoded form. So it is still
# available when being installed from a binary package, even if
# ${PKGINSTALL} is no file at that time (but only input to a shell).
	@${SED} -e '/^#%%PKG-INSTALL-START%%$$/,/^#%%PKG-INSTALL-END%%$$/d' \
	       ${PKGINSTALL} > ${PKGINSTALL}.script
	@${GZIP_CMD} ${PKGINSTALL}.script
	@b64encode ${PKGINSTALL}.script.gz script.gz > ${PKGINSTALL}.script.gz.b64
	@${SED} -n -e '1,/~EOF~.$$/p' ${PKGINSTALL} > ${PKGINSTALL}.pre
	@${SED} -n -e '/^~EOF~$$/,$$p' ${PKGINSTALL} > ${PKGINSTALL}.post
	@${CAT} ${PKGINSTALL}.pre ${PKGINSTALL}.script.gz.b64 ${PKGINSTALL}.post > ${PKGINSTALL}.full
	@${DIFF} -q ${PKGINSTALL} ${PKGINSTALL}.full >/dev/null || ${CP} ${PKGINSTALL}.full ${PKGINSTALL}

# The install target installs the heaps and libraries to their final
# location in ${MLBIN} and ${MLLIB}.
# In case of recompilation, installml installs the sml heap and the
# libraries built during compiler bootstrap to ${MLBIN} and ${MLLIB}.
# When staging CM_PATHCONFIG has to point to the final
# ${MLLIB}/pathconfig (in ${PREFIX}) while building the compiler.

.if ${PORT_OPTIONS:MEVERYTHING}
MLSRCEXCLUDES=
.for excl in ${MLNOINSTALL}
MLSRCEXCLUDES+=	--exclude "${excl}"
.endfor
.endif

do-install:
	${MKDIR} "${STAGEDIR}${MLROOT}"
.if ! ${PORT_OPTIONS:MRECOMPILE}
	cd ${WRKSRC} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="-d ${PATCH_WRKSRC} ${PATCH_ARGS}" \
	STAGEDIR="${STAGEDIR}" MLLIB="${MLLIB}" \
	INSTALLDIR="${STAGEDIR}${MLROOT}" \
	CFLAGS='${CFLAGS}' LDFLAGS='${LDFLAGS}' \
	AS='${AS}' ASFLAGS='${ASFLAGS}' EXTRA_DEFS='${EXTRA_DEFS}' \
	./config/install.sh
.else
	@${ECHO} '(* Rebuilding the recompiled libs: *)'
	cd ${WRKSRC}/${RECOMPILEDIR} && ( \
	${ECHO_CMD} 'CM.autoload "$$smlnj/cmb.cm";' ; \
	${ECHO_CMD} ${CMB_COMMAND} ; \
	${ECHO_CMD} 'CMB.make ();' ) | \
	../../bin/sml
	@${ECHO} '(* Rebuilding the recompiled heap: *)'
	cd ${WRKSRC}/${RECOMPILEDIR} && \
	./makeml
	@${ECHO} '(* Installing into ${STAGEDIR}${MLROOT}: *)'
	cd ${WRKSRC} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="-d ${PATCH_WRKSRC} ${PATCH_ARGS}" \
	STAGEDIR="${STAGEDIR}" MLLIB="${MLLIB}" \
	INSTALLDIR="${STAGEDIR}${MLROOT}" RECOMPILEDIR="${RECOMPILEDIR}" \
	CFLAGS='${CFLAGS}' LDFLAGS='${LDFLAGS}' \
	AS='${AS}' ASFLAGS='${ASFLAGS}' EXTRA_DEFS='${EXTRA_DEFS}' \
	./config/install.sh
.endif
	@${ECHO} '(* Installing man pages. *)'
.for mansect in 1 2 3 4 5 6 7 8 9
	@[ ! -d ${WRKSRC}/doc/man/man${mansect} ] || \
	{ cd ${WRKSRC}/doc/man/man${mansect} && ls *.${mansect} | \
	  ${XARGS} -J % \
	    ${INSTALL_MAN} % ${STAGEDIR}${MANPREFIX}/man/man${mansect} ; }
.endfor
	@${ECHO} '(* Stripping runtime executable: *)'
	MLARCHOPSYS=`${STAGEDIR}${MLBIN}/.arch-n-opsys` && \
	( eval $${MLARCHOPSYS} ; \
	${STRIP_CMD} "${STAGEDIR}${MLBIN}/.run/run.$${ARCH}-$${OPSYS}" \
	  "${STAGEDIR}${MLBIN}/.run/run.$${ARCH}-$${OPSYS}.so" )
.if ${PORT_OPTIONS:MEVERYTHING}
	@${ECHO} '(* Cleaning base/runtime: *)'
	cd ${WRKSRC}/base/runtime/objs && ${MAKE_CMD} clean
	@${ECHO} '(* Cleaning asdl: *)'
	${FIND} ${WRKSRC}/asdl -type f \
		-exec ${GREP} -F -l "${WRKDIR}" {} \; -delete
	@${ECHO} -n '(* Installing sources into ${STAGEDIR}${MLROOT} ...'
	@cd ${WRKSRC} && ${TAR} -cf - ${MLSRCEXCLUDES} ${MLSRCDIRS} | \
	${TAR} -xf - -C "${STAGEDIR}${MLROOT}"
	@${ECHO} ' done. *)'
.endif
# Only execute ${PKGINSTALL} when installing to ${PREFIX},
# but not when staging.
.ifmake install${CALM_PORTLINT}
	PKG_PREFIX=${PREFIX} MULTIEXEC_WRAPPER_VERBOSE=yes \
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.ifndef MULTIEXEC_WRAPPER_VERBOSE
deinstall:
	export MULTIEXEC_WRAPPER_VERBOSE=yes && \
	cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} deinstall
.endif

# This target may be used by dependent ports to set SMLNJ_VERSION
# either to the currently installed smlnj package's version
# or else to this port's version. SMLNJ_VERSION is an environment
# variable used by multiexec-wrapper to select the executable
# from that smlnj-* package matching SMLNJ_VERSION.
smlnj-version:
	@{ ${PKG_INFO} -e smlnj && \
	   ${EXPR} `${PKG_INFO} -E smlnj` : '.*-\(.*\)' 2>/dev/null ; } || \
	${ECHO_CMD} ${PKGVERSION}

.include <bsd.port.post.mk>
