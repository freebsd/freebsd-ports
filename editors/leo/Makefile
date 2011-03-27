# New ports collection makefile for:	leo
# Date created:			2002/11/17
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	leo
PORTVERSION=	4.8
CATEGORIES=	editors python
MASTER_SITES=	SF/${PORTNAME}/Leo/${PORTVERSION}%20final
DISTNAME=	Leo-${PORTVERSION}-final
DIST_SUBDIR=	leo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced outline editor for programmers

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/Gato/__init__.py:${PORTSDIR}/math/py-gato \
		${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_SITELIBDIR}/SilverCity/__init__.py:${PORTSDIR}/textproc/silvercity \
		${PYTHON_SITELIBDIR}/Pmw/__init__.py:${PORTSDIR}/x11-toolkits/py-Pmw \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

OPTIONS=	PYQT4 "Qt4 look and feel" off

USE_ZIP=	yes
USE_PYTHON=	2.6+

LEO_DIR=	${PYTHONPREFIX_SITELIBDIR}/leo

.include <bsd.port.pre.mk>

.if defined(WITH_PYQT4)
RUN_DEPENDS+=	py*-qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui
.endif

post-extract:
	@-${FIND} ${WRKSRC}/leo -type d -empty -delete

do-build:
	${SED} -e 's|@PKGDATADIR@/leo.py|${LEO_DIR}/core/runLeo.py|' \
		${FILESDIR}/leo.in > ${WRKDIR}/leo

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/leo ${PREFIX}/bin/leo
	@${MKDIR} ${LEO_DIR}
	${INSTALL_DATA} ${WRKSRC}/leo/__init__.py ${LEO_DIR}
	@${MKDIR} ${LEO_DIR}/Icons
	${INSTALL_DATA} ${WRKSRC}/leo/Icons/*.GIF ${LEO_DIR}/Icons
	${INSTALL_DATA} ${WRKSRC}/leo/Icons/*.gif ${LEO_DIR}/Icons
	${INSTALL_DATA} ${WRKSRC}/leo/Icons/*.png ${LEO_DIR}/Icons
	@${MKDIR} ${LEO_DIR}/extensions
	${INSTALL_DATA} ${WRKSRC}/leo/extensions/*.py ${LEO_DIR}/extensions
.for dir in config core external modes plugins scripts test www
	@(cd ${WRKSRC}/leo; ${COPYTREE_SHARE} ${dir} ${LEO_DIR})
.endfor
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/leo; ${COPYTREE_SHARE} doc ${LEO_DIR})
.endif

.include <bsd.port.post.mk>
