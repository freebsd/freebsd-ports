PORTNAME=	vdirsyncer
PORTVERSION=	0.20.0
CATEGORIES=	deskutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Synchronize calendars and contacts
WWW=		https://vdirsyncer.pimutils.org/en/stable/ \
		https://github.com/pimutils/vdirsyncer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.0<4.0.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiostream>=0.4.3<0.8.0:www/py-aiostream@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=5.0<9.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-log>=0.3.0<0.5.0:devel/py-click-log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	GOOGLE
GOOGLE_DESC=	Google Calendar support

GOOGLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp-oauthlib>=0:www/py-aiohttp-oauthlib@${PY_FLAVOR}

.include <bsd.port.mk>
