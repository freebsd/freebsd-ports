# New ports collection makefile for: sml/nj
# Date created:        7 July 1998
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	smlnj
PORTVERSION=	110.37
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.research.bell-labs.com/dist/smlnj/working/${PORTVERSION}/ \
		ftp://flint.cs.yale.edu/pub/smlnj/working/${PORTVERSION}/ \
		ftp://sunsite.doc.ic.ac.uk/computing/programming/languages/ml/smlnj/working/${PORTVERSION}/ \
		ftp://ftp.diku.dk/pub/smlnj/working/${PORTVERSION}/
DISTFILES=	config.tgz runtime.tgz
.if (${MACHINE_ARCH} == "i386")
DISTFILES+=	boot.x86-unix.tgz
.elif (${MACHINE_ARCH} == "alpha")
DISTFILES+=	boot.alpha32-unix.tgz
.endif
DISTFILES+=	ckit.tgz ml-burg.tgz ml-lex.tgz \
		ml-nlffi-lib.tgz ml-nlffigen.tgz \
		ml-yacc.tgz smlnj-lib.tgz
.if defined(WITH_CML) || defined(WITH_EXENE)
DISTFILES+=	cml.tgz
.endif
.if defined(WITH_EXENE)
DISTFILES+=	eXene.tgz
.endif
.if defined(WITH_SRC) || defined(WITH_RECOMPILE) || defined(WITH_FLINT)
DISTFILES+=	MLRISC.tgz cm.tgz compiler.tgz system.tgz
.endif
EXTRACT_ONLY=	config.tgz

MAINTAINER=	joemann@beefree.free.de

.if (${MACHINE_ARCH} == "i386")
MLARCH=		x86
.elif (${MACHINE_ARCH} == "alpha")
MLARCH=		alpha32
.else
BROKEN=		not ported to ${MACHINE_ARCH}
.endif

MLTARGETS=	ml-burg ckit ml-nlffi-lib ml-nlffigen
MLEXE=		ml-build ml-makedepend sml ml-yacc ml-lex ml-burg ml-nlffigen
.if defined(WITH_CML) || defined(WITH_EXENE) || defined(WITH_SRC) || defined(WITH_RECOMPILE) || defined(WITH_FLINT)
PLIST=		${WRKDIR}/.PLIST
MLPLISTFILES=	${.CURDIR}/pkg-plist
MLSRCPLIST=	${WRKDIR}/.PLIST.src
.endif

.if defined(WITH_SRC) || defined(WITH_RECOMPILE) || defined(WITH_FLINT)
# the pkg-plist for sources is large, so we'll generate it on the fly (during do-install)
MLPLISTFILES+=	${MLSRCPLIST}
MLTARGETS+=	src-smlnj
.endif
.if defined(WITH_CML) || defined(WITH_EXENE)
MLPLISTFILES+=	${FILESDIR}/plist-cml
MLTARGETS+=	cml cml-lib
.endif
.if defined(WITH_EXENE)
MLPLISTFILES+=	${FILESDIR}/plist-eXene
MLTARGETS+=	eXene
.endif

# Other mirror sites that generally carry only released versions of SML
# 	ftp://rodin.stanford.edu/pub/smlnj/release/
# 	ftp://ftp.cl.cam.ac.uk/MIRRORED/smlnj/release/
# 	ftp://ftp.ntua.gr/pub/lang/smlnj/release/
# Mirror sites that keep files around in gzipped format
# 	ftp://flint.cs.yale.edu/pub/smlnj/working/110.9.1/

DIST_SUBDIR=	sml-nj/${PORTVERSION}
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes

NO_LATEST_LINK=	yes

pre-fetch:
	@${ECHO}
.if !defined(WITH_EXENE)
.if !defined(WITH_CML)
	@${ECHO} 'Use make WITH_CML=yes to build CML (Concurrent ML).'
.endif
	@${ECHO} 'Use make WITH_EXENE=yes to build eXene (X Windows toolkit),'
	@${ECHO} ' this implies WITH_CML.'
.endif
.if !defined(WITH_FLINT)
.if !defined(WITH_RECOMPILE)
.if !defined(WITH_SRC)
	@${ECHO} 'Use make WITH_SRC=yes to have the sources installed.'
.endif
	@${ECHO} 'Use make WITH_RECOMPILE=yes to recompile the compiler,'
	@${ECHO} ' this implies WITH_SRC.'
.endif
	@${ECHO} 'Use make WITH_FLINT=yes to build sml with the FLINT'
	@${ECHO} ' structures accessible (see http://flint.cs.yale.edu),'
	@${ECHO} ' this implies WITH_RECOMPILE.'
.endif
	@${ECHO}

# make symlinks to the dist files

