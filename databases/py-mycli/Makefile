# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mycli
PORTVERSION=	1.13.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI for MySQL Database with auto-completion and syntax highlighting

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cli-helpers>=0.2.3:devel/py-cli-helpers \
		${PYTHON_PKGNAMEPREFIX}click>=4.1:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.5:devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.0.0:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}prompt_toolkit>=1.0.10:devel/py-prompt_toolkit \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}pymysql>=0.6.7:databases/py-pymysql \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.2.2:databases/py-sqlparse

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		mysql python

.include <bsd.port.mk>
