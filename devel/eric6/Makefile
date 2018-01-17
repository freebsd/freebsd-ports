# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-${FLAVOR:U:S/_/-/}
CATEGORIES=	devel python
DISTNAME=	${PORTNAME}-nolang-${DISTVERSION}

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtGui.so:x11-toolkits/py-qt${PYQTVER}-gui@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/Qsci.so:devel/py-qt${PYQTVER}-qscintilla2@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtNetwork.so:net/py-qt${PYQTVER}-network@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtSvg.so:graphics/py-qt${PYQTVER}-svg@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtSql.so:databases/py-qt${PYQTVER}-sql@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtWebKit.so:www/py-qt${PYQTVER}-webkit@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt${PYQTVER}/QtHelp.so:devel/py-qt${PYQTVER}-help@${PY_FLAVOR} \
		${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3@${PY_FLAVOR}

CONFLICTS_INSTALL=	${FLAVORS:N${FLAVOR}:C/^/${PKGNAMEPREFIX}${PORTNAME}-/:C/$/-[0-9]*/}

USES=		desktop-file-utils python:${FLAVOR:C/.*_py([0-9])/\1./}
INSTALL_CMD=	install.py -c -f eric6config.freebsd -i ${STAGEDIR} --pyqt=${PYQTVER}
SUB_FILES=	eric6.desktop
PYQTVER=	${FLAVOR:C/qt([45])_py[0-9]+/\1/}
MASTERPORT=	yes

PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

.include "${.CURDIR}/bsd.eric6.mk"
.include <bsd.port.options.mk>

PY_FLAVORS=	py${PYTHON_DEFAULT:S/.//} py${PYTHON2_DEFAULT:S/.//} py${PYTHON3_DEFAULT:S/.//}
.for flavor in ${PY_FLAVORS}
.  if empty(FLAVORS:Mqt4_${flavor})
FLAVORS:=	${FLAVORS} qt4_${flavor} qt5_${flavor}
.  endif
.endfor
.if empty(FLAVOR)
FLAVOR=		${FLAVORS:[1]}
.endif

.if ${PYQTVER} == 5
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt5/QtWebKitWidgets.so:www/py-qt5-webkitwidgets@${PY_FLAVOR}
.endif

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

do-install:
	@(cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_CMD})

post-install:
	${INSTALL_DATA} ${WRKDIR}/eric6.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${LN} -sf ${DATADIR:C|${PREFIX}(/share(/pixmaps)?)?||:C|/[^/]+|../|g}eric6/icons/default/eric.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/eric6.png
	@${MKDIR} ${STAGEDIR}${DATADIR}/i18n

.include <bsd.port.mk>
