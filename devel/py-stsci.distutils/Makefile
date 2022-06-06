# Created by: William Grzybowski <wg@FreeBSD.org>

PORTNAME=	stsci.distutils
PORTVERSION=	0.3.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Packaging utilities used by some of STScI's packages

LICENSE=	BSD3CLAUSE

DEPRECATED=	Upstream abandoned in 2013
EXPIRATION_DATE=	2022-06-30
BROKEN=	requires python setuptools<58.0.0

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}d2to1>0:devel/py-d2to1@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
