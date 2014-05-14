# Created by: Dryice Liu	<dryice@dryice.name>
# $FreeBSD$

PORTNAME=	PyProtocols
PORTVERSION=	1.0.a0.r2302
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://files.turbogears.org/eggs/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-1.0a0dev-r2302

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Protocol Definition, Declaration, and Adaptation for Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}DecoratorTools>=1.7:${PORTSDIR}/devel/py-decoratortools

USES=		zip
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_PKGVERSION=	1.0a0dev-r2302

.include <bsd.port.mk>
