# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	robotframework-selenium2library
PORTVERSION=	1.1.0
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/r/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.ru
COMMENT=	Selenium2Library is a web testing library for Robot Framework

LICENSE=	AL2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0.6c11:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=2.7.5:${PORTSDIR}/devel/py-robotframework \
	${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:${PORTSDIR}/devel/py-decorator

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
.include <bsd.port.mk>
