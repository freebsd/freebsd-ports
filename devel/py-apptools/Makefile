# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	apptools
PORTVERSION=	4.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Enthought application tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
# See ${WRKSRC}/image_LICENSE.txt for information that other
# files *LICENSE* are not used

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traits>=4.5.0:devel/py-traits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.:devel/py-configobj@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
