# New ports collection makefile for:	pymol
# Date created:			July 18, 2002
# Whom:				Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$

PORTNAME=	pymol
PORTVERSION=	1.0r2
PORTREVISION=	3
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|maho/pymol|}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Free and Open-Source molecular modeling system

BUILD_DEPENDS=	${PYNUMERIC}
RUN_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/pymol-${PORTVERSION}
USE_GL=		glut
USE_GMAKE=	yes
USE_PYTHON=	yes
PLIST_SUB=	PYTHON_VER=${PYTHON_VER}

pre-build:
	@${REINPLACE_CMD} -e "s+%%LOCALBASE%%+${LOCALBASE}+"  ${WRKSRC}/setup.py

do-build:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build

do-install:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} install \
	; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup2.py install)
	@${INSTALL_SCRIPT} ${WRKSRC}/pymol ${PREFIX}/bin/pymol

.include <bsd.port.mk>
