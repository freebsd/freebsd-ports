PORTNAME=	pytest-tornasync
DISTVERSION=	0.6.0.post2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTest plugin for testing Python 3.5+ Tornado code
WWW=		https://github.com/eukaryote/pytest-tornasync

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=5.0:www/py-tornado@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail, see https://github.com/eukaryote/pytest-tornasync/issues/15

NO_ARCH=	yes

.include <bsd.port.mk>
