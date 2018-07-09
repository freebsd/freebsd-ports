# $FreeBSD$

PORTNAME=	buildbot-grid-view
PORTVERSION=	0.9.15
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Continuous Integration Framework (Grid View)

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}buildbot-pkg>=${PORTVERSION}:devel/py-buildbot-pkg@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}buildbot-pkg>=${PORTVERSION}:devel/py-buildbot-pkg@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
