# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	backports.weakref
DISTVERSION=	1.0
DISTVERSIONSUFFIX=	.post1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Backport of the weakref module from Python 3.4

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports>0:devel/py-backports@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

POST_PLIST=	trim-backports-namespace

post-install:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__init__.py*

trim-backports-namespace:
	@${REINPLACE_CMD} '/backports\/__init__.py*/d' ${TMPPLIST}

.include <bsd.port.mk>
