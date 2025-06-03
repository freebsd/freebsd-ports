PORTNAME=	eliot
DISTVERSION=	1.17.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Logging library that tells you why it happened
WWW=		https://pypi.org/project/${PORTNAME} \
		https://github.com/itamarst/${PORTNAME}

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boltons>=0:devel/py-boltons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=0:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyrsistent>=0:devel/py-pyrsistent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
