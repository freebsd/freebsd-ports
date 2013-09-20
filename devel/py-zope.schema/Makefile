# $FreeBSD$

PORTNAME=	zope.schema
PORTVERSION=	4.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Interface extension for defining data schemas

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6.0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:${PORTSDIR}/devel/py-zope.event

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
