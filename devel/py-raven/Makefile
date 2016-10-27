# $FreeBSD$

PORTNAME=	raven
PORTVERSION=	5.31.0
CATEGORIES=	devel python
#MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Client for Sentry

LICENSE=	BSD2CLAUSE

USES=		python
# either CHEESESHOP or github, whatever is newer
USE_GITHUB=	yes
GH_ACCOUNT=	getsentry
GH_PROJECT=	raven-python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}contextlib2>0:devel/py-contextlib2
.endif

.include <bsd.port.post.mk>
