# New ports collection makefile for: sml/nj
# Date created:        7 July 1998
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	smlnj
PORTVERSION=	110.65
CATEGORIES=	lang
MASTER_SITES=	http://smlnj.cs.uchicago.edu/dist/working/${PORTVERSION}/ \
		ftp://mirror.free.de/http/smlnj.cs.uchicago.edu/dist/working/${PORTVERSION}/
PKGNAMESUFFIX=	-devel
DISTFILES=	config.tgz runtime.tgz
DIST_SUBDIR=	sml-nj/${PORTVERSION}
EXTRACT_ONLY=	config.tgz

MAINTAINER=	joemann@beefree.free.de
COMMENT=	A popular functional language from Bell Labs

NO_WRKSUBDIR=	yes
USE_GMAKE=	yes

ONLY_FOR_ARCHS=	i386

OPTIONS=	EVERYTHING "install everything from the SML/NJ distribution" off \
		RECOMPILE "recompile the SML compiler - implies EVERYTHING" off

SUB_FILES=	pkg-install
SUB_LIST=	EXEBINDIR=${MLBINRELATIVE} EXENAMES="${MLEXE}"
PKGDEINSTALL=	${PKGINSTALL}

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
MLARCH=		x86
DISTFILES+=	boot.x86-unix.tgz
#.elif (${ARCH} == "alpha")
#MLARCH=		alpha32
#DISTFILES+=	boot.alpha32-unix.tgz
.endif
DISTFILES+=	MLRISC.tgz ckit.tgz cml.tgz heap2asm.tgz ml-lpt.tgz \
		ml-lex.tgz ml-yacc.tgz smlnj-lib.tgz trace-debug-profile.tgz

PLIST_SUB=	MLARCH=${MLARCH}

.if defined(WITH_RECOMPILE)
WITH_EVERYTHING?=	${WITH_RECOMPILE}
.endif

.if defined(WITH_EVERYTHING)
DISTFILES+=	cm.tgz compiler.tgz eXene.tgz ml-burg.tgz \
		nlffi.tgz pgraph.tgz smlnj-c.tgz system.tgz
.endif

MLROOTRELATIVE=	smlnj
MLROOT=		${PREFIX}/${MLROOTRELATIVE}
MLBINRELATIVE=	${MLROOTRELATIVE}/bin
MLBIN=		${MLROOT}/bin
MLLIB=		${MLROOT}/lib
MLSRCDIRS=	base ckit cml eXene heap2asm ml-burg ml-lex ml-lpt \
		ml-yacc nlffi pgraph smlnj-c smlnj-lib
MLSRCS=
.for srcdir in ${MLSRCDIRS}
MLSRCS+=	${MLROOT}/${srcdir}
.endfor
MLTARGETS=	heap2asm
MLEXE=		heap2exec ml-antlr ml-build ml-lex ml-makedepend \
		ml-ulex ml-yacc sml
.if defined(WITH_EVERYTHING)
MLTARGETS+=	eXene ml-burg ml-nlffi-lib ml-nlffigen \
		mlrisc-tools nowhere pgraph-util src-smlnj
MLEXE+=		ml-burg ml-nlffigen nowhere
PLIST=		${WRKDIR}/.PLIST
MLRUNTIMEPLIST=	${WRKDIR}/.PLIST-runtime
MLSRCPLIST=	${WRKDIR}/.PLIST-src
MLPLISTFILES=	${.CURDIR}/pkg-plist ${FILESDIR}/plist-everything \
		${MLRUNTIMEPLIST} ${MLSRCPLIST}
.endif

pre-fetch:
	@${ECHO}
.if !defined(WITH_EVERYTHING)
	@${ECHO} 'Use make WITH_EVERYTHING=yes to also build/install'
	@${ECHO} ' eXene (X Windows toolkit),'
	@${ECHO} ' ml-burg (tree transformer),'
	@${ECHO} ' ml-nlffi (foreign function interface to C code),'
	@${ECHO} ' nowhere (preprocessor for conditional patterns),'
	@${ECHO} ' various libraries, and all the sources.'
.endif
.if !defined(WITH_RECOMPILE)
	@${ECHO} 'Use make WITH_RECOMPILE=yes to recompile the compiler.'
	@${ECHO} ' This implies WITH_EVERYTHING.'
.endif
	@${ECHO}

# make symlinks to the dist files

