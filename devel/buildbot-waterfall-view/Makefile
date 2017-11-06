# Created by: Michael Gmelin <grembo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buildbot-waterfall-view
PORTVERSION=	0.9.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Continuous Integration Framework (Waterfall View)

LICENSE=	GPLv2

BUILD_DEPENDS=	buildbot-pkg>=${PORTVERSION}:devel/buildbot-pkg
RUN_DEPENDS=	buildbot-pkg>=${PORTVERSION}:devel/buildbot-pkg

USES=		python:2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
