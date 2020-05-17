# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	robotframework-ride
PORTVERSION=	1.7.3.1
PORTREVISION=	2
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Test data editor for Robot Framework

LICENSE=	APACHE20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=2.7.5:devel/py-robotframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}robotframework-seleniumlibrary>=1.1.0:devel/py-robotframework-seleniumlibrary@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}

USES=		dos2unix python:2.7 zip
# py36 needs WX 4.0.4 wich is not ported yet
USE_PYTHON=	autoplist distutils
USE_WX=		3.0+

DOS2UNIX_GLOB=	*.py PKG-INFO settings.cfg MANIFEST.in
NO_ARCH=	yes
WX_COMPS=	wx python

.include <bsd.port.mk>
