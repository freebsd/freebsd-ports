# New ports collection makefile for:	leo
# Date created:			2002/11/17
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	leo
PORTVERSION=	4.4.8
CATEGORIES=	editors python
MASTER_SITES=	SF/${PORTNAME}/Leo/${PORTVERSION}%20final
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}-final
DIST_SUBDIR=	leo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced outline editor for programmers

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/Gato/__init__.py:${PORTSDIR}/math/py-gato \
		${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_SITELIBDIR}/SilverCity/__init__.py:${PORTSDIR}/textproc/silvercity \
		${PYTHON_SITELIBDIR}/Pmw/__init__.py:${PORTSDIR}/x11-toolkits/py-Pmw \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_ZIP=	yes
USE_PYTHON=	yes

LEO_DIR=	${PYTHONPREFIX_SITELIBDIR}/leo

do-build:
	${SED} -e 's|@PKGDATADIR@|${LEO_DIR}/src|' ${FILESDIR}/leo.in \
		> ${WRKDIR}/leo

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/leo ${PREFIX}/bin/leo
	@${MKDIR} ${LEO_DIR}/Icons
	${INSTALL_DATA} ${WRKSRC}/leo/Icons/*.GIF ${LEO_DIR}/Icons
	${INSTALL_DATA} ${WRKSRC}/leo/Icons/*.gif ${LEO_DIR}/Icons
	@${MKDIR} ${LEO_DIR}/config
	${INSTALL_DATA} ${WRKSRC}/leo/config/*.leo ${LEO_DIR}/config
	@${MKDIR} ${LEO_DIR}/extensions
	${INSTALL_DATA} ${WRKSRC}/leo/extensions/*.py ${LEO_DIR}/extensions
	${INSTALL_DATA} ${WRKSRC}/leo/extensions/*.pyd ${LEO_DIR}/extensions
	@${MKDIR} ${LEO_DIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/leo/plugins/*.py ${LEO_DIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/leo/plugins/*.txt ${LEO_DIR}/plugins
	@${MKDIR} ${LEO_DIR}/plugins/examples
	${INSTALL_DATA} ${WRKSRC}/leo/plugins/examples/*.py ${LEO_DIR}/plugins/examples
	@${MKDIR} ${LEO_DIR}/src
	${INSTALL_DATA} ${WRKSRC}/leo/src/* ${LEO_DIR}/src
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/leo/doc/LICENSE.TXT ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/leo/doc/README.TXT ${DOCSDIR}
	@${MKDIR} ${LEO_DIR}/doc
	${INSTALL_DATA} ${WRKSRC}/leo/doc/LeoDocs.leo ${LEO_DIR}/doc
.endif

.include <bsd.port.mk>
