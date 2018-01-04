# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rb
PORTVERSION=	1.6
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Rb - the redis blaster

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=2.6:databases/py-redis@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	getsentry
GH_PROJECT=	rb

.include <bsd.port.mk>
