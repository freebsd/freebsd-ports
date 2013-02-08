# New ports collection makefile for:	leo
# Date created:			2002/11/17
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	leo
PORTVERSION=	4.10
PORTREVISION=	4
CATEGORIES=	editors python
MASTER_SITES=	SF/${PORTNAME}/Leo/${PORTVERSION}%20final
DISTNAME=	Leo-${PORTVERSION}-final
DIST_SUBDIR=	leo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced outline editor for programmers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=0:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:${PORTSDIR}/textproc/py-docutils \
		silvercity>=0:${PORTSDIR}/textproc/silvercity \
		${PYTHON_PKGNAMEPREFIX}Pmw>=0:${PORTSDIR}/x11-toolkits/py-Pmw \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui

OPTIONS_DEFINE=	PYENCHANT DOCS
PYENCHANT_DESC=	Enable PyEnchant support

WRKSRC=		${WRKDIR}/Leo-${PORTVERSION}-final

USE_ZIP=	yes
USE_PYTHON=	2.6+

LEO_DIR=	${PYTHONPREFIX_SITELIBDIR}/leo

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYENCHANT}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enchant>=0:${PORTSDIR}/textproc/py-enchant
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
	${INSTALL_DATA} ${WRKSRC}/leo/Icons/*.svg ${LEO_DIR}/Icons
	@(cd ${WRKSRC}/leo/Icons && ${COPYTREE_SHARE} cleo ${LEO_DIR}/Icons)
.for dir in config core external extensions modes plugins scripts test www
	@(cd ${WRKSRC}/leo; ${COPYTREE_SHARE} ${dir} ${LEO_DIR})
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/leo; ${COPYTREE_SHARE} doc ${LEO_DIR})
.endif

.include <bsd.port.mk>
