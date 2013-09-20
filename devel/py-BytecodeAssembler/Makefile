# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	BytecodeAssembler
PORTVERSION=	0.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate Python code objects by "assembling" bytecode

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}DecoratorTools>=1.7:${PORTSDIR}/devel/py-decoratortools \
		${PYTHON_PKGNAMEPREFIX}SymbolType>0:${PORTSDIR}/devel/py-SymbolType
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
