PORTNAME=	inflect
PORTVERSION=	6.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate plurals, singular nouns, ordinals, indefinite articles
WWW=		https://github.com/jaraco/inflect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4.1:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic>=1.9.1:devel/py-pydantic@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
