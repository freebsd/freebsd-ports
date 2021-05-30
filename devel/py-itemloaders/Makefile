PORTNAME=	itemloaders
DISTVERSION=	1.0.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Base library in Python for scrapy's ItemLoader

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}w3lib>=1.17.0:www/py-w3lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsel>=1.5.0:textproc/py-parsel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0.9.5:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itemadapter>=0.1.0:devel/py-itemadapter@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
