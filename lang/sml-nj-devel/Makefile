# New ports collection makefile for: sml/nj
# Date created:        7 July 1998
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	smlnj
PORTVERSION=	110.48
CATEGORIES=	lang
MASTER_SITES=	http://smlnj.cs.uchicago.edu/dist/working/${PORTVERSION}/
DISTFILES=	config.tgz runtime.tgz
.include <bsd.port.pre.mk>
.if (${ARCH} == "i386")
DISTFILES+=	boot.x86-unix.tgz
#.elif (${ARCH} == "alpha")
#DISTFILES+=	boot.alpha32-unix.tgz
.endif
DISTFILES+=	ml-yacc.tgz ml-lex.tgz smlnj-lib.tgz cml.tgz
.if defined(WITH_EVERYTHING) || defined(WITH_RECOMPILE) || defined(WITH_FLINT)
DISTFILES+=	ml-burg.tgz \
		ckit.tgz ml-nlffi-lib.tgz ml-nlffigen.tgz smlnj-c.tgz \
		eXene.tgz \
		MLRISC.tgz cm.tgz compiler.tgz system.tgz
.endif
EXTRACT_ONLY=	config.tgz

MAINTAINER=	joemann@beefree.free.de
COMMENT=	A popular functional language from Bell Labs

DIST_SUBDIR=	sml-nj/${PORTVERSION}
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes

NO_LATEST_LINK=	yes
CONFLICTS=	smlnj-110.0.*

ONLY_FOR_ARCHS=	i386

.if (${ARCH} == "i386")
MLARCH=		x86
#.elif (${ARCH} == "alpha")
#MLARCH=		alpha32
.endif

PLIST_SUB=	MLARCH=${MLARCH}

.if defined(WITH_FLINT)
WITH_RECOMPILE?=	${WITH_FLINT}
.endif
.if defined(WITH_RECOMPILE)
WITH_EVERYTHING?=	${WITH_RECOMPILE}
.endif

MLROOTRELATIVE=	smlnj
MLROOT=		${PREFIX}/${MLROOTRELATIVE}
MLBIN=		${MLROOT}/bin
MLLIB=		${MLROOT}/lib
MLSRCSBASE=	ckit src
MLSRCSRELATIVE=	${MLROOTRELATIVE}/ckit ${MLROOTRELATIVE}/src
MLSRCS=		${MLROOT}/ckit ${MLROOT}/src
MLEXE=		sml ml-yacc ml-lex ml-build ml-makedepend
.if defined(WITH_EVERYTHING)
MLTARGETS=	ml-burg eXene src-smlnj \
		ml-nlffi-lib ml-nlffigen nowhere pgraph-util
MLEXE+=		ml-burg ml-nlffigen nowhere
PLIST=		${WRKDIR}/.PLIST
MLRUNTIMEPLIST=	${WRKDIR}/.PLIST-runtime
MLSRCPLIST=	${WRKDIR}/.PLIST-src
MLPLISTFILES=	${.CURDIR}/pkg-plist ${FILESDIR}/plist-everything \
		${MLRUNTIMEPLIST} ${MLSRCPLIST}
.endif
.if defined(WITH_FLINT)
MLFLINTPATCH=	optional-patch-src::compiler::core.cm
.endif

# This is an ugly hack to find out if we need to patch and
# recompile the core system, because src/system/smlnj/installer
# currently fails on cross device installs, i.e. if ${WRKDIR}
# and ${MLROOT} are not on the same partition.

.if !make(describe) && !defined(WITH_RECOMPILE)
.if defined(WRKDIR)
MLWRKDIR=	${WRKDIR}
.else
MLWRKDIR!=	cd ${.CURDIR} && ${MAKE} describe -V WRKDIR
.endif
.if !defined(DF)
DF!=		${WHICH} df
.endif
MLCHROOT!=	${DF} / | ${TAIL} -1 | \
		${AWK} '{ if ($$NF == "/") pri''ntf "" ; \
			else pri''ntf "%s", $$NF }'
