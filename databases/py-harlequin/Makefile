PORTNAME=	harlequin
DISTVERSION=	2.5.1
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	SQL IDE for your terminal
WWW=		https://harlequin.sh/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to run because requires devel/py-tree-sitter >= 0.25.2 (see PR 289772)

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.28.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.1.7_1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.3.3,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=4.5.1:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}questionary>=2.1.1:devel/py-questionary@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich-click>=1.8.5:devel/py-rich-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shandy-sqlfmt>=0.29.0:devel/py-shandy-sqlfmt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual-fastdatatable>=0.14.0:textproc/py-textual-fastdatatable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual-textarea>=0.17.2:textproc/py-textual-textarea@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual>=6.11.0:textproc/py-textual@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.13.3:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-sql>=0.3.11:devel/py-tree-sitter-sql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter>=0.25.2:devel/py-tree-sitter@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
