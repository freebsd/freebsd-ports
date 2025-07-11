PORTNAME=	psygnal
PORTVERSION=	0.14.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast python callback/event system modeled after Qt Signals
WWW=		https://psygnal.readthedocs.io/en/latest/ \
		https://github.com/pyapp-kit/psygnal

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.8.0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PROXY PYDANTIC
PROXY_DESC=	Evented proxy support
PYDANTIC_DESC=	Evented model support

PROXY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wrapt>=0:devel/py-wrapt@${PY_FLAVOR}
PYDANTIC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic2>=0:devel/py-pydantic2@${PY_FLAVOR}

.include <bsd.port.mk>
