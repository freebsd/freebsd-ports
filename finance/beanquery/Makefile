PORTNAME=	beanquery
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	PYPI

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Customizable lightweight SQL query tool
WWW=		https://github.com/beancount/beanquery

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR} \
		TatSu>0:textproc/py-TatSu@${PY_FLAVOR} \
		beancount>0:finance/beancount

USES=		python
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

.include <bsd.port.mk>
