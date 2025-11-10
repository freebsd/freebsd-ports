PORTNAME=	sortinghat
DISTVERSION=	1.6.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

# Ask clusteradm@ before removal
MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to manage identities
WWW=		https://github.com/chaoss/grimoirelab-sortinghat

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}click>=8.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-cors-headers>=3.7.0:www/py-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-graphql-jwt34>=0.3.0:www/py-django-graphql-jwt34@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-rq>=2.3.2:devel/py-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-storages>=1.13.2:www/py-django-storages@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-treebeard>=4.5.1:www/py-django-treebeard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.18.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphene-django>=2.15:devel/py-graphene-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoirelab-toolkit>=1.0.9:devel/py-grimoirelab-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>=5.2.0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mysqlclient>=2.0.3:databases/py-mysqlclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.4.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.9.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=1.12.0:devel/py-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sgqlc>=16.1:devel/py-sgqlc@${PY_FLAVOR} \
		uwsgi${PYTHON_PKGNAMESUFFIX}>0:www/uwsgi

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 unittest
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
