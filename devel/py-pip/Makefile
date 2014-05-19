# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pip
PORTVERSION=	1.5.6
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tool for installing and managing Python packages

LICENSE=	MIT

DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCS_MAKE_ENV=	HOME=${WRKDIR}

GH_ACCOUNT=	pypa
GH_COMMIT=	437fb31

OPTIONS_DEFINE=	DOCS

USES=		shebangfix
USE_GITHUB=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

# This port installs the following file in shared dirs
# PLIST_FILES= bin/pip

SHEBANG_FILES=	pip/__init__.py
python_OLD_CMD=	${SETENV} python
python_CMD=	${PYTHON_CMD}

.if 0
TEST_DEPENDS=	tox:${PORTSDIR}/devel/py-tox
TOX_CMD=	${LOCALBASE}/bin/tox
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx -n --all-files --fresh-env

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objects.inv")
.endif

.if 0
regression-test: build
	@cd ${WRKSRC} && \
	${TOX_CMD} -e py${PYTHON_SUFFIX},docs
.endif

.include <bsd.port.mk>
