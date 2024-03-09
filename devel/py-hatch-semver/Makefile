PORTNAME=	hatch-semver
PORTVERSION=	2.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/fleetingbytes/hatch-semver/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hatch_semver-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hatch plugin for semver versioning scheme
WWW=		https://github.com/Nagidal/hatch-semver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=0:devel/py-semver@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
