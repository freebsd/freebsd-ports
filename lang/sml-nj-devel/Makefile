# New ports collection makefile for: sml/nj
# Date created:        7 July 1998
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	smlnj
PORTVERSION=	110.42
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.research.bell-labs.com/dist/smlnj/working/${PORTVERSION}/ \
		ftp://flint.cs.yale.edu/pub/smlnj/working/${PORTVERSION}/ \
		ftp://gd.tuwien.ac.at/languages/smlnj/working/${PORTVERSION}/
DISTFILES=	config.tgz runtime.tgz
.if (${MACHINE_ARCH} == "i386")
DISTFILES+=	boot.x86-unix.tgz
#.elif (${MACHINE_ARCH} == "alpha")
#DISTFILES+=	boot.alpha32-unix.tgz
.endif
DISTFILES+=	ml-yacc.tgz ml-lex.tgz smlnj-lib.tgz cml.tgz
.if defined(WITH_EVERYTHING) || defined(WITH_RECOMPILE) || defined(WITH_FLINT)
DISTFILES+=	ml-burg.tgz \
		ckit.tgz ml-nlffi-lib.tgz ml-nlffigen.tgz \
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

ONLY_FOR_ARCHS=	i386

.if (${MACHINE_ARCH} == "i386")
MLARCH=		x86
#.elif (${MACHINE_ARCH} == "alpha")
#MLARCH=		alpha32
.endif

.if defined(WITH_FLINT)
WITH_RECOMPILE?=	${WITH_FLINT}
.endif
.if defined(WITH_RECOMPILE)
WITH_EVERYTHING?=	${WITH_RECOMPILE}
.endif

MLROOTRELATIVE=	smlnj
MLROOT=	${PREFIX}/${MLROOTRELATIVE}
MLBIN=		${MLROOT}/bin
MLLIB=		${MLROOT}/lib
MLSRCSBASE=	ckit src
MLSRCSRELATIVE=	${MLROOTRELATIVE}/ckit ${MLROOTRELATIVE}/src
MLSRCS=	${MLROOT}/ckit ${MLROOT}/src
MLEXE=		sml ml-yacc ml-lex ml-build ml-makedepend
.if defined(WITH_EVERYTHING)
MLTARGETS=	ml-burg eXene src-smlnj \
		ml-nlffi-lib ml-nlffigen nowhere pgraph-util
