# $FreeBSD$

PORTNAME=	pytest-tornado
PORTVERSION=	0.4.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Py.test plugin providing fixtures and markers for tornado

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
