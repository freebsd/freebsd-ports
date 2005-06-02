# New ports collection makefile for: sml/nj
# Date created:        7 July 1998
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	smlnj
PORTVERSION=	110.54
CATEGORIES=	lang
MASTER_SITES=	http://smlnj.cs.uchicago.edu/dist/working/${PORTVERSION}/ \
		ftp://mirror.free.de/http/smlnj.cs.uchicago.edu/dist/working/${PORTVERSION}/
DISTFILES=	config.tgz runtime.tgz
.include <bsd.port.pre.mk>
.if (${ARCH} == "i386")
DISTFILES+=	boot.x86-unix.tgz
#.elif (${ARCH} == "alpha")
#DISTFILES+=	boot.alpha32-unix.tgz
.endif
DISTFILES+=	ml-yacc.tgz ml-lex.tgz smlnj-lib.tgz cml.tgz MLRISC.tgz ckit.tgz
.if defined(WITH_EVERYTHING) || defined(WITH_RECOMPILE)
DISTFILES+=	ml-burg.tgz \
		ml-nlffi-lib.tgz ml-nlffigen.tgz smlnj-c.tgz \
		eXene.tgz \
		cm.tgz compiler.tgz system.tgz tools.tgz
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

pre-fetch:
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
	@${ECHO}

# make symlinks to the dist files

post-extract:
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/* .

# Configuring is done by uncommenting the appropriate #request xxx
# lines of config/targets. Dependency details are handled by
# src/system/smlnj/installer using config/dependencies.

.if defined(WITH_EVERYTHING)
do-configure:
	${ECHO_CMD} -n > ${WRKDIR}/.tmp.sed
.for t in ${MLTARGETS}
	${ECHO_CMD} '/^#request[ 	]+${t}$$/s/^#//' >> ${WRKDIR}/.tmp.sed
.endfor
	${SED} -i .default -E -f ${WRKDIR}/.tmp.sed "${WRKDIR}/config/targets"
# Recompilation requires ml-lex and ml-yacc. All requested targets
# will be built later using the recompiled core system after
# removing targets.customized. See "do-build" below.
.if defined(WITH_RECOMPILE)
	( ${ECHO_CMD} "request	ml-yacc" && \
	  ${ECHO_CMD} "request	ml-lex" && \
	  ${ECHO_CMD} "request	src-smlnj" ) \
	> "${WRKDIR}/config/targets.customized"
.endif
.endif

# The build target patches, builds, and installs the system within WRKDIR.
# src/runtime is not cleaned afterwards to avoid its recompilation during
# a subsequent make install.
# See src/system/README for information on recompiling the compiler.

.if defined(WITH_RECOMPILE)
RECOMPILEDIR=	src/system
.else
RECOMPILEDIR=
.endif

# calm portlint complaining about /dev/null
AUXSLASH=	/
AUXDEV=		${AUXSLASH}dev
AUXDEVNULL!=	if [ -w ${AUXDEV}/null ]; then ${ECHO_CMD} -n ${AUXDEV}/null; \
		else ${ECHO_CMD} -n '${WRKDIR}/.devnull'; fi

MLRUNTIMEPATCHES!=	cd ${FILESDIR} && \
			( ${LS} do-patch-src::runtime::* 2> ${AUXDEVNULL} || \
			  ${TRUE} )
.if defined(WITH_EVERYTHING)
MLSOURCEPATCHES!=	cd ${FILESDIR} && \
			( ${LS} do-patch-src::* 2> ${AUXDEVNULL} || \
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
.if defined(WITH_RECOMPILE)
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
	-@cd ${FILESDIR} && \
	( ${LS} do-patch-src::runtime::* 2> ${AUXDEVNULL} ) | \
	${SED} -e 's%::%/%g' | \
	${SED} -E -e 's%^do-patch-(.*)%${MLROOTRELATIVE}/\1.orig%' \
	>> ${MLRUNTIMEPLIST}
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
