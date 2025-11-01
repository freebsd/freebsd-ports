PORTNAME=	ipython
PORTVERSION=	8.18.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Enhanced Interactive Python shell
WWW=		https://ipython.org/ \
		https://ipython.readthedocs.io/en/stable/ \
		https://github.com/ipython/ipython

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=51.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>=0:devel/py-decorator@${PY_FLAVOR} \
		${PY_EXCEPTIONGROUP} \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.16:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>=4.3:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.41<3.1.0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.4.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stack-data>0:devel/py-stack-data@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=5:devel/py-traitlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib-inline>0:math/py-matplotlib-inline@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	py*-ipython5

NO_ARCH=	yes

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-install-EXAMPLES-on:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
