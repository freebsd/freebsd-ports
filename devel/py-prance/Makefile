# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	prance
PORTVERSION=	0.18.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Resolving Swagger/OpenAPI 2.0 and 3.0.0 parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=3.0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=2.9:devel/py-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.14:devel/py-six@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	CLI ICU
OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	FLEX OSV SSV
OPTIONS_DEFAULT=OSV
CLI_DESC=	Command-line interface support
FLEX_DESC=	Use py-flex as backend
ICU_DESC=	Unicode support
OSV_DESC=	Use py-openapi-spec-validator as backend
SSV_DESC=	Use py-swagger-spec-validator as backend

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7.0<8:devel/py-click@${PY_FLAVOR}
FLEX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flex>=6.13<7:devel/py-flex@${PY_FLAVOR}
ICU_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyicu>=2.4<3:devel/py-pyicu@${PY_FLAVOR}
OSV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openapi-spec-validator>=0.2.1<0.3:devel/py-openapi-spec-validator@${PY_FLAVOR}
SSV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}swagger-spec-validator>=2.4<3:devel/py-swagger-spec-validator@${PY_FLAVOR}

.include <bsd.port.mk>
