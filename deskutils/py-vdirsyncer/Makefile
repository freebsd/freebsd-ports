PORTNAME=	vdirsyncer
DISTVERSION=	0.19.1
CATEGORIES=	deskutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Synchronize calendars and contacts
WWW=		https://vdirsyncer.readthedocs.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.10.1:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiostream>=0.4.5:www/py-aiostream@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}atomicwrites>=0.1.7:devel/py-atomicwrites@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=5.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-log<0.4.0:devel/py-click-log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-threading>=0.2:devel/py-click-threading@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.4.0:www/py-requests-toolbelt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	GOOGLE

GOOGLE_DESC=	Enable Google Calendar support
GOOGLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp-oauthlib>=0:www/py-aiohttp-oauthlib@${PY_FLAVOR}

.include <bsd.port.mk>
