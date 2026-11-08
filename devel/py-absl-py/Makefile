PORTNAME=	absl-py
PORTVERSION=	2.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	absl_py-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Abseil Python Common Libraries
WWW=		https://abseil.io/docs/python/ \
		https://github.com/abseil/abseil-py

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.26:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
