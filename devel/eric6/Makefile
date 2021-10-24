# Created by: Boris Samorodov <bsam@FreeBSD.org>

.include "${.CURDIR}/../../devel/eric6/bsd.eric6.mk"

PKGNAMESUFFIX=	-qt5-${FLAVOR:U:S/_/-/}
DISTNAME=	${PORTNAME}-nolang-${DISTVERSION}
PORTREVISION=	0
CATEGORIES=	devel python

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=15.2:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.14:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}editorconfig>=0.12.0:editors/py-editorconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>=1.5:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asttokens>=1.1:devel/py-asttokens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.3.1:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=0:textproc/py-enchant@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=15.2:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.14:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}editorconfig>=0.12.0:editors/py-editorconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>=1.5:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asttokens>=1.1:devel/py-asttokens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.3.1:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=0:textproc/py-enchant@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

CONFLICTS_INSTALL=	${FLAVORS:N${FLAVOR}:C/^/${PORTNAME}-qt5-/}

USES+=		desktop-file-utils python:3.5+ pyqt:5 shebangfix
USE_PYTHON=	flavors
USE_PYQT=	qscintilla2 webengine \
		pyqt5
INSTALL_PY=	install.py -c -f eric6config.freebsd -i ${STAGEDIR}
SHEBANG_FILES=	*.py eric/eric6/*.py eric/scripts/*.py
SUB_FILES=	eric6.desktop
MASTERPORT=	yes

PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

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
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_PY})

post-install:
	${INSTALL_DATA} ${WRKDIR}/eric6.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${LN} -sf ${DATADIR:C|${PREFIX}(/share(/pixmaps)?)?||:C|/[^/]+|../|g}eric6/icons/default/eric.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/eric6.png
	@${MKDIR} ${STAGEDIR}${DATADIR}/i18n
	${REINPLACE_CMD} -e 's|${STAGEDIR}|${DATADIR}|g' \
			 -e 's|${WRKSRC}|${DATADIR}|g' \
			${STAGEDIR}/${DATADIR}/eric6install.json
	@${RM}	${STAGEDIR}/${DATADIR}/eric6install.json.bak

.include <bsd.port.mk>
