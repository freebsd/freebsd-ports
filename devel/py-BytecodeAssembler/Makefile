# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	BytecodeAssembler
PORTVERSION=	0.6.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate Python code objects by "assembling" bytecode

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-12-12

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}DecoratorTools>=1.7:devel/py-decoratortools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SymbolType>0:devel/py-SymbolType@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
