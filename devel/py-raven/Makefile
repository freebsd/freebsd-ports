# $FreeBSD$

PORTNAME=	raven
PORTVERSION=	5.13.0
CATEGORIES=	devel python
#MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Client for Sentry

LICENSE=	BSD2CLAUSE

USES=		python:3
# either CHEESESHOP or github, whatever is newer
USE_GITHUB=	yes
GH_ACCOUNT=	getsentry
GH_PROJECT=	raven-python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
