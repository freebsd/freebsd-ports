# Created by: Michael Gmelin <grembo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buildbot-www
PORTVERSION=	0.9.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Continuous Integration Framework (WWW)

LICENSE=	GPLv2

BUILD_DEPENDS=	buildbot>=${PORTVERSION}:devel/buildbot \
		buildbot-pkg>=${PORTVERSION}:devel/buildbot-pkg \
		${PYTHON_PKGNAMEPREFIX}mock>0.8.0:devel/py-mock
RUN_DEPENDS=	buildbot-console-view>=${PORTVERSION}:devel/buildbot-console-view \
		buildbot-grid-view>=${PORTVERSION}:devel/py-buildbot-grid-view \
		buildbot-waterfall-view>=${PORTVERSION}:devel/buildbot-waterfall-view \
		${PYTHON_PKGNAMEPREFIX}service_identity>=16.0.0:security/py-service_identity

USES=		python:2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
