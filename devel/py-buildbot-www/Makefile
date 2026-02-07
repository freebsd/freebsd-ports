PORTNAME=	buildbot-www
DISTVERSION=	4.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	buildbot_www-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Buildbot UI
WWW=		https://buildbot.net

LICENSE=	GPLv2
#LICENSE_FILE=	Not packaged in sdist

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}buildbot-pkg>=${PORTVERSION}:devel/py-buildbot-pkg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}buildbot-console-view>=${PORTVERSION}:devel/py-buildbot-console-view@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}buildbot-grid-view>=${PORTVERSION}:devel/py-buildbot-grid-view@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}buildbot-waterfall-view>=${PORTVERSION}:devel/py-buildbot-waterfall-view@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}buildbot-wsgi-dashboards>=${PORTVERSION}:devel/py-buildbot-wsgi-dashboards@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>=16.0.0:security/py-service-identity@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
