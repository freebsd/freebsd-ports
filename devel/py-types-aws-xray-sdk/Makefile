PORTNAME=	types-aws-xray-sdk
PORTVERSION=	2.15.0.20251206
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	types_aws_xray_sdk-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Typing stubs for aws-xray-sdk
WWW=		https://github.com/python/typeshed

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
