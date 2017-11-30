# Created by: Michael Gmelin <grembo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buildbot-www
PORTVERSION=	0.9.11
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Continuous Integration Framework (WWW)

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}buildbot>=${PORTVERSION}:devel/py-buildbot@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}buildbot-pkg>=${PORTVERSION}:devel/py-buildbot-pkg@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0.8.0:devel/py-mock@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}buildbot-console-view>=${PORTVERSION}:devel/py-buildbot-console-view@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}buildbot-grid-view>=${PORTVERSION}:devel/py-buildbot-grid-view@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}buildbot-waterfall-view>=${PORTVERSION}:devel/py-buildbot-waterfall-view@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=16.0.0:security/py-service_identity@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
