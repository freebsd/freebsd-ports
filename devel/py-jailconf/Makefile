# Created by: s.adaszewski@gmail.com
# $FreeBSD$

PORTNAME=	jailconf
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	s.adaszewski@gmail.com
COMMENT=	Parse and edit your FreeBSD jail.conf with python

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	leforestier
NO_ARCH=	yes

.include <bsd.port.mk>
