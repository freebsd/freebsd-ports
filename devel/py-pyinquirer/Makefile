# Created by: Gilbert Morgan <gmm@tutanota.com>
# $FreeBSD$

PORTNAME=	PyInquirer
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Collection of common interactive command line user interfaces

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prompt_toolkit>0:devel/py-prompt_toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}

USES=		localbase python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
