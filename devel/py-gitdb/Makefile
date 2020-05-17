# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitdb
PORTVERSION=	4.0.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Git Object Database

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}smmap>=3.0.1<4:devel/py-smmap@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}gitdb2

.include <bsd.port.mk>
