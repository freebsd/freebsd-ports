# Created by: Piotr Florczyk <p.florczyk@adminworkshop.pl>
# $FreeBSD$

PORTNAME=	construct
PORTVERSION=	2.8.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	28

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	Python module for parsing and building of data structures

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Latest upstream version is in ports tree devel/py-construct
EXPIRATION_DATE=2019-03-20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
