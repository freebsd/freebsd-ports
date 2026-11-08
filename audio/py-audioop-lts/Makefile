PORTNAME=	audioop-lts
PORTVERSION=	0.2.2
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	audioop_lts-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LTS Port of Python audioop
WWW=		https://github.com/AbstractUmbra/audioop

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.13+
USE_PYTHON=	autoplist concurrent pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
