PORTNAME=	buildbot-wsgi-dashboards
DISTVERSION=	4.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	buildbot_wsgi_dashboards-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Buildbot plugin to integrate flask or bottle dashboards to buildbot UI (React)
WWW=		https://buildbot.net

LICENSE=	GPLv2
#LICENSE_FILE=	Not packaged in sdist

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}buildbot-pkg>=${PORTVERSION}:devel/py-buildbot-pkg@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}buildbot-pkg>=${PORTVERSION}:devel/py-buildbot-pkg@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
