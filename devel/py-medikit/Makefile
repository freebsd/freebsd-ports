# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	medikit
PORTVERSION=	0.5.19
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automated release engineer assistant

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.9:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}git_semver>=0.2.1:devel/py-git_semver@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mondrian>=0.6.6:devel/py-mondrian@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=17.0:devel/py-packaging@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-tools>=1.11:devel/py-pip-tools@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.28:devel/py-stevedore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whistle>=1.0:devel/py-whistle@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yapf>=0.20:textproc/py-yapf@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python:3.5+

.include <bsd.port.mk>
