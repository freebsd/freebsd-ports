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
DISTNAME=	${OCTAVE_PKGNAME}-${PORTVERSION}

bsd_octave_mk_MAINTAINER=	stephen@FreeBSD.org

BUILD_DEPENDS+=	octave:${PORTSDIR}/math/octave
RUN_DEPENDS+=	octave:${PORTSDIR}/math/octave \
		${LOCALBASE}/libexec/octave/load-octave-pkg:${PORTSDIR}/math/octave-forge-base
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre

USE_FORTRAN=	yes
USES+=		gmake

DIST_SUBDIR=	octave-forge
OCTAVE_PKGNAME=	${PORTNAME:S/octave-forge-//}
TARBALLS_DIR=	${LOCALBASE}/share/octave/tarballs

MAKE_ENV+=	PACKAGE=${WRKDIR}/${DISTNAME}.tar.gz

LOAD_OCTAVE_PKG_CMD=	${LOCALBASE}/libexec/octave/load-octave-pkg

do-install:
	${MKDIR} ${TARBALLS_DIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}.tar.gz ${TARBALLS_DIR}/.
	${LN} -s -f ${DISTNAME}.tar.gz ${TARBALLS_DIR}/${OCTAVE_PKGNAME}.tar.gz
	${LOAD_OCTAVE_PKG_CMD}

post-install:
	@${ECHO_CMD} "share/octave/tarballs/${DISTNAME}.tar.gz" >> ${TMPPLIST}
	@${ECHO_CMD} "share/octave/tarballs/${OCTAVE_PKGNAME}.tar.gz" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec if [ -x ${LOAD_OCTAVE_PKG_CMD} ]; then ${LOAD_OCTAVE_PKG_CMD}; fi" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec if [ -x ${LOAD_OCTAVE_PKG_CMD} ]; then ${LOAD_OCTAVE_PKG_CMD}; fi" >> ${TMPPLIST}
	@if [ -e ${.CURDIR}/pkg-message ]; then ${CAT} ${.CURDIR}/pkg-message; fi
