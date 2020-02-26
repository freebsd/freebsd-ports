# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	epsilon
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Epsilon-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of Python utility modules used by DivMod projects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0.13:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=13.2.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# bin/benchmark
CONFLICTS_INSTALL=	brlcad

.include <bsd.port.mk>
