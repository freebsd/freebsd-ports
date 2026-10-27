PORTNAME=	ruff
DISTVERSION=	0.17.3
CATEGORIES=	devel python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extremely fast Python linter and code formatter
WWW=		https://astral.sh/ \
		https://docs.astral.sh/ruff/ \
		https://github.com/astral-sh/ruff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	ruff:devel/ruff

USES=		python
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	astral-sh

NO_ARCH=	yes

# suggested to the upstream to add an ability to use the external ruff
# executable, see https://github.com/astral-sh/ruff/issues/11932
# however, the above issue was closed with some support for this suggestion after closure

.include <bsd.port.mk>