MLFINDMOUNT=	'{ if (P == $$NF) MAXMOUNT = P ; else \
		   if (index(P "/", $$NF) == 1) \
		   if (length($$NF) > length(MAXMOUNT)) MAXMOUNT = $$NF } \
		END { print MAXMOUNT }'
MLWRKDIRMOUNT!=	${DF} | ${AWK} -v P="${MLCHROOT}${MLWRKDIR}" ${MLFINDMOUNT}
MLROOTMOUNT!=	${DF} | ${AWK} -v P="${MLCHROOT}${MLROOT}" ${MLFINDMOUNT}
.if ${MLWRKDIRMOUNT} != ${MLROOTMOUNT}
FORCE_RECOMPILE=	yes
.if !defined(WITH_EVERYTHING)
DISTFILES+=	MLRISC.tgz cm.tgz compiler.tgz system.tgz
.endif
.endif
.endif

pre-fetch:
.if defined(FORCE_RECOMPILE)
	@${ECHO}
	@${ECHO} '***** Recompilation enforced because of an installer bug'
	@${ECHO} '***** for cross device installs. This increases time'
	@${ECHO} '***** and space required to build the port.'
	@${ECHO} '***** To avoid this, let WRKDIR (or WRKDIRPREFIX)'
	@${ECHO} '***** point to the same partition as ${MLROOT}.'
.endif
	@${ECHO}
.if !defined(WITH_EVERYTHING)
	@${ECHO} 'Use make WITH_EVERYTHING=yes to also build ml-burg'
	@${ECHO} ' (tree transformer), eXene (X Windows toolkit),'
	@${ECHO} ' ml-nlffi (foreign function interface to C code),'
	@${ECHO} ' nowhere (preprocessor for conditional patterns),'
	@${ECHO} ' and all the sources.'
.endif
.if !defined(WITH_RECOMPILE)
	@${ECHO} 'Use make WITH_RECOMPILE=yes to recompile the compiler.'
	@${ECHO} ' This implies WITH_EVERYTHING.'
.endif
.if !defined(WITH_FLINT)
	@${ECHO} 'Use make WITH_FLINT=yes to apply a p''atch w''hich makes'
	@${ECHO} ' the compiler'"'"'s FLINT structures visible (see'
	@${ECHO} ' http://flint.cs.yale.edu/flint/publications/tcif.html),'
	@${ECHO} ' use it with CM.autoload "$$smlnj/viscomp/core.cm";'
	@${ECHO} ' or see http://offshore.free.de/~5/FLINTerpreter/sml2flint/'
	@${ECHO} ' for code that should help you to get started.'
	@${ECHO} ' This implies WITH_RECOMPILE.'
.endif
	@${ECHO}

# make symlinks to the dist files

