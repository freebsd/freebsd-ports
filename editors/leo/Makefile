# Created by: Alan Eldridge <ports@geeksrus.net>
# $FreeBSD$

PORTNAME=	leo
PORTVERSION=	4.11
CATEGORIES=	editors python
MASTER_SITES=	SF/${PORTNAME}/Leo/${PORTVERSION}-final
DISTFILES=	Leo-${PORTVERSION}-final.zip
DIST_SUBDIR=	leo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced outline editor for programmers

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=0:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:${PORTSDIR}/textproc/py-docutils \
		silvercity>=0:${PORTSDIR}/textproc/silvercity \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui

OPTIONS_DEFINE=	PYENCHANT DOCS
PYENCHANT_DESC=	Enable PyEnchant support
PYENCHANT_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}enchant>=0:${PORTSDIR}/textproc/py-enchant

WRKSRC=		${WRKDIR}/Leo-${PORTVERSION}-final

USES=		shebangfix
SHEBANG_FILES=	leo/doc/html/fixup.pl leo/scripts/LinixInstall.py
USE_PYTHON=	yes

DESKTOP_ENTRIES="Leo" "Literate Editor with Outlines" \
		"${LEO_DIR}/Icons/leoapp32.png" "leo" "" ""

LEO_DIR=	${PYTHONPREFIX_SITELIBDIR}/leo

.include <bsd.port.options.mk>

post-extract:
	@-${FIND} ${WRKSRC}/leo -type d -empty -delete

post-patch:
	@${REINPLACE_CMD} -i '' -e \
		'1s|^\#![[:space:]].*|#!${PYTHON_CMD}|' \
		${WRKSRC}/leo/test/cgi-bin/edward.py

do-build:
	${SED} -e 's|@PKGDATADIR@/leo.py|${LEO_DIR}/core/runLeo.py|' \
		${FILESDIR}/leo.in > ${WRKDIR}/leo

do-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} leo ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${LEO_DIR}
	(cd ${WRKSRC}/leo && ${INSTALL_DATA} __init__.py ${STAGEDIR}${LEO_DIR})
	@${MKDIR} ${STAGEDIR}${LEO_DIR}/Icons
.for i in GIF gif png svg
	(cd ${WRKSRC}/leo/Icons && ${INSTALL_DATA} *.${i} \
		${STAGEDIR}${LEO_DIR}/Icons)
.endfor
.for i in cleo recorder
	(cd ${WRKSRC}/leo/Icons && ${COPYTREE_SHARE} ${i} \
		${STAGEDIR}${LEO_DIR}/Icons)
.endfor
.for i in config core doc external extensions modes plugins scripts test www
	(cd ${WRKSRC}/leo && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${LEO_DIR})
.endfor
	@-(cd ${STAGEDIR}/${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f ${LEO_DIR:S,${PREFIX}/,,})

.include <bsd.port.mk>
