# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	devel python
DISTNAME=	${PORTNAME}-${PORTVERSION}

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtGui.so:x11-toolkits/py-qt${PYQTVER}-gui@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/Qsci.so:devel/py-qt${PYQTVER}-qscintilla2@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtNetwork.so:net/py-qt${PYQTVER}-network@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtSvg.so:graphics/py-qt${PYQTVER}-svg@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtSql.so:databases/py-qt${PYQTVER}-sql@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtWebKit.so:www/py-qt${PYQTVER}-webkit@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtHelp.so:devel/py-qt${PYQTVER}-help@${PY_FLAVOR} \
		${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3@${PY_FLAVOR}

USES=		desktop-file-utils
INSTALL_CMD=	install.py -c -f eric6config.freebsd -i ${STAGEDIR} --pyqt=${PYQTVER}
PLIST_FILES=
SUB_FILES=	eric6.desktop
OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_DEFAULT=PYQT4
OPTIONS_SINGLE=	PYQT
OPTIONS_SINGLE_PYQT=	PYQT4 PYQT5
PYQT_DESC=	PyQt Version
PYQT4_DESC=	Python bindings for Qt4
PYQT4_VARS=	PYQTVER=4
PYQT5_DESC=	Python bindings for Qt5
PYQT5_VARS=	PYQTVER=5
PYQT5_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt5/QtWebKitWidgets.so:www/py-qt5-webkitwidgets@${PY_FLAVOR}
EXTRA_PATCHES=
MASTERPORT=

PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	${RM} ${WRKSRC}/eric/i18n/*.qm ${WRKSRC}/eric/i18n/*.ts

do-configure:
	${SED}  -e 's,PYTHON_SITELIBDIR,${PYTHON_SITELIBDIR},' \
		-e 's,PREFIX,${PREFIX},' \
		-e 's,DATADIR,${DATADIR},' \
		-e 's,LOCALBASE,${LOCALBASE},' \
		-e 's,DOCSDIR,${DOCSDIR},' \
		-e 's,EXAMPLESDIR,${EXAMPLESDIR},' \
		< ${FILESDIR}/config > ${WRKSRC}/eric6config.freebsd

post-install:
	${INSTALL_DATA} ${WRKDIR}/eric6.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${LN} -sf ${DATADIR:C|${PREFIX}(/share(/pixmaps)?)?||:C|/[^/]+|../|g}eric6/icons/default/eric.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/eric6.png
	@${MKDIR} ${STAGEDIR}${DATADIR}/i18n

.include "${.CURDIR}/../../devel/eric6/Makefile.inc"
