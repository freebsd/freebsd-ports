# New ports collection makefile for: sml/nj
# Date created:        7 July 1998
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	smlnj
PORTVERSION=	110.0.7
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.research.bell-labs.com/dist/smlnj/release/110.0.7/ \
		http://smlnj.cs.uchicago.edu/dist/release/110.0.7/ \
		ftp://flint.cs.yale.edu/pub/smlnj/release/110.0.7/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	bin.x86-unix.tar.Z cm.tar.Z cml.tar.Z \
		config.tar.Z eXene.tar.Z \
		ml-burg.tar.Z ml-lex.tar.Z \
		ml-yacc.tar.Z runtime.tar.Z \
		smlnj-c.tar.Z smlnj-lib.tar.Z
EXTRACT_ONLY=	config.tar.Z

MAINTAINER=	joemann@beefree.free.de
COMMENT=	A popular functional language from Bell Labs

# Other mirror sites that generally carry only released versions of SML
# 	ftp://ftp.cl.cam.ac.uk/MIRRORED/smlnj/release/

DIST_SUBDIR=	sml-nj/${PORTVERSION}
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes

CONFLICTS=	smlnj-110.[1-9][0-9]*

ONLY_FOR_ARCHS=	i386

SML_BASE=	${PREFIX}/lib/sml-nj
SML_LIBDIR=	${SML_BASE}/lib
SML_BINDIR=	${SML_BASE}/bin
SML_SRCDIR=	${SML_BASE}/src
SML_EXES=	ml-burg ml-lex ml-yacc sml sml-cm

# make symlinks to the dist files
post-extract:
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/*  .

# The build target needs to run $WRKDIR/config/install.sh
do-build:
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="${FILESDIR}" PATCH="${PATCH}" PATCH_ARGS="${PATCH_ARGS}" \
		./config/install.sh

# install target
# 1. create installation directories
# 2. copy the ./bin directory across
# 3. edit bin/.run_sml to override BIN_DIR
# 4. set up temporary symlinks from WRKDIR subdirs to SML_BASE
# 5. run config/install.sh in SML_BASE in order to
# 6. rebuild sml-cm with CM's paths pointing into SML_BASE
# 7. remove the temporary symlinks
# 8. copy all x86-unix directories
# 9. find all .cm files reachable from $WRKDIR/lib and copy them across
# 10. copy the aliases in ./lib changing WRKDIR to SML_LIBDIR
# 11. install links to executables in $PREFIX/bin
do-install:
	${MKDIR} ${SML_BASE} ${SML_BINDIR} ${SML_LIBDIR}
	tar -C ${WRKDIR} -cf - bin | tar -C ${SML_BASE} -xf -
	${RM} -f ${SML_BINDIR}/.run-sml
	${SED} -e "s,^BIN_DIR=.*\$$,BIN_DIR=${SML_BINDIR}," \
		< ${WRKDIR}/bin/.run-sml > ${SML_BINDIR}/.run-sml
	${CHMOD} 755 ${SML_BINDIR}/.run-sml
	${LN} -s ${WRKDIR}/config ${SML_BASE}
	${LN} -s ${WRKDIR}/bin.x86-unix ${SML_BASE}
	${LN} -s ${WRKDIR}/src ${SML_BASE}
	${RM} ${SML_BINDIR}/.heap/sml*
	cd ${SML_BASE} && config/install.sh
	${RM} ${SML_BASE}/config
	${RM} ${SML_BASE}/bin.x86-unix
	${RM} ${SML_BASE}/src
	cd ${WRKDIR} && tar -cf - `${FIND} . -name x86-unix` | \
		tar -C ${SML_BASE} -xf -
	cd ${WRKDIR} && tar -cf - `${SCRIPTDIR}/get-cm ${WRKDIR}` | \
		tar -C ${SML_BASE} -xf -
	for f in ${WRKDIR}/lib/*; do\
		${SED} -e "s,${WRKDIR},${SML_BASE}," < $$f > \
			${SML_LIBDIR}/`${BASENAME} $$f`; \
	done
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${SML_BINDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SML_SRCDIR}
.for file in ${SML_EXES}
	-${LN} -s ${SML_BINDIR}/${file} ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
