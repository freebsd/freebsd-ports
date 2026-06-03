PORTNAME=	hatch-tryton
PORTVERSION=	0.1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hatch_tryton-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	hatchling plugin for Tryton
WWW=		https://www.tryton.org/ \
		https://foss.heptapod.net/tryton/hatch-tryton

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
