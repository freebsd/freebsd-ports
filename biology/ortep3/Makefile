# New ports collection makefile for:	ORTEP-III
# Version required:	1.0
# Date created:		1999-05-08
# Whom:			Ryo MIYAMOTO
#
# $FreeBSD$
#

DISTNAME= ortep
PKGNAME= ortep3-1.0
CATEGORIES= biology
MASTER_SITES= ftp://ftp.ccl.net/pub/chemistry/software/SOURCES/FORTRAN/ortep/
EXTRACT_SUFX= .tar.Z

MAINTAINER= rmiya@cc.hirosaki-u.ac.jp

LIB_DEPENDS= pgplot.5:${PORTSDIR}/graphics/pgplot

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400002
BROKEN=	doesn\'t build with new f77 compiler
.endif

pre-patch:
	${CP} ${FILESDIR}/Makefile.ortep3 ${WRKDIR}/${DISTNAME}/src/Makefile
.if defined(USEPGPLOT)
	${CP} ${FILESDIR}/patch-aa ${PATCHDIR}/
	${CP} ${FILESDIR}/patch-ab ${PATCHDIR}/
.endif

post-patch:
.if defined(USEPGPLOT)
	${RM} ${PATCHDIR}/patch-aa
	${RM} ${PATCHDIR}/patch-ab
.endif

do-build:
	(cd ${WRKDIR}/${DISTNAME}/src && ${MAKE} all)

pre-install:
	strip ${WRKDIR}/${DISTNAME}/src/ortep3
	${RM} -rf ${PREFIX}/share/doc/ortep3
	${MKDIR} ${PREFIX}/share/doc/ortep3
	${MKDIR} ${PREFIX}/share/doc/ortep3/examples
	${MKDIR} ${PREFIX}/share/doc/ortep3/man
	${MKDIR} ${PREFIX}/share/doc/ortep3/src

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/src/ortep3 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/* \
	      ${PREFIX}/share/doc/ortep3/examples
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/man/* \
	      ${PREFIX}/share/doc/ortep3/man
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/src/000readme.txt \
	      ${PREFIX}/share/doc/ortep3/src
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README.1st \
	      ${PREFIX}/share/doc/ortep3

.include <bsd.port.post.mk>
