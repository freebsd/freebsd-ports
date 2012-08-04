# New ports collection makefile for:	pymol
# Date created:			July 18, 2002
# Whom:				Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$

PORTNAME=	pymol
PORTVERSION=	${VERSION}.${SVNREVISION}
PORTREVISION=	2
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|maho/pymol|}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Free and Open-Source molecular modeling system

BUILD_DEPENDS=	${PYNUMERIC}
RUN_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

VERSION=	1.5.0.1
SVNREVISION=	3978

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/pymol-${PORTVERSION}
USE_GL=		glut glew
USE_GMAKE=	yes
USE_PYTHON=	yes
PLIST_SUB=	PYMOL_VER=${VERSION} PYTHON_VER=${PYTHON_VER}

pre-build:
	@${REINPLACE_CMD} -e "s+%%LOCALBASE%%+${LOCALBASE}+"  ${WRKSRC}/setup.py

#do build process actually installs some files, so omitted.
do-build:

do-install:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} install)
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup2.py install)
	@${INSTALL_SCRIPT} ${WRKSRC}/pymol ${PREFIX}/bin/pymol

#maintainance
do-fetch-svn:
	#svn ls https://pymol.svn.sourceforge.net/svnroot/pymol/tags
	#http://pymol.svn.sourceforge.net/viewvc/pymol/trunk/
	${RM} -rf pymol-${VERSION}.${SVNREVISION}
	svn -r ${SVNREVISION} export http://pymol.svn.sourceforge.net/svnroot/pymol/trunk/pymol pymol-${VERSION}.${SVNREVISION}
	tar cvfj pymol-${VERSION}.${SVNREVISION}.tar.bz2 pymol-${VERSION}.${SVNREVISION}
	scp pymol-${VERSION}.${SVNREVISION}.tar.bz2 freefall.freebsd.org:public_distfiles/pymol/

.include <bsd.port.mk>
