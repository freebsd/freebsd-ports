# New ports collection makefile for: sml/nj
# Version required:    110
# Date created:        7 July 1998
# Whom:                jkoshy
#
# $Id: Makefile,v 1.5 1999/02/02 03:52:32 jkoshy Exp $
#

DISTNAME=     110.9.1-bin.x86-unix
PKGNAME=      smlnj-110.9.1
CATEGORIES=   lang
MASTER_SITES= ftp://ftp.research.bell-labs.com/dist/smlnj/working/110.9.1/ \
	      ftp://ftp.diku.dk/pub/smlnj/working/110.9.1/ \
	      ftp://sunsite.doc.ic.ac.uk/computing/programming/languages/ml/smlnj/working/110.9.1/ \
	      ftp://compiler.kaist.ac.kr/pub/sml/working/110.9.1/
DISTFILES=    110.9.1-bin.x86-unix.tar.Z 110.9.1-cm.tar.Z 110.9.1-cml.tar.Z \
	      110.9.1-config.tar.Z 110.9.1-eXene.tar.Z \
	      110.9.1-ml-burg.tar.Z 110.9.1-ml-lex.tar.Z 110.9.1-ml-yacc.tar.Z \
	      110.9.1-runtime.tar.Z 110.9.1-smlnj-c.tar.Z \
	      110.9.1-smlnj-lib.tar.Z

MAINTAINER=   jkoshy@freebsd.org

# Other mirror sites that generally carry only released versions of SML
# 	ftp://rodin.stanford.edu/pub/smlnj/release/
# 	ftp://ftp.cl.cam.ac.uk/MIRRORED/smlnj/release/
# 	ftp://ftp.ntua.gr/pub/lang/smlnj/release/
# Mirror sites that keep files around in gzipped format
# 	ftp://flint.cs.yale.edu/pub/smlnj/working/110.9.1/

DIST_SUBDIR=  sml-nj
NO_WRKSUBDIR= yes
EXTRACT_ONLY= 110.9.1-config.tar.Z
USE_GMAKE=    yes

SML_BASE=     ${PREFIX}/lib/sml-nj
SML_LIBDIR=   ${SML_BASE}/lib
SML_BINDIR=   ${SML_BASE}/bin
SML_SRCDIR=   ${SML_BASE}/src
SML_EXES=     ml-burg ml-lex ml-yacc sml

# make symlinks to the dist files
post-extract:
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/*  .

# The build target needs to run $WRKDIR/config/install.sh
do-build:
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="$(FILESDIR)" PATCH="$(PATCH)" PATCH_ARGS="$(PATCH_ARGS)" \
		./config/install.sh

# install target
# 1. create installation directories
# 2. copy the ./bin directory across
# 3. edit bin/.run_sml to override BIN_DIR
# 4. copy all .stable files in CM/ directories
# 5. find all .cm files reachable from $WRKDIR/lib and copy them across
# 6. copy the aliases in ./lib changing WRKDIR to SML_LIBDIR
# 7. install links to executables in $PREFIX/bin
do-install:
	${MKDIR} ${SML_BASE} ${SML_BINDIR} ${SML_LIBDIR}
	tar -C ${WRKDIR} -cf - bin | tar -C ${SML_BASE} -xf -
	${RM} -f ${SML_BINDIR}/.run-sml
	${SED} -e "s,^BIN_DIR=.*\$$,BIN_DIR=${SML_BINDIR}," \
		< ${WRKDIR}/bin/.run-sml > ${SML_BINDIR}/.run-sml
	chmod 755 ${SML_BINDIR}/.run-sml
	cd ${WRKDIR} && tar -cf - `find . -name '*.stable' | ${GREP} CM` | \
		tar -C ${SML_BASE} -xf -
	cd ${WRKDIR} && tar -cf - `${SCRIPTDIR}/get-cm ${WRKDIR}` | \
		tar -C ${SML_BASE} -xf -
	for file in ${WRKDIR}/lib/*; do\
		${SED} -e "s,${WRKDIR},${SML_BASE}," < $$file > \
			${SML_LIBDIR}/`basename $$file`; \
	done
.for file in ${SML_EXES}
	-${LN} -s ${SML_BINDIR}/${file} ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