post-extract:
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/* .

# Configuring is done by uncommenting the appropriate #request xxx
# lines of config/targets. Dependency details are handled by
# src/system/smlnj/installer using config/dependencies.

.if defined(WITH_EVERYTHING) || defined(FORCE_RECOMPILE)
do-configure:
.if defined(WITH_EVERYTHING)
	${ECHO_CMD} -n > ${WRKDIR}/.tmp.sed
.for t in ${MLTARGETS}
	${ECHO_CMD} '/^#request[ 	]+${t}$$/s/^#//' >> ${WRKDIR}/.tmp.sed
.endfor
	${SED} -i .default -E -f ${WRKDIR}/.tmp.sed "${WRKDIR}/config/targets"
.endif
# Recompilation requires ml-lex and ml-yacc. All requested targets
# will be built later using the recompiled core system after
# removing targets.customized. See "do-build" below.
.if defined(WITH_RECOMPILE) || defined(FORCE_RECOMPILE)
	( ${ECHO_CMD} "request	ml-yacc" && \
	  ${ECHO_CMD} "request	ml-lex" ) \
	> "${WRKDIR}/config/targets.customized"
.endif
.endif

# The build target patches, builds, and installs the system within WRKDIR.
# src/runtime is not cleaned afterwards to avoid its recompilation during
# a subsequent make install.
# See src/system/README for information on recompiling the compiler.

.if defined(WITH_RECOMPILE) || defined(FORCE_RECOMPILE)
RECOMPILEDIR=	src/system
.else
RECOMPILEDIR=
.endif

.if defined(WITH_EVERYTHING) || defined(FORCE_RECOMPILE)
MLSOURCEUNPACKTARGETS=	cm compiler mlrisc smlnj-lib system
MLSOURCEPATCHES!=	cd ${FILESDIR} && ${LS} do-patch-src::*
.if defined(WITH_FLINT)
MLSOURCEPATCHES+=	${MLFLINTPATCH}
.endif
.else
MLSOURCEUNPACKTARGETS=
MLSOURCEPATCHES=
.endif

do-build:
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="${PATCH_ARGS}" \
	MLNORUNTIMECLEAN=yes \
	MLSOURCEUNPACKTARGETS="${MLSOURCEUNPACKTARGETS}" \
	MLSOURCEPATCHES="${MLSOURCEPATCHES}"	./config/install.sh
.if defined(WITH_RECOMPILE) || defined(FORCE_RECOMPILE)
	${RM} ${WRKDIR}/config/targets.customized
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
.if defined(WITH_RECOMPILE) || defined(FORCE_RECOMPILE)
MLNOINSTALL+=	sml.bin.${MLARCH}-unix sml.boot.${MLARCH}-unix \
		sml.lib sml.${MLARCH}-bsd
.endif
MLSRCEXCLUDEREGEX=	-e '^(@dirrm\ )?${MLROOTRELATIVE}/src/runtime'
.for excl in ${MLNOINSTALL}
MLSRCEXCLUDEREGEX+=	-e '/${excl}$$' -e '/${excl}/'
.endfor

pre-install:
	@${ECHO} -n '(* Computing package list ...'
	@${TAR} -tzf ${WRKDIR}/runtime.tgz | \
	${SED} -E -e 's%^(.*[^/])$$%${MLROOTRELATIVE}/src/\1%' \
		-e 's%^(.*)/$$%@dirrm\ ${MLROOTRELATIVE}/src/\1%' \
		> ${MLRUNTIMEPLIST}
	@cd "${WRKDIR}" && ( \
	( ${FIND} -s -d ${MLSRCSBASE} \! -type d | \
	${AWK} '{ print "${MLROOTRELATIVE}/" $$0 }' ) ; \
	( ${FIND} -s -d ${MLSRCSBASE} -type d | \
	${AWK} '{ print "@dirrm ${MLROOTRELATIVE}/" $$0 }' ) ) | \
	${EGREP} -v ${MLSRCEXCLUDEREGEX} > ${MLSRCPLIST}
	@${GREP} -h ^[^@] ${MLPLISTFILES} | ${SORT} -u > ${PLIST}
	@${GREP} -h ^@dirrm ${MLPLISTFILES} | ${SORT} -r -u >> ${PLIST}
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
.if !defined(WITH_RECOMPILE) && !defined(FORCE_RECOMPILE)
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
	@${ECHO} '(* Cleaning src/runtime: *)'
	cd ${WRKDIR}/src/runtime/objs && ${GMAKE} clean
	@${ECHO} -n '(* Installing sources into ${MLROOT} ...'
	@cd ${WRKDIR} && ${TAR} -cf - ${MLSRCEXCLUDES} ${MLSRCSBASE} | \
	${TAR} -xf - -C "${MLROOT}"
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${MLSRCS}
	@${ECHO} ' done. *)'
.endif

post-install:
	${MKDIR} ${PREFIX}/bin
.for f in ${MLEXE}
	${LN} -s ${MLBIN}/$f ${PREFIX}/bin/$f
.endfor

.include <bsd.port.post.mk>
