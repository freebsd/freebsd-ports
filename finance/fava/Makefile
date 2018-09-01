# $FreeBSD$

PORTNAME=	fava
PORTVERSION=	1.8
DISTVERSIONPREFIX=	v
CATEGORIES=	finance
MASTER_SITES=	LOCAL/nivit/${PORTNAME}/:static
DISTFILES=	${PORTNAME}-static-gen-${PORTVERSION}.tar.gz:static

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Web interface for Beancount

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	beancount>=2.1.2:finance/beancount \
		${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>0:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Babel>0:devel/py-flask-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown2>0:textproc/py-markdown2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${PY_FLAVOR}

GH_ACCOUNT=	beancount

USES=		python:3.5+  # same as finance/beancount
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
