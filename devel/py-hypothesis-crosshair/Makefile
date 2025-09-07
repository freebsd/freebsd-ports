PORTNAME=	hypothesis-crosshair
PORTVERSION=	0.0.25
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hypothesis_crosshair-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Level-up your Hypothesis tests with CrossHair
WWW=		https://github.com/pschanely/hypothesis-crosshair

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}crosshair-tool>=0.0.74:devel/py-crosshair-tool@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
