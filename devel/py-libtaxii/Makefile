# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtaxii
PORTVERSION=	1.1.110
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Python library for handling TAXII Messages and invoking TAXII Services

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.2.3:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.4.1:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python

.include <bsd.port.mk>
