# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	apptools
PORTVERSION=	4.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Enthought application tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
# See ${WRKSRC}/image_LICENSE.txt for information that other
# files *LICENSE* are not used

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traitsui>=0:graphics/py-traitsui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
# The requirements are defined in apptools/__init__.py

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
