#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# bsd.octave.mk - Octave related macro
# Common code to install octave-forge packages.
# It is, in effect, a wrapper using the package handling already built
# into math/octave.

MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases \
		SF/octave/Octave%20Forge%20Packages/R2009-06-07 \
		SF/octave/Octave%20Forge%20Packages/R2009-05-08
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

bsd_octave_mk_MAINTAINER=	stephen@FreeBSD.org

BUILD_DEPENDS+=	octave:math/octave
RUN_DEPENDS+=	octave:math/octave \
		${LOCALBASE}/libexec/octave/load-octave-pkg:math/octave-forge-base
LIB_DEPENDS+=	libpcre.so:devel/pcre

USES+=		fortran gmake compiler:c++14-lang
CXXFLAGS+=	-std=gnu++11

DIST_SUBDIR=	octave-forge
OCTAVE_PKGNAME=	${PORTNAME:S/octave-forge-//}
TARBALLS_DIR=	${LOCALBASE}/share/octave/tarballs
INSTALL_TARBALLS_DIR=	${STAGEDIR}${PREFIX}/share/octave/tarballs

MAKE_ENV+=	PACKAGE=${WRKDIR}/${DISTNAME}.tar.gz
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" LD_CXX="${CXX}" DL_LD="${CXX}" MKOCTFILE="${LOCALBASE}/bin/mkoctfile" OCTAVE_VERSION=-`${MAKE} -C ${.CURDIR}/../../math/octave -V PORTVERSION`

LOAD_OCTAVE_PKG_CMD=	${LOCALBASE}/libexec/octave/load-octave-pkg

do-install:
	${MKDIR} ${INSTALL_TARBALLS_DIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}.tar.gz ${INSTALL_TARBALLS_DIR}/.
	${LN} -s -f ${DISTNAME}.tar.gz ${INSTALL_TARBALLS_DIR}/${OCTAVE_PKGNAME}.tar.gz

post-install:
	@${ECHO_CMD} "share/octave/tarballs/${DISTNAME}.tar.gz" >> ${TMPPLIST}
	@${ECHO_CMD} "share/octave/tarballs/${OCTAVE_PKGNAME}.tar.gz" >> ${TMPPLIST}
	@${ECHO_CMD} "@postunexec if [ -x ${LOAD_OCTAVE_PKG_CMD} ]; then ${LOAD_OCTAVE_PKG_CMD}; fi" >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec if [ -x ${LOAD_OCTAVE_PKG_CMD} ]; then ${LOAD_OCTAVE_PKG_CMD}; fi" >> ${TMPPLIST}
