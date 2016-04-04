# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	robotframework-selenium2library
PORTVERSION=	1.7.4
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Web testing library for Robot Framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=2.7.5:devel/py-robotframework \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:devel/py-decorator

USES=		python:2
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
