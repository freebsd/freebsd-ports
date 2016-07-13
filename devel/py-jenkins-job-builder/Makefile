# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jenkins-job-builder
PORTVERSION=	1.6.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Manage Jenkins jobs with YAML

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PKGNAMEPREFIX}pbr>0:devel/py-pbr
RUN_DEPENDS=	${PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PKGNAMEPREFIX}pbr>0:devel/py-pbr \
		${PKGNAMEPREFIX}six>0:devel/py-six \
		${PKGNAMEPREFIX}stevedore>0:devel/py-stevedore \
		${PKGNAMEPREFIX}python-jenkins>0:devel/py-python-jenkins

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