post-extract:
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/* .

# Configuring is done by uncommenting the appropriate #request xxx
# lines of config/targets. Dependency details are handled by
# base/system/smlnj/installer using config/dependencies and
# config/actions.

do-configure:
.if defined(MLTARGETS)
	${ECHO_CMD} -n > "${WRKDIR}/.tmp.sed"
.for t in ${MLTARGETS}
	${ECHO_CMD} '/^#request[ 	]+${t}$$/s/^#//' >> "${WRKDIR}/.tmp.sed"
.endfor
	${SED} -i .default -E -f "${WRKDIR}/.tmp.sed" "${WRKDIR}/config/targets"
.endif
# Recompilation requires ml-lex and ml-yacc. All requested targets
# will be built later using the recompiled core system after
# removing targets.customized. See "do-build" below.
.if defined(WITH_RECOMPILE)
	( ${ECHO_CMD} "request	ml-yacc" && \
	  ${ECHO_CMD} "request	ml-lex" && \
	  ${ECHO_CMD} "request	ml-lex-mllex-tool" && \
	  ${ECHO_CMD} "request	src-smlnj" ) \
	> "${WRKDIR}/config/targets.customized"
.endif

# The build target patches, builds, and installs the system within WRKDIR.
# base/runtime is not cleaned afterwards to avoid its recompilation during
# a subsequent make install.
# See base/system/README for information on recompiling the compiler.

.if defined(WITH_RECOMPILE)
RECOMPILEDIR=	base/system
.else
RECOMPILEDIR=
.endif

# calm portlint complaining about /dev/null
AUXSLASH=	/
AUXDEV=		${AUXSLASH}dev
AUXDEVNULL!=	if [ -w ${AUXDEV}/null ]; then ${ECHO_CMD} -n ${AUXDEV}/null; \
		else ${ECHO_CMD} -n '${WRKDIR}/.devnull'; fi

MLRUNTIMEPATCHES!=	cd ${FILESDIR} && \
			( ${LS} do-patch-base_runtime_* 2> ${AUXDEVNULL} || \
			  ${TRUE} )
.if defined(WITH_EVERYTHING)
MLSOURCEPATCHES!=	cd ${FILESDIR} && \
			( ${LS} do-patch-* 2> ${AUXDEVNULL} || \
			  ${TRUE} )
.else
MLSOURCEPATCHES=
.endif

do-build:
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="${PATCH_ARGS}" \
	MLNORUNTIMECLEAN=yes \
	MLRUNTIMEPATCHES="${MLRUNTIMEPATCHES}" \
	MLSOURCEPATCHES="${MLSOURCEPATCHES}"	./config/install.sh
.if defined(WITH_RECOMPILE)
	-${RM} ${WRKDIR}/config/targets.customized
	@${ECHO} '(* Recompiling the core system: *)'
	cd ${WRKDIR}/${RECOMPILEDIR} && ( \
	${ECHO_CMD} 'CM.autoload "$$smlnj/cmb.cm";' ; \
	${ECHO_CMD} 'CMB.make ();' ) | \
	../../bin/sml
	@${ECHO} '(* Building the recompiled heap: *)'
	cd ${WRKDIR}/${RECOMPILEDIR} && \
	./makeml
	@${ECHO} '(* Removing old libs and heaps: *)'
	cd ${WRKDIR}/${RECOMPILEDIR} && \
	${RM} -rf ../../lib && ${MKDIR} ../../lib && \
	${FIND} ../../bin/.heap -name '*.${MLARCH}-bsd' \
	\! -name 'sml.${MLARCH}-bsd' -delete -print
	@${ECHO} '(* Installing the recompiled libs and heap: *)'
	cd ${WRKDIR}/${RECOMPILEDIR} && \
	./installml
	@${ECHO} '(* Building requested targets: *)'
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="${PATCH_ARGS}" \
	MLNORUNTIMECLEAN=yes RECOMPILEDIR="${RECOMPILEDIR}" \
	./config/install.sh
.endif

# Nowadays PLIST has to be computed before installation. We do it in
# "pre-install" because source extraction happens during "build".

.if defined(WITH_EVERYTHING)
MLNOINSTALL=	.cm
.if defined(WITH_RECOMPILE)
MLNOINSTALL+=	sml.bin.${MLARCH}-unix sml.boot.${MLARCH}-unix \
		sml.lib sml.${MLARCH}-bsd
.endif
MLSRCEXCLUDEREGEX=	-e '^(@dirrm\ )?${MLROOTRELATIVE}/base/runtime'
.for excl in ${MLNOINSTALL}
MLSRCEXCLUDEREGEX+=	-e '/${excl}$$' -e '/${excl}/'
.endfor
MLPATCHPATHREGEX=	-E -e 's%(^|[^_])_([^_]|$$)%\1/\2%g' \
			   -e 's%(^|[^_])__([^_]|$$)%\1_\2%g' \
			   -e 's%(^|[^_])___([^_]|$$)%\1/_\2%g'

pre-install:
	@${ECHO} -n '(* Computing package list ...'
	@${TAR} -tzf ${WRKDIR}/runtime.tgz | \
	${SED} -E -e 's%^(.*[^/])$$%${MLROOTRELATIVE}/base/\1%' \
		-e 's%^(.*)/$$%@dirrm\ ${MLROOTRELATIVE}/base/\1%' \
		> ${MLRUNTIMEPLIST}
.for p in ${MLRUNTIMEPATCHES}
	@${ECHO_CMD} '${p}' | \
	${SED} ${MLPATCHPATHREGEX} | \
	${SED} -E -e 's%^do-patch-(base/.*)%${MLROOTRELATIVE}/\1.orig%' \
	>> ${MLRUNTIMEPLIST}
.endfor
	@cd "${WRKDIR}" && ( \
	( ${FIND} -s -d ${MLSRCDIRS} \! -type d | \
	${AWK} '{ print "${MLROOTRELATIVE}/" $$0 }' ) ; \
	( ${FIND} -s -d ${MLSRCDIRS} -type d -empty | \
	${AWK} '{ print "@exec mk""dir -p %D/${MLROOTRELATIVE}/" $$0 }' ) ; \
	( ${FIND} -s -d ${MLSRCDIRS} -type d | \
	${AWK} '{ print "@dirrm ${MLROOTRELATIVE}/" $$0 }' ) ) | \
	${EGREP} -v ${MLSRCEXCLUDEREGEX} > ${MLSRCPLIST}
	@${GREP} -h "^[^@]" ${MLPLISTFILES} | ${SORT} -u > ${PLIST}
	@${GREP} -h "^@exec mk""dir" ${MLPLISTFILES} | ${SORT} -u >> ${PLIST}
	@${GREP} -h "^@dirrm" ${MLPLISTFILES} | ${SORT} -r -u >> ${PLIST}
	@${ECHO} ' done. *)'
.endif

# The install target installs the heaps and libraries to their final
# location in ${MLBIN} and ${MLLIB}.
# In case of recompilation, installml installs the sml heap and the
# libraries built during compiler bootstrap to ${MLBIN} and ${MLLIB}.

.if defined(WITH_EVERYTHING)
MLSRCEXCLUDES=
.for excl in ${MLNOINSTALL}
MLSRCEXCLUDES+=	--exclude "${excl}"
.endfor
.endif

do-install:
	${MKDIR} "${MLROOT}"
.if !defined(WITH_RECOMPILE)
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="${PATCH_ARGS}" \
	INSTALLDIR="${MLROOT}" ./config/install.sh
.else
	@${ECHO} '(* Rebuilding the recompiled libs: *)'
	cd ${WRKDIR}/${RECOMPILEDIR} && ( \
	${ECHO_CMD} 'CM.autoload "$$smlnj/cmb.cm";' ; \
	${ECHO_CMD} 'CMB.make ();' ) | \
	../../bin/sml
	@${ECHO} '(* Rebuilding the recompiled heap: *)'
	cd ${WRKDIR}/${RECOMPILEDIR} && \
	./makeml
	@${ECHO} '(* Installing into ${MLROOT}: *)'
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="${PATCH_ARGS}" \
	INSTALLDIR="${MLROOT}" RECOMPILEDIR="${RECOMPILEDIR}" \
	./config/install.sh
.endif
	MLARCHOPSYS=`${MLBIN}/.arch-n-opsys` && \
	( eval $${MLARCHOPSYS} ; \
	${STRIP_CMD} "${MLBIN}/.run/run.$${ARCH}-$${OPSYS}" )
	@${CHOWN} -R ${BINOWN}:${BINGRP} "${MLBIN}" "${MLLIB}"
.if defined(WITH_EVERYTHING)
	@${ECHO} '(* Cleaning base/runtime: *)'
	cd ${WRKDIR}/base/runtime/objs && ${GMAKE} clean
	@${ECHO} -n '(* Installing sources into ${MLROOT} ...'
	@cd ${WRKDIR} && ${TAR} -cf - ${MLSRCEXCLUDES} ${MLSRCDIRS} | \
	${TAR} -xf - -C "${MLROOT}"
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${MLSRCS}
	@${ECHO} ' done. *)'
.endif

post-install:
	PKG_PREFIX=${PREFIX} MULTIEXEC_WRAPPER_VERBOSE=yes \
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.ifndef MULTIEXEC_WRAPPER_VERBOSE
deinstall:
	export MULTIEXEC_WRAPPER_VERBOSE=yes && \
	cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} deinstall
.endif

# This target may be used by dependent ports to set SMLNJ_DEVEL_VERSION
# either to the currently installed sml-nj-devel package's version
# or else to this port's version. SMLNJ_DEVEL_VERSION is an environment
# variable used by multiexec-wrapper to select the executable
# from that smlnj-devel-* package matching SMLNJ_DEVEL_VERSION.
smlnj-devel-version:
#	XXX PKG_INFO not in bsd.commands.mk (20070818)
	@${EXPR} `${PKG_INFO} -q -O lang/sml-nj-devel` : '.*-\(.*\)' \
		2>/dev/null || \
	${ECHO_CMD} ${PKGVERSION}

.include <bsd.port.post.mk>
