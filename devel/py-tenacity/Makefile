PORTNAME=	tenacity
PORTVERSION=	9.2.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Retry code until it succeeds
WWW=		https://tenacity.readthedocs.io/en/latest/ \
		https://github.com/jd/tenacity

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${PORTVERSION}
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jd

.include <bsd.port.mk>
