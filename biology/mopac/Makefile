# New ports collection makefile for:  mopac
# Version required:  7
# Date created:  1997-04-23
# Whom:	 Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1999/04/01 08:06:43 taoka Exp $
#

DISTNAME=	mopac7
PKGNAME=	mopac-7.02
CATEGORIES=	biology
MASTER_SITES=	ftp://ccl.osc.edu/pub/chemistry/software/SOURCES/FORTRAN/mopac7_sources/
DISTFILES=	mopac7.tar.Z  mopac7-man.tar.Z

PATCH_SITES=	ftp://ccl.osc.edu/pub/chemistry/software/LINUX/mopac7/old-version-95.06.21/
PATCHFILES=	mopac7-linux.diff.Z
PATCH_DIST_STRIP=	-p1

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp

USE_GMAKE=	yes

post-patch:
	${CP}  ${WRKDIR}/${DISTNAME}/esp.rof  ${WRKDIR}/${DISTNAME}/esp.f

pre-install:
	${CP} ${FILESDIR}/rmopac  ${WRKDIR}/${DISTNAME}/rmopac
	${RM} -rf ${PREFIX}/share/doc/mopac
	${MKDIR} ${PREFIX}/share/doc/mopac

post-install:
	${INSTALL_DATA} ${FILESDIR}/h2o.dat  ${PREFIX}/share/doc/mopac/
	${INSTALL_DATA} ${WRKDIR}/mopac7-man/mopac.tex  ${PREFIX}/share/doc/mopac/
	${INSTALL_DATA} ${WRKDIR}/mopac7-man/mopac.dvi  ${PREFIX}/share/doc/mopac

.include <bsd.port.mk>
