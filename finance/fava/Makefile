# $FreeBSD$

PORTNAME=	fava
PORTVERSION=	1.10
PORTREVISION=	0
CATEGORIES=	finance
MASTER_SITES=	CHEESESHOP

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Web interface for Beancount

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	beancount>=2.1.2:finance/beancount \
		${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>0:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Babel>0:devel/py-flask-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown2>0:textproc/py-markdown2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.5+  # same as finance/beancount
USE_PYTHON=	autoplist distutils noflavors

.include <bsd.port.mk>
