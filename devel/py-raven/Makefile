# $FreeBSD$

PORTNAME=	raven
PORTVERSION=	6.10.0
PORTREVISION=	1
CATEGORIES=	devel python
#MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Client for Sentry

LICENSE=	BSD2CLAUSE

USES=		python:3.6+
# either CHEESESHOP or github, whatever is newer
USE_GITHUB=	yes
GH_ACCOUNT=	getsentry
GH_PROJECT=	raven-python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
