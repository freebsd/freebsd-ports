# Created by: Michael Gmelin <grembo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buildbot-www
PORTVERSION=	1.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Buildbot UI

LICENSE=	GPLv2
#LICENSE_FILE=	Not packaged in sdist

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}buildbot>=${PORTVERSION}:devel/py-buildbot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}buildbot-pkg>=${PORTVERSION}:devel/py-buildbot-pkg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0.8.0:devel/py-mock@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}buildbot-console-view>=${PORTVERSION}:devel/py-buildbot-console-view@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}buildbot-grid-view>=${PORTVERSION}:devel/py-buildbot-grid-view@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}buildbot-waterfall-view>=${PORTVERSION}:devel/py-buildbot-waterfall-view@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=16.0.0:security/py-service_identity@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
