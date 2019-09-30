# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rb
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Redis blaster

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis2>=2.6:databases/py-redis2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