MLEXE+=		ml-burg ml-nlffigen nowhere
PLIST=		${WRKDIR}/.PLIST
MLRUNTIMEPLIST=	${WRKDIR}/.PLIST.runtime
MLSRCPLIST=	${WRKDIR}/.PLIST.src
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
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/*  .

# Configuring is done by uncommenting the appropriate #request xxx
# lines of config/targets. Dependency details are handled by
# config/install.sh using config/dependencies.

.if defined(WITH_EVERYTHING)
do-configure:
	${ECHO_CMD} -n > ${WRKDIR}/.tmp.sed
.for t in ${MLTARGETS}
	${ECHO_CMD} '/^#request[ 	]+${t}$$/s/^#//' >> ${WRKDIR}/.tmp.sed
.endfor
	${SED} -E -f ${WRKDIR}/.tmp.sed "${WRKDIR}/config/targets" \
	> "${WRKDIR}/config/targets.customized"
.endif

# The build target builds and installs the system within the WRKDIR.
# The src/runtime is not cleaned afterwards to avoid recompilation during
# a subsequent make install.
# See src/system/README for information on recompiling the compiler.

.if defined(WITH_FLINT)
MLFLINTPATCH=	optional-patch-flint-access
.endif

do-build:
.if defined(WITH_RECOMPILE)
	${MV} "${WRKDIR}/config/targets.customized" \
	"${WRKDIR}/config/targets.customized.later"
	${SED} -E -e '/^#request[        ]+src-smlnj$$/s/^#//' \
	"${WRKDIR}/config/targets" > "${WRKDIR}/config/targets.customized"
.endif
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="$(FILESDIR)" PATCH="$(PATCH)" PATCH_ARGS="$(PATCH_ARGS)" \
	MLNORUNTIMECLEAN=yes	./config/install.sh
.if defined(WITH_FLINT)
	${TEST} -f "${WRKDIR}/.patch.${MLFLINTPATCH}" || \
	( cd ${WRKDIR} && \
	${PATCH} < "${FILESDIR}/${MLFLINTPATCH}" && \
	${TOUCH} "${WRKDIR}/.patch.${MLFLINTPATCH}" )
.endif
.if defined(WITH_RECOMPILE)
	cd ${WRKDIR}/src/system && ( \
	${ECHO_CMD} 'CM.autoload "$$smlnj/cmb.cm";' ; \
	${ECHO_CMD} 'CMB.make ();' ) | \
	../../bin/sml && \
	./makeml && \
	${RM} -rf ../../lib && ${MKDIR} ../../lib && \
	${FIND} ../../bin/.heap -name '*.${MLARCH}-bsd' \
	\! -name 'sml.${MLARCH}-bsd' -delete && \
	./installml && \
	${MV} "${WRKDIR}/config/targets.customized.later" \
	"${WRKDIR}/config/targets.customized"
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="$(FILESDIR)" PATCH="$(PATCH)" PATCH_ARGS="$(PATCH_ARGS)" \
	MLNORUNTIMECLEAN=yes	./config/install.sh
.endif

# Nowadays PLIST has to be computed before installation. We do it in 
# "pre-install" because source extraction happens during "build".
.if defined(WITH_EVERYTHING)
MLNOINSTALL=	CM
.if defined(WITH_RECOMPILE)
MLNOINSTALL+=	sml.boot.${MLARCH}-unix sml.bin.${MLARCH}-unix
.endif
MLSRCEXCLUDEREGEX=	-e '^(@dirrm\ )?${MLROOTRELATIVE}/src/runtime'
.for excl in ${MLNOINSTALL}
MLSRCEXCLUDEREGEX+=	-e '/${excl}$$' -e '/${excl}/'
.endfor

pre-install:
	@${ECHO} -n 'Computing package list ...'
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
	@${ECHO} ' done.'
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

PLIST_SUB=	MLARCH=${MLARCH}

do-install:
	${MKDIR} "${MLROOT}"
.if defined(WITH_RECOMPILE)
	${MV} "${WRKDIR}/config/targets.customized" \
	"${WRKDIR}/config/targets.customized.later"
	${ECHO_CMD} -n > "${WRKDIR}/config/targets.customized"
.endif
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="$(FILESDIR)" PATCH="$(PATCH)" PATCH_ARGS="$(PATCH_ARGS)" \
	INSTALLDIR="$(MLROOT)"	./config/install.sh
	MLARCHOPSYS=`$(MLBIN)/.arch-n-opsys` && \
	( eval $${MLARCHOPSYS} ; \
	$(STRIP_CMD) "$(MLBIN)/.run/run.$${ARCH}-$${OPSYS}" )
.if defined(WITH_RECOMPILE)
	cd ${WRKDIR}/src/system && \
	INSTALLROOT="${MLROOT}" ./makeml && \
	${RM} -rf "${MLLIB}" && ${MKDIR} "${MLLIB}" && \
	${FIND}  "${MLBIN}"/.heap -name '*.${MLARCH}-bsd' \
	\! -name 'sml.${MLARCH}-bsd' -delete && \
	INSTALLROOT="${MLROOT}" ./installml
	${MV} "${WRKDIR}/config/targets.customized.later" \
	"${WRKDIR}/config/targets.customized"
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="$(FILESDIR)" PATCH="$(PATCH)" PATCH_ARGS="$(PATCH_ARGS)" \
	INSTALLDIR="$(MLROOT)"	./config/install.sh
.endif
	@${CHOWN} -R ${BINOWN}:${BINGRP} "${MLBIN}" "${MLLIB}"
.if defined(WITH_EVERYTHING)
	cd ${WRKDIR}/src/runtime/objs && ${GMAKE} clean
	@${ECHO} -n 'Installing sources into ${MLROOT} ...'
	@cd ${WRKDIR} && ${TAR} -cf - ${MLSRCEXCLUDES} ${MLSRCSBASE} | \
	${TAR} -xf - -C "${MLROOT}"
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${MLSRCS}
	@${ECHO} ' done.'
.endif

post-install:
	${MKDIR} $(PREFIX)/bin
.for f in $(MLEXE)
	${LN} -s $(MLBIN)/$f $(PREFIX)/bin/$f
.endfor

.include <bsd.port.mk>
