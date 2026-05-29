PORTNAME=	sortinghat
DISTVERSION=	1.14.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

# Ask clusteradm@ before removal of this port if it becomes unmaintained
MAINTAINER=	siva@FreeBSD.org
COMMENT=	Tool to manage identities
WWW=		https://github.com/chaoss/grimoirelab-sortinghat

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}click>=8.2.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django52>=5.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-graphql-jwt>=0.4.0:www/py-django-graphql-jwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphene-django>=3.2.3:devel/py-graphene-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sgqlc>=16.1:devel/py-sgqlc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mysqlclient>=2.2.7:databases/py-mysqlclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=2.5.0:devel/py-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-rq>=3.1:devel/py-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-cors-headers>=4.6.0:www/py-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.4.0:www/py-pyjwt@${PY_FLAVOR} \
		uwsgi${PYTHON_PKGNAMESUFFIX}>=2.0:www/uwsgi \
		${PYTHON_PKGNAMEPREFIX}django-treebeard>=4.5.1:www/py-django-treebeard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoirelab-toolkit>=0.3:devel/py-grimoirelab-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-storages>=1.13.2:www/py-django-storages@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.18.0:security/py-google-auth@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpretty>0:www/py-httpretty@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
