# $FreeBSD$

PORTNAME=	jenkins-job-builder
PORTVERSION=	2.0.9
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Manage Jenkins jobs with YAML

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>0:devel/py-stevedore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-jenkins>0:devel/py-python-jenkins@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>0:devel/py-fasteners@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
