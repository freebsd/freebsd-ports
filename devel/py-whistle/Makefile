PORTNAME=	whistle
PORTVERSION=	2.1.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/python-whistle/whistle/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Event dispatcher
WWW=		https://python-whistle.github.io/ \
		https://github.com/python-whistle/whistle

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
