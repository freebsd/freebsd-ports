PORTNAME=	beangulp
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	PYPI

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Importers Framework for Beancount
WWW=		https://github.com/beancount/beangulp/tree/master/examples/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>4:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}magic>0:devel/py-magic@${PY_FLAVOR} \
		beancount>0:finance/beancount

USES=		python # same as finance/beancount
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

.include <bsd.port.mk>
