PORTNAME=	blessed
DISTVERSION=	1.20.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Easy, practical library for making terminal apps
WWW=		https://github.com/jquast/blessed

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>=0.1.4:devel/py-wcwidth@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 4 tests fail, see https://github.com/jquast/blessed/issues/251

NO_ARCH=	yes

.include <bsd.port.mk>