post-extract:
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/*  .

# Configuring is done by uncommenting the appropriate #TARGETS="$TARGETS xxx"
# lines of config/targets

do-configure:
	test -f "${WRKDIR}/config/targets.orig" || \
	${MV} "${WRKDIR}/config/targets" "${WRKDIR}/config/targets.orig"
	${ECHO} -n > ${WRKDIR}/.tmp.sed
.for t in ${MLTARGETS}
	${ECHO} '/^#TARGETS="\$$TARGETS[ 	]+${t}"$$/s/#//' >> ${WRKDIR}/.tmp.sed
.endfor
	${SED} -E -f ${WRKDIR}/.tmp.sed "${WRKDIR}/config/targets.orig" \
	> "${WRKDIR}/config/targets"

# The build target builds and installs the system within the WRKDIR.
# The src/runtime is not cleaned afterwards to avoid recompilation during
# a subsequent make install.
# See src/system/README for information on recompiling the compiler.

.if defined(WITH_FLINT)
MLFLINTPATCH=	optional-patch-flint-access
.endif

do-build:
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="$(FILESDIR)" PATCH="$(PATCH)" PATCH_ARGS="$(PATCH_ARGS)" \
	MLNORUNTIMECLEAN=yes	./config/install.sh
.if defined(WITH_FLINT)
	test -f "${WRKDIR}/.patch.${MLFLINTPATCH}" || \
	( cd ${WRKDIR} && \
	${PATCH} < "${FILESDIR}/${MLFLINTPATCH}" && \
	${TOUCH} "${WRKDIR}/.patch.${MLFLINTPATCH}" )
.endif
.if defined(WITH_RECOMPILE) || defined(WITH_FLINT)
	cd ${WRKDIR}/src/system && ( \
	${ECHO} 'CM.autoload "$$smlnj/cmb.cm";' ; \
	${ECHO} 'CMB.make ();' ) | \
	../../bin/sml && \
	./makeml && \
	./installml &&
.endif

# The install target installs the heaps and libraries to their final
# location in ${PREFIX}/smlnj.
# In case of recompilation, installml installs the sml heap and the
# libraries built during compiler bootstrap to ${PREFIX}/smlnj.

.if defined(WITH_SRC) || defined(WITH_RECOMPILE) || defined(WITH_FLINT)
MLNOINSTALL=	CM
.if defined(WITH_RECOMPILE) || defined(WITH_FLINT)
MLNOINSTALL+=	sml.boot.${MLARCH}-unix sml.bin.${MLARCH}-unix
.endif
MLSRCEXCLUDES=
.for excl in ${MLNOINSTALL}
MLSRCEXCLUDES+=	--exclude "${excl}"
.endfor
.endif

PLIST_SUB=	MLARCH=${MLARCH}

do-install:
	${MKDIR} "${PREFIX}/smlnj"
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="$(FILESDIR)" PATCH="$(PATCH)" PATCH_ARGS="$(PATCH_ARGS)" \
	INSTALLDIR="$(PREFIX)/smlnj"	./config/install.sh
.if defined(WITH_RECOMPILE) || defined(WITH_FLINT)
	cd ${WRKDIR}/src/system && \
	INSTALLROOT="${PREFIX}/smlnj" ./makeml && \
	INSTALLROOT="${PREFIX}/smlnj" ./installml
.endif
.if defined(WITH_SRC) || defined(WITH_RECOMPILE) || defined(WITH_FLINT)
	cd ${WRKDIR}/src/runtime/objs && ${GMAKE} clean
	@${ECHO} -n 'Installing sources into ${PREFIX}/smlnj ...'
	@cd ${WRKDIR} && tar -cf - ${MLSRCEXCLUDES} ckit src | tar -xf - -C "${PREFIX}/smlnj"
	@${ECHO} ' done.'
	cd "${PREFIX}" && ( find -s -d smlnj/src smlnj/ckit \! -type d ; \
	( find -s -d smlnj/src smlnj/ckit -type d | ${AWK} '{ printf "@dirrm "; print }' ) \
	) > ${MLSRCPLIST}
.endif
.if defined(WITH_CML) || defined(WITH_EXENE) || defined(WITH_SRC) || defined(WITH_RECOMPILE) || defined(WITH_FLINT)
	${GREP} -h ^[^@] ${MLPLISTFILES} | sort -u > ${PLIST}
	${GREP} -h ^@dirrm ${MLPLISTFILES} | sort -r -u >> ${PLIST}
.endif

post-install:
	${MKDIR} $(PREFIX)/bin
.for f in $(MLEXE)
	${LN} -s $(PREFIX)/smlnj/bin/$f $(PREFIX)/bin/$f
.endfor

.include <bsd.port.mk>
