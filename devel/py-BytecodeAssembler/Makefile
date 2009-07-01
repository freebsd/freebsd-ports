# New ports collection makefile for:	py-BytecodeAssembler
# Date created:		23 June, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	BytecodeAssembler
PORTVERSION=	0.5.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Generate Python code objects by "assembling" bytecode

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}DecoratorTools>=1.7:${PORTSDIR}/devel/py-decoratortools \
		${PYTHON_PKGNAMEPREFIX}SymbolType>0:${PORTSDIR}/devel/py-SymbolType
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
