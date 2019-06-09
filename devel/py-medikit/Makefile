# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	medikit
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automated release engineer assistant

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.9<3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}git_semver>=0.2.3<0.3:devel/py-git_semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mondrian>=0.7<1:devel/py-mondrian@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=19.0<20:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-tools2>=2.0.2<2.1:devel/py-pip-tools2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.28<2:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whistle>=1.0<2:devel/py-whistle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yapf>=0.20<1:textproc/py-yapf@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
