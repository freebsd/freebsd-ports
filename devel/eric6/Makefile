# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	3
PKGNAMESUFFIX=	-${FLAVOR:U:S/_/-/}
DISTNAME=	${PORTNAME}-nolang-${DISTVERSION}
CATEGORIES=	devel python

# Note to MAINTAINER: this should be converted to USES=pyqt, USE_PYQT=[...]
RUN_DEPENDS=	${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3@${PY_FLAVOR}

CONFLICTS_INSTALL=	${FLAVORS:N${FLAVOR}:C/^/${PKGNAMEPREFIX}${PORTNAME}-/:C/$/-[0-9]*/}

USES=		desktop-file-utils python:${FLAVOR:C/.*_py([0-9])/\1./} pyqt:5
USE_PYQT=	core gui qscintilla2 webengine \
		help_run network_run svg_run sql_run
INSTALL_CMD=	install.py -c -f eric6config.freebsd -i ${STAGEDIR} --pyqt=5
SUB_FILES=	eric6.desktop
MASTERPORT=	yes

PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include "${.CURDIR}/bsd.eric6.mk"
.include <bsd.port.options.mk>

PY_FLAVORS=	py${PYTHON_DEFAULT:S/.//} py${PYTHON2_DEFAULT:S/.//} py${PYTHON3_DEFAULT:S/.//}
.for flavor in ${PY_FLAVORS}
.  if empty(FLAVORS:Mqt5_${flavor})
FLAVORS:=	${FLAVORS} qt5_${flavor}
.  endif
.endfor
.if empty(FLAVOR)
FLAVOR=		${FLAVORS:[1]}
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
