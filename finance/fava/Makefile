PORTNAME=	fava
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	PYPI

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Web interface for Beancount
WWW=		https://beancount.github.io/fava/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babel>=2.7:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.4:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.28:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babel>=2.11:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>=8:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-babel>=4:devel/py-flask-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=3.1:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown-it-py>=3:textproc/py-markdown-it-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgspec>=0.19:devel/py-msgspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchfiles>=0.20.0:devel/py-watchfiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=3.1:www/py-werkzeug@${PY_FLAVOR} \
		beancount>=3.2.0:finance/beancount \
		beangulp>=0.2:finance/beangulp \
		beanquery>=0.1:finance/beanquery

USES=		python # same as finance/beancount
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

.include <bsd.port.mk>
