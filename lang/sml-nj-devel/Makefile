# New ports collection makefile for: sml/nj
# Version required:    110
# Date created:        7 July 1998
# Whom:                jkoshy
#
# $Id$
#

DISTNAME=     110-bin.x86-unix
PKGNAME=      smlnj-110
CATEGORIES=   lang
MASTER_SITES= ftp://ftp.research.bell-labs.com/dist/smlnj/release/110/ \
	      ftp://rodin.stanford.edu/pub/smlnj/release/110/ \
	      ftp://flint.cs.yale.edu/pub/smlnj/release/110/ \
	      ftp://ftp.diku.dk/pub/smlnj/release/110/ \
	      ftp://ftp.cl.cam.ac.uk/MIRRORED/smlnj/release/110/ \
	      ftp://sunsite.doc.ic.ac.uk/computing/programming/languages/ml/smlnj/release/110/ \
	      ftp://ftp.ntua.gr/pub/lang/smlnj/release/110/ \
	      ftp://compiler.kaist.ac.kr/pub/sml/release/110/
DISTFILES=    110-bin.x86-unix.tar.Z 110-cm.tar.Z 110-cml.tar.Z \
	      110-config.tar.Z 110-eXene.tar.Z \
	      110-ml-burg.tar.Z 110-ml-lex.tar.Z 110-ml-yacc.tar.Z \
	      110-runtime.tar.Z 110-sml-nj.tar.Z 110-smlnj-c.tar.Z \
	      110-smlnj-lib.tar.Z

MAINTAINER=   jkoshy@freebsd.org

DIST_SUBDIR=  sml-nj
NO_WRKSUBDIR= yes
EXTRACT_ONLY= 110-config.tar.Z
USE_GMAKE=    yes

SML_BASE=     ${PREFIX}/lib/sml-nj
SML_LIBDIR=   ${SML_BASE}/lib
SML_BINDIR=   ${SML_BASE}/bin
SML_SRCDIR=   ${SML_BASE}/src
SML_EXES=     ml-burg ml-lex ml-yacc sml sml-cm

# The build target needs to run $WRKDIR/config/install.sh
do-build:
	cd ${WRKDIR} && ./config/install.sh

do-install:
	${MKDIR} ${SML_BASE}
	${MKDIR} ${SML_BINDIR}
	tar -C ${WRKDIR} -cf - bin | tar -C ${SML_BASE} -xf -
	${RM} ${SML_BINDIR}/.run-sml
	${SED} -e "s,^BIN_DIR=.*\$$,BIN_DIR=${SML_BINDIR}," \
		< ${WRKDIR}/bin/.run-sml > ${SML_BINDIR}/.run-sml
	chmod 755 ${SML_BINDIR}/.run-sml
.for file in ${SML_EXES}
	-${LN} -s ${SML_BINDIR}/${file} ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
