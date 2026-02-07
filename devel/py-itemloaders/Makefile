PORTNAME=	itemloaders
DISTVERSION=	1.3.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Base library in Python for scrapy's ItemLoader
WWW=		https://pypi.org/project/itemloaders/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}w3lib>=1.17.0:www/py-w3lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsel>=1.5.0:textproc/py-parsel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0.9.5:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itemadapter>=0.1.0:devel/py-itemadapter@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
